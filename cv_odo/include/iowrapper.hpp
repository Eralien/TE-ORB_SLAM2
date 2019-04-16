#ifndef IOWRAPPER_HPP
#define IOWRAPPER_HPP

#include "boost/filesystem.hpp"

using namespace boost::filesystem;

void loadFolder(const path& path_to_folder, std::vector<path> & files);
void printFilesInFolder(std::ostream &os, std::vector<path> &files, const path & folder_name);

#endif