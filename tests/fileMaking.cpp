#include "../src/fs/file.h"
#include <iostream>

int main()
{
    int pause;
    std::string fileName;
    std::string fileData;
    std::cout << "Creating file, pick a name: " << std::endl;
    std::cin >> fileName;
    std::cout << "What data do you want to be stored? : " << std::endl;
    std::cin >> fileData;
    
    // Create file
    File file(fileName, fileData);
    std::cout << "Made file with data: " << file.getData() << std::endl;

    std::cin >> pause;
}