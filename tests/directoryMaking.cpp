#include "../src/fs/directory.h"
#include <iostream>

int main()
{
    int pause;
    std::string dirPath;
    std::cout << "Creating directory, choose path: " << std::endl;
    std::cin >> dirPath;
    
    // Create directory
    Directory directory(dirPath);

    std::cin >> pause;
}