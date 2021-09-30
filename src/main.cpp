#include <iostream>
#include <chrono>
#include "greet.h"
#include "alias.h"
#include "speedtest.h"
#include "tts.h"
#include "ls_alias.h"
int main(){
    greet();
    std::string cmnd;
    bool extraCmnd=false;
    while (true)
    {
        std::cout<<">>";
        getline(std::cin,cmnd);
        if(cmnd.substr(0,5)=="alias"){
            AliasHelper(cmnd);
        }
        else if(cmnd=="speedtest"){
            speedTest();
        }
        else if(cmnd=="clear"){
            system("clear");
        }
        else if(cmnd=="weather"){
            int t=system("python3 deps/weather.py");
            if(t!=0){
                speak("Trying to install dependency,");
                std::cout<<"Trying to install dependency, (REQUESTS)\n";
                system("pip install requests");
                std::cout<<"Trying again\n";
                if(system("python3 deps/weather.py")!=0){
                    speak("Error occured please try again ,are you connected to internet?");
                    std::cout<<"Error occured please try again (are you connected to internet?)\n";
                }
            }
        }
        else if(cmnd=="exit"){
            return 0;
        }
        else{
            std::ifstream reader("alias.txt");
            std::string line;
            while(std::getline(reader,line)){
                if(line.substr(0,cmnd.length())==cmnd){
                    extraCmnd=true;
                    system((line.substr(cmnd.length()+1,line.length()-cmnd.length())).c_str());
                }
            }
            if(!extraCmnd){
                speak("\"No_such command found!\"");
                std::cout<<"No such command found!\n";
                extraCmnd=false;
            }
        }
    }
}
