#include <string>

class File {
    public:
        std::string path;
        std::string fileName;
        
        File(std::string& path);
        std::string getData();
    private:
        std::string m_Data;
};