#include "file.h"
#include <iostream>
#include <fstream>

File::File(const std::string& path, const std::string& data)
{
    // get filename from path
    std::string fileName = path.substr(path.find_last_of("/\\") + 1);
    File::fileName = fileName;
    File::path = path;

    // create file on disk
    File::m_Data = data;
    std::ofstream file(path.c_str());
    file << data.c_str();
    file.close();
}

std::string File::getData() 
{
    std::string dataRead;
    std::ifstream file(File::path.c_str());
    while(getline(file, dataRead)) {
        std::cout << "Read data: " << dataRead << std::endl;
    }
    file.close();
    File::m_Data = dataRead;
    return dataRead;
}