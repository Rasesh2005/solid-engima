#ifndef TTS
#define TTS
#include <iostream>
#include <string>
#ifdef _WIN32 || _WIN64
#include <sapi.h>
using namespace std;
void speak(wcin input)
{
    ISpVoice* pVoice=NULL;
    HRESULT hr;
    wstring input;
    a=CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (FAILED(a))
    {   
        cout << "ERROR 404 FAILED INITIALIZING COM\n";
        exit(1);
    }
    HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
    hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL,       IID_ISpVoice, (void **)&pVoice);
 
    if( SUCCEEDED( hr ) )
    {    
        hr = pVoice->Speak(input.c_str(), 0, NULL);
        pVoice->Release();
        pVoice = NULL;
    }
}
#else
    int speak(const std::string& script){
        if(system(("espeak "+script).c_str())!=0){
            std::cout<<"Installing espeak...\n";
            if(system("sudo apt install espeak")!=0){
                std::cout<<"Error occured try again!\n";
                return -1;
            }
        }
        return 0;
    }
#endif
#endif