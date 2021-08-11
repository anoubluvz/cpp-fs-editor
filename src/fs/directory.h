#include <string>
#include <vector>

#include "file.h"

class Directory {
    public:
        std::string path;
        std::string dirName;
        
        Directory(std::string& path);
        File* getFile(std::string& fileName);
        Directory* getDirectory(std::string& dirName);
    private:
        std::vector<Directory> m_Directories;
        std::vector<File> m_Files;
};