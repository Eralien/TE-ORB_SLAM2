#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include <detection.h>

class Detection;

using detectptr_t = std::shared_ptr<Detection>;
using detections_t = std::vector<detectptr_t>;

detections_t parse_predictions(std::ifstream &predictTxt);

std::vector<size_t> extract_bbox(std::ifstream &file);
