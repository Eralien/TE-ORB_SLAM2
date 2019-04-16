#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/rgbd/depth.hpp"

#include "boost/filesystem.hpp"

using namespace boost::filesystem;

void loadFolder(const path& path_to_folder, std::vector<path> & files);
void printFilesInFolder(std::ostream &os, std::vector<path> &files, const path & folder_name);
void combine_images(cv::Mat &img1, cv::Mat &img2, cv::Mat &combinedImg);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << std::endl
                  << "Usage: ./odo path_to_data" << std::endl;
        return 1;
    }

    std::ofstream outFile("output.txt");
    path rgb_folder(std::string(argv[1]) + "rgb");
    path depth_folder(std::string(argv[1]) + "depth");
        
    std::vector<path> rgb_files, depth_files;

    try
    {
        
        loadFolder(rgb_folder, rgb_files);
        loadFolder(depth_folder, depth_files);

    }
    catch (const filesystem_error &ex)
    {
        std::cerr << ex.what() << "\n";
    }

    std::sort(rgb_files.begin(), rgb_files.end());
    std::sort(depth_files.begin(), depth_files.end());
        
    // printFilesInFolder(outFile, rgb_files, rgb_folder);
    // printFilesInFolder(outFile, depth_files, depth_folder);
    std::string windowName = "RGBD";
    cv::namedWindow(windowName);

    int size = (rgb_files.size() < depth_files.size()) ? rgb_files.size() : depth_files.size();

    // Index 0 produces a wierd depth image for some reason
    for (uint i = 2; i < 5; ++i)
    {
        std::string rgb_file_src   = rgb_files[i-1].filename().string();
        std::string depth_file_src = depth_files[i-1].filename().string();
        std::string rgb_file_dst   = rgb_files[i].filename().string();
        std::string depth_file_dst = depth_files[i].filename().string();

        cv::Mat rgb_im_src = cv::imread("../../data/rgb/" + rgb_file_src);
        cv::Mat depth_im_src = cv::imread("../../data/depth/" + depth_file_src);
        cv::Mat rgb_im_dst = cv::imread("../../data/rgb/" + rgb_file_dst);
        cv::Mat depth_im_dst = cv::imread("../../data/depth/" + depth_file_dst);

        cv::Mat src_mask = cv::Mat::ones(rgb_im_src.size(), CV_8U);
        cv::Mat dst_mask = cv::Mat::ones(depth_im_src.size(), CV_8U);
        cv::OutputArray rt;
        cv::rgbd::Odometry::compute(
            rgb_im_src,
            depth_im_src,
            src_mask,
            rgb_im_dst,
            depth_im_dst,
            dst_mask,
            rt);

        //std::cout << "../../data/rgb/" + rgb_file << std::endl;
        //std::cout << "../../data/depth/" + depth_file << std::endl;

        cv::Mat combinedImg = cv::Mat();
        combine_images(rgb_im_src, depth_im_src, combinedImg);

        cv::imshow(windowName, combinedImg); // Show our image inside the created window.
        cv::waitKey(0);                // Wait for any keystroke in the window
    }

    cv::destroyWindow(windowName); //destroy the created window

    outFile.close();

    return 0;
}

void loadFolder(const path& path_to_folder, std::vector<path> & files)
{
    for (directory_entry &file : directory_iterator(path_to_folder))
    {
        files.push_back(file.path().filename());
    }
}

void printFilesInFolder(std::ostream &os, std::vector<path> &files, const path & folder_name)
{
    os << "Files in " << folder_name << "..." << std::endl;
    os << "Number of files: " << files.size() << std::endl;
    for (auto & file : files)
    {
        os << file.string() << std::endl;
    }
    os << "\n\n";
}

void combine_images(cv::Mat &img1, cv::Mat &img2, cv::Mat &combinedImg)
{
    int width = 2*img1.cols;
    int height = img1.rows;

    cv::Mat totalImg = cv::Mat(height, width, img1.type());
    cv::Rect subImageROI = cv::Rect(0, 0, img1.cols, img1.rows);

    // copy to subimage
    img1.copyTo(totalImg(subImageROI));

    subImageROI.x = img1.cols;
    img2.copyTo(totalImg(subImageROI));

    combinedImg = totalImg.clone();
}

