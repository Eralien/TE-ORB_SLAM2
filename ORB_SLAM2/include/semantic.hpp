#ifndef SEMANTIC_HPP
#define SEMANTIC_HPP

#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

#include <parser.hpp>
#include <classprob.hpp>

const std::string PREFIX = "../";
const std::string IMAGE_LIST = PREFIX + "data/TUM_list.txt";
const std::string YOLO_TXT = PREFIX + "data/prediction_info_full.txt";

const uint MAX_FEATURES = 500;

#endif