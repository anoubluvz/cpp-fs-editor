#include "directory.h"
#include <direct.h>

Directory::Directory(const std::string& path)
{
    // get dirname from path
    std::string extractedDirname = path.substr(path.find_last_of("/\\") + 1);
    dirName = extractedDirname;
    dirPath = path;

    // todo: check if directory exists and if it does then just read data
    
    // create directory on disk
    _mkdir(dirPath.c_str());
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