# SemanticORB-SLAM

This repository is for Team 7 project of NAME 568/EECS 568/ROB 530: [__Mobile Robotics__](http://robots.engin.umich.edu/mobilerobotics/) of University of Michigan.

__Team members__: Madhav Achar, Siyuan Feng, Yue Shen, Hui Sun, Xi Lin

## SemanticORB-SLAM
 SemanticORB-SLAM is a work that investigate two different methods to improve the tracking of [ORB-SLAM2](https://github.com/raulmur/ORB_SLAM2) in environments where it is difficult to extract ORB features. Methods are:
 * Incorporate high level semantic information from an object classification system such as [YOLOv3](https://pjreddie.com/darknet/yolo/) to improve ORB matching and association in frame by frame tracking. 
 * Utilize RGB-D odometry tracking based on the photo-consistency formulation of the frame-to-frame tracking problem performed in <cite>Real-time visual odometry from dense RGB-D images</cite> and implemented in OpenCV's RGB-D odometry class.

 ## License
 In our work we use the repo of [ORB-SLAM2](https://github.com/raulmur/ORB_SLAM2) and [darknet](https://github.com/pjreddie/darknet).

ORB-SLAM2 is released under a [GPLv3 license](https://github.com/raulmur/ORB_SLAM2/blob/master/License-gpl.txt). For any commercial or academic usage, please visit ORB-SLAM2 github repo to ensure feasibility.

If you use SemanticORB-SLAM, please cite the works in [Related Publications](#related-publications).


## Installation
For darknet and ORB-SLAM2, please install them separately. Our work has been tested on __Ubuntu 16.04__.

### ORB-SLAM2
We encourage you to read its [README](./ORB_SLAM2/README.md) for installation details first. Make sure you have installed these prerequisites:
* C++11 or C++0x Compiler
* Pangolin
* OpenCV, version higher than 2.4.3
* Eigen3


 ### Related Publications
 1. <cite>ORB-SLAM2: An Open-Source SLAM System for Monocular, Stereo, and RGB-D Cameras</cite>:
 ```
@ARTICLE{orbslam2, 
author={R. {Mur-Artal} and J. D. {Tardos}}, 
journal={IEEE Transactions on Robotics}, 
title={ORB-SLAM2: An Open-Source SLAM System for Monocular, Stereo, and RGB-D Cameras}, 
year={2017}, 
volume={33}, 
number={5}, 
pages={1255-1262}, 
keywords={cameras;distance measurement;Kalman filters;mobile robots;motion estimation;path planning;robot vision;SLAM (robots);ORB-SLAM;open-source SLAM system;lightweight localization mode;map points;zero-drift localization;SLAM community;monocular cameras;stereo cameras;simultaneous localization and mapping system;RGB-D cameras;Simultaneous localization and mapping;Cameras;Optimization;Feature extraction;Tracking loops;Trajectory;Localization;mapping;RGB-D;simultaneous localization and mapping (SLAM);stereo}, 
doi={10.1109/TRO.2017.2705103}, 
ISSN={1552-3098}, 
month={Oct},}
 ```
 2. <cite>Yolov3: An incremental improvement</cite>:
```
@article{redmon2018yolov3,
  title={Yolov3: An incremental improvement},
  author={Redmon, Joseph and Farhadi, Ali},
  journal={arXiv preprint arXiv:1804.02767},
  year={2018}
}
```

 3. <cite>Real-time visual odometry from dense RGB-D images</cite>:
 ```
 @INPROCEEDINGS{rgbd-odo, 
author={F. {Steinbrücker} and J. {Sturm} and D. {Cremers}}, 
booktitle={2011 IEEE International Conference on Computer Vision Workshops (ICCV Workshops)}, 
title={Real-time visual odometry from dense RGB-D images}, 
year={2011}, 
volume={}, 
number={}, 
pages={719-722}, 
keywords={distance measurement;image processing;iterative methods;target tracking;realtime visual odometry;dense RGB-D images;Microsoft Kinect camera;energy function;rigid body motion;twist coordinates;coarse-to-fine scheme;iterative closest point algorithm;camera motion;camera tracking applications;Cameras;Robots;Visualization;Equations;Iterative closest point algorithm;Three dimensional displays;Streaming media}, 
doi={10.1109/ICCVW.2011.6130321}, 
ISSN={}, 
month={Nov},}
 ```
