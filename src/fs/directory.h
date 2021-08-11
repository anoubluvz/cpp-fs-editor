#include <string>
#include <vector>

#include "file.h"

class Directory {
    public:
        std::string dirPath;
        std::string dirName;
        
        Directory(const std::string& path);
        File* getFile(const std::string& fileName);
        Directory* getDirectory(const std::string& dirName);
    private:
        std::vector<Directory> m_Directories;
        std::vector<File> m_Files;
};