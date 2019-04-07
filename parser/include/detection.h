#ifndef DETECTION_HPP
#define DETECTION_HPP

#include <vector>
#include <iostream>

class Detection 
{
public:
    double prob;
    std::vector<size_t> bbox;
    std::string className;

public:
    Detection(double probability, std::string name);

    void setBoundingBox(std::vector<size_t> boundingBox);
};

#endif