#include <parser.h>
#include <detection.h>

const std::string PREFIX = "../../";

void TEST_print_bbox(detections_t &detections)
{
    for (size_t i = 0; i < detections.size(); ++i)
    {
        for (size_t j = 0; j < detections[0]->bbox.size(); ++j)
        {
            std::cout << detections[i]->bbox[j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::ifstream predictionFile(PREFIX + "/data/prediction_info.txt");
    if(!predictionFile.is_open())
    {
        std::cout << "Error opening file!" << std::endl;
        return 0;
    }
 
    detections_t detections = parse_predictions(predictionFile);

    TEST_print_bbox(detections);

    return 0;
}