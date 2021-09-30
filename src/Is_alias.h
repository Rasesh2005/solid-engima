#include <iostream>
#include <filesystem>
namespace fs=std::filesystem;
#ifndef files
#define files
void printFile(){
    std::cout<<"All files are \n";
    std::string path="/";
     for (const auto & file : fs::directory_iterator(path))
        std::cout << file.path() << std::endl;
}
#endif