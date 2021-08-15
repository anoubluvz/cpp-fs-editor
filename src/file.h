#include <string>

class File {
    public:
        std::string filePath;
        std::string fileName;
        
        File(const std::string& path, const std::string& data);
        std::string getData();
    private:
        std::string m_Data;
};