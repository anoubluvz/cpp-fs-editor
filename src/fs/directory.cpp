#include <direct.h>
#include "directory.h"

Directory::Directory(const std::string& path)
{
    // get dirname from path
    std::string dirName = path.substr(path.find_last_of("/\\") + 1);
    Directory::dirName = dirName;
    Directory::path = path;

    // create directory on disk
    _mkdir(path.c_str());
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