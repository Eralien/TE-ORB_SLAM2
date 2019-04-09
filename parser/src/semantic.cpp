#include <semantic.h>

int main(int argc, char* argv[])
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
        
        // Read in semantic information from prediction file
        detections_t detections = parse::get_detections(yolotxt);
        
        cv::imshow(windowName, image); // Show our image inside the created window.
        cv::waitKey(0); // Wait for any keystroke in the window
    }

    cv::destroyWindow(windowName); //destroy the created window

    return 0;
}