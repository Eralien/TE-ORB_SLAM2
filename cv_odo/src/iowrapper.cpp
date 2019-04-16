#include "iowrapper.hpp"



void loadFolder(const path& path_to_folder, std::vector<path> & files)
{
    for (directory_entry &file : directory_iterator(path_to_folder))
    {
        files.push_back(file.path().filename());
    }
}

void printFilesInFolder(std::ostream &os, std::vector<path> &files, const path & folder_name)
{
    os << "Files in " << folder_name << "..." << std::endl;
    os << "Number of files: " << files.size() << std::endl;
    for (auto & file : files)
    {
        os << file.string() << std::endl;
    }
    os << "\n\n";
}
