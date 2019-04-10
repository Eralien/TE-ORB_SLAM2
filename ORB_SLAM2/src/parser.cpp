#include <parser.hpp>

std::vector<size_t> parse::extract_bbox(std::ifstream &file)
{
    std::string line;
    getline(file, line);
    std::stringstream ss(line);

    uint numval;
    std::string text, semicolon;

    std::vector<size_t> bbox;
    for (size_t i = 0; i < 4; ++i)
    {
        ss >> text >> numval >> semicolon;
        bbox.push_back(numval);
    }
    return bbox;
}

detections_t parse::get_detections(std::ifstream &file)
{
    detections_t detectVector;

    int numDetections = get_num_detections(file);
    detectVector.reserve(numDetections);

    for (uint i = 0; i < numDetections; ++i)
    {
        // Read in the class name... The loop is necessary because some class
        // names are more than 1 word. For example one the class names is cell
        // phone
        std::string str, className;
        getline(file, str);
        std::stringstream ss(str);

        while (ss >> str)
        {
            if (!is_probability(str))
            {
                className += str;
                continue;
            }
            break;
        }
        // Read in the probability score of the class
        double prob = atof(str.c_str());

        // std::cout << "Class Name: " << className << std::endl;
        // std::cout << "Probability: " << prob << std::endl;

        // Create detection object and add it to the vector
        detectptr_t obj = std::make_shared<Detection>(prob, className);
        auto bbox = extract_bbox(file);
        obj->set_bounding_box(bbox);
        detectVector.push_back(obj);
    }

    return detectVector;
}
