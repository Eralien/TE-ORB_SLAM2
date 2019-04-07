#include <detection.h>
    
Detection::Detection(double probability, std::string name)
: prob(probability), className(name)
{
}

void Detection::setBoundingBox(std::vector<size_t> boundingBox)
{
    bbox = boundingBox;
}
