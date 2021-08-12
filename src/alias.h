#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include "tts.h"
#ifdef __linux__
    #include <unistd.h>
#endif
namespace fs=std::filesystem;

void AliasHelper(const std::string&);
void Usage();
bool isExecutable(const std::string&);
bool aliasExist();
void createAlias();
void deleteAlias();

void AliasHelper(const std::string& cmnd){
    if(cmnd == "alias --create"){
        createAlias();
    }
    else if(cmnd == "alias --help"){
        Usage();
    }
    else if(cmnd == "alias --delete"){
        deleteAlias();
    }
    else{
        Usage();
    }
}
void Usage(){
    std::cout<<"alias --create  ~  creates an alias\n";
    std::cout<<"alias --delete  ~  deletes an alias\n";
}
bool isExecutable(const std::string& path){
    #ifdef __linux__
        if(!access(path.c_str(),X_OK)){
            return true;
        }
        return false;
    #endif
    //windows user spesific (exe,bat)
    for(const auto& ending:{".exe",".bat"})
    {
        if(path.ends_with(ending)){
            return true;
        }
    }
    return false;
    
}
bool aliasExist(const std::string& name){
    std::ifstream reader("alias.txt");
    std::string line;
    while(std::getline(reader,line)){
        if(line.substr(0,name.length())==name){
            return true;
        }
    }
    return false;
}
void createAlias(){
    std::string name,path;
    bool created=false;
    while(!created){
        speak("\"Please enter the name of alias\"");
        std::cout<<"Please enter the name of alias\n>>";
        getline(std::cin,name);
        std::cin.clear();

        if (aliasExist(name))
        {
            speak("\"The  alias name already exists, Try Again\"");
            std::cout<<"The  alias name already exists, Try Again!!\n";
            continue;
        }
        speak("\"Please enter the path to executable\"");
        std::cout<<"Please enter the path to executable\n>>";
        getline(std::cin,path);
        std::cin.clear();

        if(!fs::exists(fs::path(path))){
            speak("\"No such file exists, Try again\"");
            std::cout<<"No such file exists, Try again!!\n";
            continue;
        }
        if(isExecutable(path))
            created=true;
        else{

            speak("\"The given file is not an executable, Try again\"");
            std::cout<<"The given file is not an executable, Try again!!\n";
        }
    }
    std::ofstream writer("alias.txt",std::ofstream::app);
    writer<<name<<" "<<path<<"\n";
    speak("\"Alias created\"");
    std::cout<<"Alias created!\n";
}
void deleteAlias(){
    speak("\"Enter the namme of the alias\"");
    std::cout<<"Enter the namme of the alias\n>>";
    std::string name;
    getline(std::cin,name);
    std::string line;
    bool exists=false;
    std::ifstream reader("alias.txt");
    std::vector<std::string> perLine;
    while(std::getline(reader,line)){
        if(line.substr(0,name.length())==name){
            exists=true;
            continue;
        }
        perLine.push_back(line);
    }

    if(!exists){
        speak("\"No such alias found\"");
        std::cout<<"No such alias found!\n";
        return;
    }
    std::ofstream writer("alias.txt");
    for(const auto& Pline:perLine){
        writer<<Pline<<"\n";
    }
    speak("\"Alias deleted sucssfully\"");
    std::cout<<"Alias deleted sucssfully!\n";
}