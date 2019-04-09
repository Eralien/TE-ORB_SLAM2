#include <detection.hpp>

Detection::Detection(double probability, std::string &name)
    : prob(probability), classtype(match_classtype(name))
{
}

void Detection::set_bounding_box(std::vector<size_t> &boundingBox)
{
    bbox = boundingBox;
}

CLASSTYPE Detection::match_classtype(std::string &name)
{
    if (name == "laptop")
        return LAPTOP;
    if (name == "cellphone")
        return CELLPHONE;
    if (name == "remote")
        return REMOTE;
    if (name == "tvmonitor")
        return TVMONITOR;
    if (name == "mouse")
        return MOUSE;
    return UNKNOWN;
}
