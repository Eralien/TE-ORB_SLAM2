#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <unordered_map>

#include <detection.hpp>

class Detection;

using detectptr_t = std::shared_ptr<Detection>;
using detections_t = std::vector<detectptr_t>;

namespace parse
{

// Given the file stream object for the predictions text file, it returns all
// the detections as a vector for a single image. The file stream object is
// returned in a state such that the next time it is called it will read the
// detections for the next image in the sequence.
//
// The data from the predicitons file needs to have detections in the following
// format as an example
// car 0.997897
// left: 293; right: 412; top: 191; bottom: 235;
detections_t get_detections(std::ifstream &predictTxt);

// Extracts the bounding box information of the detection and returns the
// information as a vector. Indices 0 and 1 represent the x value of the left
// and right corners. Indices 3 and 4 represent the y value of the top and
// bottom corners.
std::vector<size_t> extract_bbox(std::ifstream &file);

// Returns the number of detections for the image currently being processed
// The function expects the meta data information in the following format:
//
// 2 NEW Mon Apr  8 23:51:53 2019
//
// In the above example, 2 represents the number of detections
inline uint get_num_detections(std::ifstream &file)
{
    std::string metaData;
    getline(file, metaData);
    std::istringstream iss(metaData);

    uint numDetections;
    iss >> numDetections;
    return numDetections;
}

// Simple number check to determine if string is class or probability
inline bool is_probability(const std::string &s)
{
    return std::isdigit(*s.begin());
}

} // namespace parse

#endif