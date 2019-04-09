// This file creates a report with the following information:
// 1. Number of different class
// 2. Sorted list of the number of occurences of each class

#include <analytics.hpp>

const std::string PREFIX = "../../";

inline std::string get_class_name(std::ifstream &file)
{
    std::string str, className;
    getline(file, str);
    std::stringstream ss(str);

    while (ss >> str)
    {
        if (!parse::is_probability(str))
        {
            className += str;
            continue;
        }
        break;
    }
    return className;
}

void write_report(const std::vector<ClassData> &stats)
{
    std::cout << "Object Detection Report" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Number of Unique Classes: " << stats.size() << std::endl;
    std::cout << std::endl;

    for (const auto &item : stats)
    {
        std::cout << "Name: " << item.name << "\t\t"
                  << "Count: " << item.count << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    std::ifstream file(PREFIX + "/data/prediction_info_1_room.txt");
    if (!file.is_open())
    {
        std::cout << "Error opening file!" << std::endl;
        return 0;
    }

    std::vector<ClassData> stats;
    while (!file.eof())
    {
        int numDetections = parse::get_num_detections(file);

        for (uint i = 0; i < numDetections; ++i)
        {
            // Extract class information
            std::string className = get_class_name(file);

            // Update count
            auto it = std::find(stats.begin(), stats.end(), className);
            if (it != stats.end())
            {
                it->count++;
            }
            else
            {
                stats.push_back(ClassData(className));
            }

            // Bounding Box information .. ignore line
            std::string bboxline;
            getline(file, bboxline);
        }
    }

    // Sort detections by class
    std::sort(stats.begin(), stats.end(),
              [](const ClassData &c1, const ClassData &c2) { return c1.count > c2.count; });

    write_report(stats);

    return 0;
}
