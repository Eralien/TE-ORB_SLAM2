#ifndef CLASSPROB_HPP
#define CLASSPROB_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <parser.hpp>

// Returns back a NxM matrix where N is the number of valid orbs that can
// confidently have a class applied to and M is the number of classes. To give
// an orb a class it needs to be either in a bounding box with no over lap with
// other bounding boxes or all bounding boxes that it's within need to have the
// same class. If an or cannot meet these requirements the row corresponding to
// the orb is filled with 0's.
void get_semantic_info(
    const std::vector<cv::KeyPoint> &kp,
    const detections_t &detections,
    cv::Mat &semantics);

#endif