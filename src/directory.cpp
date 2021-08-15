#include "directory.h"
#include <direct.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>
#include <stdio.h>

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
            if(*(buffer->d_name) != '.' || *(buffer->d_name) != '.') {
                std::string documentPath = path + "/" + buffer->d_name;
                if(buffer->d_type == NUM_FOLDER)
                {
                    // folder
                    std::cout << "folder: " << buffer->d_name << std::endl;
                    Directory newDir(documentPath);
                    m_Directories.push_back(newDir);
                }
                else if(buffer->d_type == NUM_FILE)
                {
                    // file
                    std::cout << "file: " << buffer->d_name << std::endl;
                    File newFile(documentPath, " ");
                    m_Files.push_back(newFile);
                }
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

bool Directory::deleteFile(const std::string& fileName)
{
    for(File file : m_Files)
    {
        if(file.fileName == fileName)
        {
            if(remove(file.filePath.c_str()) != 0 )
            {
                std::cout << "Error deleting file: " << file.fileName << std::endl;
            }
        }
    }
}

bool Directory::deleteDirectory(const std::string& dirName)
{
    for(auto it = m_Directories.begin(); it != m_Directories.end(); it++)
    {
        Directory m_dir = *it;
        if(m_dir.dirName == dirName)
        {
            struct dirent *entry = NULL;
            DIR *dir = opendir(m_dir.dirPath.c_str());
            while(entry = readdir(dir))
            {
                DIR *sub_dir = NULL;
                FILE *file = NULL;
                char abs_path[100] = {0};
                if(*(entry->d_name) != '.' || *(entry->d_name) != '..')
                {
                    sprintf(abs_path, "%s/%s",  m_dir.dirPath.c_str(), entry->d_name);
                    if(sub_dir = opendir(abs_path))
                    {
                        closedir(sub_dir);
                        deleteDirectory(abs_path);
                    }
                    else
                    {
                        if(file = fopen(abs_path, "r"))
                        {
                            fclose(file);
                            remove(abs_path);
                        }
                    }
                }
            }
            m_Directories.erase(it);
        }
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