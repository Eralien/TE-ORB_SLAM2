#ifndef RGBDODO_HPP
#define RGBDODO_HPP


#include <opencv_odometry/rgbd.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <memory>
#include <vector>
#include <iostream>

class CameraParams
{
    public:
    static const float FOCUS_LENGTH;
    static const float CX;
    static const float CY;

    static const float MIN_DEPTH;        // in meters
    static const float MAX_DEPTH;        // in meters
    static const float MAX_DEPTH_DIFF;   // in meters
    static const float MAX_POINTS_PART;
    
    // This is for TUM dataset
    static const float PIXEL_TO_METER_SCALEFACTOR;
};

const float CameraParams::FOCUS_LENGTH = 525.0;
const float CameraParams::CX = 325.1;
const float CameraParams::CY = 249.7;

const float CameraParams::MIN_DEPTH = 0.8f;        // in meters
const float CameraParams::MAX_DEPTH = 4.0f;        // in meters
const float CameraParams::MAX_DEPTH_DIFF = 0.08f;  // in meters
const float CameraParams::MAX_POINTS_PART = 0.09f;

const float CameraParams::PIXEL_TO_METER_SCALEFACTOR = 0.0002;

class RGB_ODO
{
    public:
        std::shared_ptr<cv::rgbd::Odometry> odom;
        cv::Mat camera_matrix;
    
    public:
        RGB_ODO()
        {
            createCameraMatrix();
            setupParams();
        }

        RGB_ODO(const cv::Mat & params)
        {
            createCameraMatrix(params);
            setupParams();
        }

    private:
        void createCameraMatrix()
        {
            float vals[] = {CameraParams::FOCUS_LENGTH, 
                            0., 
                            CameraParams::CX, 
                            0., 
                            CameraParams::FOCUS_LENGTH, 
                            CameraParams::CY, 
                            0., 
                            0., 
                            1.};
            camera_matrix = cv::Mat(3, 3, CV_32FC1, vals).clone();
        }

        void createCameraMatrix(const cv::Mat & params)
        {
            float vals[] = {params.at<float>(0,0), 
                            0., 
                            params.at<float>(0,2), 
                            0., 
                            params.at<float>(1,1), 
                            params.at<float>(1,2), 
                            0., 
                            0., 
                            1.};
            camera_matrix = cv::Mat(3, 3, CV_32FC1, vals).clone();
        }

        void setupParams()
        {
            std::vector<int> iterCounts(4);
            iterCounts[0] = 7;
            iterCounts[1] = 7;
            iterCounts[2] = 7;
            iterCounts[3] = 10;

            std::vector<float> minGradMagnitudes(4);
            minGradMagnitudes[0] = 12;
            minGradMagnitudes[1] = 5;
            minGradMagnitudes[2] = 3;
            minGradMagnitudes[3] = 1;

            odom = std::make_shared<cv::rgbd::RgbdOdometry>(
                camera_matrix, CameraParams::MIN_DEPTH, 
                CameraParams::MAX_DEPTH, CameraParams::MAX_DEPTH_DIFF, 
                iterCounts,
                minGradMagnitudes, CameraParams::MAX_POINTS_PART,
                cv::rgbd::Odometry::RIGID_BODY_MOTION);
            std::cout << "RGBD Odometry Initialized!" << std::endl;
        }
};

#endif