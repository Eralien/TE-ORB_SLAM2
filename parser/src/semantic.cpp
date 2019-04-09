#include <semantic.hpp>

void combine_images(cv::Mat &img1, cv::Mat &img2, cv::Mat &combinedImg);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Please enter the number of files to process when running!" << std::endl;
        std::cout << "Usage ./semantic <num>" << std::endl;
        return 0;
    }

    int numImages = atoi(argv[1]);

    std::ifstream imageList(IMAGE_LIST);
    if (!imageList.is_open())
    {
        std::cout << "Unable to read in list of images from " << IMAGE_LIST << std::endl;
        return 0;
    }

    std::ifstream yolotxt(YOLO_TXT);
    if (!yolotxt.is_open())
    {
        std::cout << "Unable to read in the yolo detections from " << YOLO_TXT << std::endl;
    }

    // Create a window
    std::string windowName = "TUM";
    cv::namedWindow(windowName);

    for (uint i = 0; i < numImages; ++i)
    {
        std::string imageName;
        getline(imageList, imageName);
        std::cout << "Processing image " << imageName << "...\n";

        // Read in image from rgb folder
        cv::Mat image = cv::imread(PREFIX + "data/rgb/" + imageName);
        std::cout << PREFIX + "rgb/" + imageName << std::endl;

        cv::Mat imGray;
        cv::cvtColor(image, imGray, cv::COLOR_BGR2GRAY);

        // Variables to store keypoints and descriptors
        std::vector<cv::KeyPoint> keypoints;
        cv::Mat descriptors;

        // Detect ORB features and compute descriptors
        cv::Ptr<cv::Feature2D> orb = cv::ORB::create(MAX_FEATURES);
        orb->detectAndCompute(imGray, cv::Mat(), keypoints, descriptors);

        // Read in semantic information from prediction file
        std::vector<cv::KeyPoint> validKPs;
        detections_t detections = parse::get_detections(yolotxt);
        cv::Mat semantics = cv::Mat::zeros(keypoints.size(), NUM_CLASSTYPES, CV_32FC1);
        get_semantic_info(keypoints, detections, semantics, validKPs);

        // Draw keypoints on original image
        cv::Mat allKPImage, validKPImage;
        cv::Scalar green = {0, 255, 0};
        drawKeypoints(image, keypoints, allKPImage, green);
        drawKeypoints(image, validKPs, validKPImage, green);

        // Display images side by side
        cv::Mat combinedImg = cv::Mat();
        combine_images(allKPImage, validKPImage, combinedImg);

        cv::imshow(windowName, combinedImg); // Show our image inside the created window.
        cv::waitKey(0);                // Wait for any keystroke in the window
    }

    cv::destroyWindow(windowName); //destroy the created window

    return 0;
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