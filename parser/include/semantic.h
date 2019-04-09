#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

#include <parser.h>

const std::string PREFIX = "../../";
const std::string IMAGE_LIST = PREFIX + "data/TUM_list.txt";
const std::string YOLO_TXT = PREFIX + "data/prediction_info_1_room.txt";
