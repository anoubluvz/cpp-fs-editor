#include "file.h"
#include <iostream>
#include <fstream>

File::File(const std::string& path, const std::string& data)
{
    // get filename from path
    std::string extractedFilename = path.substr(path.find_last_of("/\\") + 1);
    fileName = extractedFilename;
    filePath = path;

    std::cout << extractedFilename << std::endl;

    // todo: check if file exists if it exists then read data if not then just create one
    
    // create file on disk
    File::m_Data = data;
    std::ofstream file(path.c_str());
    file << data;
    file.close();
}

std::string File::getData() 
{
    std::string dataRead;
    std::ifstream file(filePath.c_str());
    while(getline(file, dataRead)) {
        std::cout << "Read data: " << dataRead << std::endl;
    }
    file.close();
    m_Data = dataRead;
    return dataRead;
}