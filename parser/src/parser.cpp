#include <parser.h>

std::vector<size_t> extract_bbox(std::ifstream &file)
{
    size_t numval;
    std::string text;
    char semicolon;

    std::vector<size_t> bbox;
    for (size_t i = 0; i < 4; ++i)
    {
        file >> text >> numval >> semicolon;
        bbox.push_back(numval);
    }
    return bbox;
}

detections_t parse_predictions(std::ifstream &file)
{
    // Read in first meta data line of prediction file
    std::string dateTimeInfo;
    getline(file, dateTimeInfo);

    detections_t detectVector;

    std::string className;
    double prob;

    // Each detection in the prediction file is structured as follows
    // car 0.997897
    // left: 293; right: 412; top: 191; bottom: 235;
    while (file >> className >> prob)
    {
        detectptr_t obj = std::make_shared<Detection>(prob, className);
        obj->setBoundingBox(extract_bbox(file));

        detectVector.push_back(obj);
    }
    return detectVector;
}
