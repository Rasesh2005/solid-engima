#include <chrono>
#include <iostream>
#include "tts.h"
void greet() {
    const auto start = std::chrono::system_clock::now();
    const auto t = std::chrono::system_clock::to_time_t(start);
    const auto formatted_time = std::localtime(&t);
    int time = formatted_time->tm_hour;
    if(time<12){
        speak("\"Good Morning\"");
        std::cout<<"Good Morning,\n";
    }
    else if(time>=12 && time<=15){
        speak("\"Good Afternoon\"");
        std::cout<<"Good Afternoon,\n";
    }
    else if(time>15 && time<=18){
        speak("\"Good Evening\"");
        std::cout<<"Good Evening,\n";
    }
    else if(time>18 && time<=24){
        speak("\"Good Night\"");
        std::cout<<"Good Night,\n";
    }
}