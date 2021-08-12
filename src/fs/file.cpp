#include "file.h"
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>

std::string readFile(const std::string& path)
{
    std::string dataRead;
    std::ifstream f(path.c_str());
    getline(f, dataRead);
    return dataRead;
}

bool fileExists(const std::string& path)
{
    struct stat info;
    return (stat(path.c_str(), &info) == 0);
}

File::File(const std::string& path, const std::string& data)
{
    // get filename from path
    std::string extractedFilename = path.substr(path.find_last_of("/\\") + 1);
    fileName = extractedFilename;
    filePath = path;

    std::cout << extractedFilename << std::endl;

    // todo: check if file exists if it exists then read data if not then just create one
    if(fileExists(path))
    {
        std::cout << "File already exists, Reading data!" << std::endl;
        // import file data
        std::string dataRead = readFile(path);
        m_Data = dataRead;
    }
    else
    {
        std::cout << "File doesn't exist, making file!" << std::endl;
        // create file on disk
        m_Data = data;
        std::ofstream file(path.c_str());
        file << data;
        file.close();
    }
}

std::string File::getData() 
{
    std::string dataRead = readFile(filePath);
    m_Data = dataRead;
    return dataRead;
}