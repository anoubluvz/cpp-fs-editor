#include "directory.h"
#include <direct.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>

#define NUM_FOLDER 16
#define NUM_FILE 0

bool dirExists(const std::string& path)
{
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}

Directory::Directory(const std::string& path)
{
    // get dirname from path
    std::string extractedDirname = path.substr(path.find_last_of("/\\") + 1);
    dirName = extractedDirname;
    dirPath = path;

    // todo: check if directory exists and if it does then just read data
    if(dirExists(path))
    {
        DIR *dir;
        struct dirent *buffer;
        dir = opendir(path.c_str());
        while((buffer = readdir(dir)) != NULL)
        {
            if(buffer->d_type == NUM_FOLDER)
            {
                // folder
                std::cout << "folder: " << buffer->d_name << std::endl;
            }
            else if(buffer->d_type == NUM_FILE)
            {
                // file
                std::cout << "file: " << buffer->d_name << std::endl;
            }
        }
        closedir(dir);
    }
    else
    {
        // create directory on disk
        _mkdir(dirPath.c_str());
    }
}

File* Directory::getFile(const std::string& fileName)
{
    File* fileFound = NULL;
    for(File& file : m_Files) {
        if(file.fileName == fileName) {
            fileFound = &file;
        }
    }
    return fileFound;
}

Directory* Directory::getDirectory(const std::string& dirName)
{
    Directory* dirFound = NULL;
    for(Directory& directory : m_Directories) {
        if(directory.dirName == dirName) {
            dirFound = &directory;
        }
    }
    return dirFound;
}