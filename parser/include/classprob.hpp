#ifndef CLASSPROB_HPP
#define CLASSPROB_HPP

#include <assert.h>

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

#include <parser.hpp>

// Returns back a NxM matrix where N is the number of valid orbs that can
// confidently have a class applied to and M is the number of classes. To give
// an orb a class it needs to be either in a bounding box with no over lap with
// other bounding boxes or all bounding boxes that it's within need to have the
// same class. If an or cannot meet these requirements the row corresponding to
// the orb is filled with 0's.
//
// validKPs is a vector that upon return stores all the keypoints that have a
// class associated with them. The vector holds the index of the keypoint in the
// keypoints vector.
void get_semantic_info(
    const std::vector<cv::KeyPoint> &kp,
    const detections_t &detections,
    cv::Mat &semantics,
    std::vector<int> &validKPs);

// Checks to see whether the keypoint is within the bouding box. Borders are
// included.
bool is_keypoint_within_box(const cv::KeyPoint &kp, const detectptr_t &detection);

// Checks to see how many bounding boxes a single keypoint falls in. For each
// bounding box it falls in, the index of the detection is kept track in the
// boxes vector. The boxes vector is expected to be sent in as an empty vector.
void get_num_bbox_for_keypoint(
    const cv::KeyPoint &kp,
    const detections_t &detections,
    std::vector<int> &boxes);

// Returns true only if a keypoint is in multiple bounding boxes and they all
// have the same class that is something other than UNKNOWN
bool bboxes_have_same_valid_class(
    const detections_t &detections, 
    const std::vector<int> &boxes);

#endif