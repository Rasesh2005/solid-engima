#include <iostream>
void speedTest(){
    #ifdef __linux__
        system("deps/linux/speedtest");
    #else
        system("deps/windows/speedtest.exe");
    #endif
}