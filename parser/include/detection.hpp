#ifndef DETECTION_HPP
#define DETECTION_HPP

#include <vector>
#include <iostream>
#include <cstring>

const uint NUM_CLASSTYPES = 6;

enum CLASSTYPE
{
    LAPTOP,
    CELLPHONE,
    REMOTE,
    TVMONITOR,
    MOUSE,
    UNKNOWN
};

class Detection
{
  public:
    double prob;
    std::vector<size_t> bbox;
    CLASSTYPE classtype;

  public:
    Detection(double probability, std::string &name);

    void set_bounding_box(std::vector<size_t> &boundingBox);

    CLASSTYPE match_classtype(std::string &classstr);
};

#endif