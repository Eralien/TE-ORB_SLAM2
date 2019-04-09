#include <classprob.hpp>

bool is_keypoint_within_box(
    const cv::KeyPoint &kp,
    const detectptr_t &detection)
{
    bool ret = true;
    ret = ret && (kp.pt.x > detection->bbox[0] && kp.pt.x < detection->bbox[1]);
    ret = ret && (kp.pt.y > detection->bbox[2] && kp.pt.y < detection->bbox[3]);
    return ret;
}

void get_num_bbox_for_keypoint(
    const cv::KeyPoint &kp,
    const detections_t &detections,
    std::vector<int> &boxes)
{
    boxes.clear(); // Sanity check

    for (uint i = 0; i < detections.size(); ++i)
    {
        if (is_keypoint_within_box(kp, detections[i]))
        {
            boxes.push_back(i);
        }
    }
}

bool bboxes_have_same_valid_class(
    const detections_t &detections, 
    const std::vector<int> &boxes)
{
    assert(boxes.size() >= 2);

    CLASSTYPE classtype = detections[boxes[0]]->classtype;
    for (uint i = 1; i < boxes.size(); ++i)
    {
        if (detections[boxes[i]]->classtype != classtype)
            return false;
    }

    if (classtype == UNKNOWN)
        return false;

    return true;
}

void get_semantic_info(
    const std::vector<cv::KeyPoint> &keypoints,
    const detections_t &detections,
    cv::Mat &semantics)
{
    cv::Mat zeroRow = cv::Mat::zeros(1,NUM_CLASSTYPES,CV_32FC1);

    for (uint i = 0; i < keypoints.size(); ++i)
    {
        std::vector<int> validBBoxes;
        get_num_bbox_for_keypoint(keypoints[i], detections, validBBoxes);

        // Orb does not fall within a single bounding box so set all class
        // probabilities to 0
        if (validBBoxes.size() == 0)
        {
            zeroRow.copyTo(semantics.row(i));
            continue;
        }

        // Orb falls in a single bounding box
        CLASSTYPE classtype = detections[validBBoxes[0]]->classtype;
        if (validBBoxes.size() == 1 && classtype != UNKNOWN)
        {
            cv::Mat row = zeroRow.clone();
            row.at<float>(0, classtype) = detections[validBBoxes[0]]->prob;
            row.copyTo(semantics.row(i));
            continue;
        }

        // Orb falls in multiple bounding boxes - need to check and see if all
        // the bounding boxes it falls in have the same class
        if(bboxes_have_same_valid_class(detections, validBBoxes))
        {
            cv::Mat row = zeroRow.clone();
            row.at<float>(0, classtype) = detections[validBBoxes[0]]->prob;
            row.copyTo(semantics.row(i));
        }
        else
        {
            zeroRow.copyTo(semantics.row(i));
        }
    }
}
