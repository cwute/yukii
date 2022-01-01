#include <iostream>
#include "Recoil Data.hpp"
#include "Vector2.hpp"
#include <Windows.h>
#include <chrono>
#include <cmath>
#include <Lmcons.h>
#include <ctime>
#include "Stuff.hpp"

//line 107 fix
#pragma warning(disable : 4996)

//playsound fix
#pragma comment(lib, "Winmm.lib")

//using namespace std;
float sens = 0.6f;
boolean randomize = true;
void QuerySleep(int ms)
{
    LONGLONG timerResolution;
    LONGLONG wantedTime;
    LONGLONG currentTime;
    QueryPerformanceFrequency((LARGE_INTEGER*)&timerResolution);
    timerResolution /= 1000;
    QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
    wantedTime = currentTime / timerResolution + ms;
    currentTime = 0;
    while (currentTime < wantedTime)
    {
        QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
        currentTime /= timerResolution;
    }
}


void Mouse_Move(Vector2 vals)
{
    mouse_event(MOUSEEVENTF_MOVE, (int)vals.x, (int)vals.y, 0, 0);
}

void Smoothing(float delay, float animation, Vector2 in,bool holo,bool scope8x,bool suppresor, int magsize) {
    bool debug = false;
    int x_ = 0, y_ = 0, t_ = 0;
    int xmult, ymult;

    
    

    xmult = in.x;
    ymult = in.y;

    if (holo) {
        xmult = xmult * 1.2f;
        ymult = ymult * 1.2f;
    }
    if (suppresor) {
        xmult = xmult * 0.8f;
        ymult = ymult * 0.8f;
    }
    if (scope8x) {
        xmult = xmult * 3.84f;
        ymult = ymult * 3.84f;
    }

    if (debug) {
        std::cout << "Current bullet: " << magsize << std::endl;
        std::cout << "Current Vector2: x: " << in.x << " y: " << in.y << std::endl;
        std::cout << "Calculated Vector2: x:" << xmult << " y: " << ymult << std::endl;
    }

    for (int i = 1; i <= (int)animation; ++i) {
        int xI = i * xmult / (int)animation;
        int yI = i * ymult / (int)animation;
        int tI = i * (int)animation / (int)animation;
        mouse_event(1, (int)xI - (int)x_ , (int)yI - (int)y_ , 0, 0);
        QuerySleep((int)tI - (int)t_);
        x_ = xI; y_ = yI; t_ = tI;
    }
    QuerySleep((int)delay - (int)animation);

}

void printStart() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 13);
    PlaySound(TEXT("D:\\stuff_for_c++_ playing_sounds_etc\\blackclover.wav"), NULL, SND_ASYNC);


    std::cout << R"(  ___    ___ ___  ___  ___  __    ___  ___     
 |\  \  /  /|\  \|\  \|\  \|\  \ |\  \|\  \    
 \ \  \/  / | \  \\\  \ \  \/  /|\ \  \ \  \   
  \ \    / / \ \  \\\  \ \   ___  \ \  \ \  \  
   \/  /  /   \ \  \\\  \ \  \\ \  \ \  \ \  \ 
 __/  / /      \ \_______\ \__\\ \__\ \__\ \__\
|\___/ /        \|_______|\|__| \|__|\|__|\|__|
\|___|/                                        
                                               
                                               )" << '\n';
   

    char* user = getenv("username");
    std::cout << "Welcome: " << std::string(user) << " uwu " <<std::endl;
   
    

    time_t now = time(0);
    char* dt = ctime(&now);
    std::cout << "Time of login: " << dt << std::endl;
    std::cout << std::endl;
    std::cout << "Currently playing: Black Catcher by Viceblanka" << std::endl;

}

void print(boolean holo, boolean scope8x,int choice, bool suppresor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 13);

    
    std::cout << R"(  ___    ___ ___  ___  ___  __    ___  ___     
 |\  \  /  /|\  \|\  \|\  \|\  \ |\  \|\  \    
 \ \  \/  / | \  \\\  \ \  \/  /|\ \  \ \  \   
  \ \    / / \ \  \\\  \ \   ___  \ \  \ \  \  
   \/  /  /   \ \  \\\  \ \  \\ \  \ \  \ \  \ 
 __/  / /      \ \_______\ \__\\ \__\ \__\ \__\
|\___/ /        \|_______|\|__| \|__|\|__|\|__|
\|___|/                                        
                                               
                                               )" << '\n';
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << "Keys: " << std::endl;
    std::cout << "AK = END" << std::endl;
    std::cout << "MP5 = PAGE UP" << std::endl;
    std::cout << "M249 = PAGE DOWN" << std::endl;
    std::cout << "SEMI = HOME " << std::endl;
    std::cout << "M39 = INSERT " << std::endl;
    std::cout << "LR = DELETE" << std::endl;
    std::cout << "TOMMY = ALT + DELETE" << std::endl;
    std::cout << "CUSTOM = ALT + INSERT" << std::endl;
    std::cout << "HOLO = F9" << std::endl;
    std::cout << "SCOPE 8X = F10" << std::endl;
    std::cout << "SUPPRESOR = ALT + F9 " << std::endl << std::endl;

    SetConsoleTextAttribute(hConsole, 11);
    std::cout << "Weapon: " << "                         ";
    switch (choice) {

         case 0:
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "none, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, mp5, m249, semi, m39, lr, tommy, custom" << std::endl;
              break;

         case 1:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "none, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "ak, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "mp5, m249, semi, m39, lr, tommy, custom" << std::endl;
              break;

         case 2:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "none, ak, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "mp5, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "m249, semi, m39, lr, tommy, custom" << std::endl;
              break;

         case 3:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, mp5, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "m249, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "semi, m39, lr, tommy, custom" << std::endl;
              break;

         case 4:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "none, ak, mp5, m249, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "semi, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "m39, lr, tommy, custom" << std::endl;
              break;
         case 5:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "none, ak, mp5, m249, semi, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "m39, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "lr, tommy, custom" << std::endl;
             break;
         case 6:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "none, ak, mp5, m249, semi, m39, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "lr,";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << " tommy, custom " << std::endl;
             break;
         case 7:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "none, ak, mp5, m249, semi, m39, lr, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "tommy, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << " custom " << std::endl;
             break;
         case 8:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "none, ak, mp5, m249, semi, m39, lr, tommy, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "custom " << std::endl;
             break;
    }

    SetConsoleTextAttribute(hConsole, 11);
    std::cout << std::endl;
    std::cout << "Attachments: " << "                    ";
    

    if (!holo && !suppresor && !scope8x) {
        SetConsoleTextAttribute(hConsole, 10);
        std::cout << "none, ";
    }
    if (holo || suppresor || scope8x) {
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "none, ";
    }
    if (holo) {
        SetConsoleTextAttribute(hConsole, 10);
        std::cout << "holo, ";
    }
    else if (!holo) {
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "holo, ";
    }
    if (scope8x) {
        SetConsoleTextAttribute(hConsole, 10);
        std::cout << "8x, ";
    }
    else if (!scope8x) {
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "8x, ";
    }
    if (suppresor) {
        SetConsoleTextAttribute(hConsole, 10);
        std::cout << "suppresor " << std::endl;
    }
    else if (!suppresor) {
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "suppresor " << std::endl;
    }
}

int main()
{
    SetConsoleTitle(L"Yukii");
    printStart();

    int choice = 0;
    boolean holo = false;
    boolean scope8x = false;
    boolean suppresor = false;
    boolean debug = true;

    while (true) {
        int magsize = 0;
        if (GetAsyncKeyState(VK_END) & 0x8000) {
            if (choice == 1) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
            else {
                choice = 1;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
        }
        if (GetAsyncKeyState(VK_PRIOR) & 0x8000) {
            if (choice == 2) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
            else{
                choice = 2;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
        }
        if (GetAsyncKeyState(VK_NEXT) & 0x8000) {
            if (choice == 3) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
            else {
                choice = 3;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
        }
        if (GetAsyncKeyState(VK_HOME) & 0x8000) {
            if (choice == 4) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
            else{
                choice = 4;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);

            }
        }
        if (GetAsyncKeyState(VK_INSERT) & 0x8000 && !(GetAsyncKeyState(VK_MENU) & 0x8000)) {

            if (choice == 5) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
            else {
                choice = 5;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);

            }
        }
        if (GetAsyncKeyState(VK_DELETE) & 0x8000 && !(GetAsyncKeyState(VK_MENU) & 0x8000)) {

            if (choice == 6) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
            else {
                choice = 6;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);

            }
        }
        if (GetAsyncKeyState(VK_F9) & 0x8000 && GetAsyncKeyState(VK_MENU) & 0x8000) {
            if (suppresor) {
                Beep(1000, 100);
                suppresor = false;
                system("CLS");
                print(holo,scope8x,choice,suppresor);
                Sleep(500);
            }
            else {
                suppresor = true;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
        }
        if (GetAsyncKeyState(VK_F9) & 0x8000 && !(GetAsyncKeyState(VK_MENU) & 0x8000)) {
            if (holo) {
                Beep(1000, 100);
                holo = false;
                scope8x = false;
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
            else{
                holo = true;
                scope8x = false;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
        }
        if (GetAsyncKeyState(VK_F10) & 0x8000) {
            if (scope8x) {
                Beep(1000, 100);
                scope8x = false;
                holo = false;
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
            else {
                scope8x = true;
                holo = false;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
        }
        if(GetAsyncKeyState(VK_MENU) & 0x8000 && GetAsyncKeyState(VK_DELETE)){
            if (choice == 7) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
            else {
                choice = 7;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);

            }
        }
        if (GetAsyncKeyState(VK_MENU) & 0x8000 && GetAsyncKeyState(VK_INSERT)){
            if (choice == 8) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);
            }
            else {
                choice = 8;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice, suppresor);
                Sleep(500);

            }
        }
        if (GetAsyncKeyState(VK_F12) & 0x8000) exit(0);

        switch (choice) {
        case 0:
            break;
        case 1:
            //ak
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {

                if (magsize < 31) {
                    if (magsize >= 1) {
                        Smoothing(133.f, AssaultRifleControl::control_ak[magsize], Stuff::getPos(AssaultRifle::data[magsize],AssaultRifle::data[magsize - 1]), holo, scope8x, suppresor, magsize);
                    }
                    else {
                        Smoothing(133.f, AssaultRifleControl::control_ak[magsize], Stuff::getPos(AssaultRifle::data[magsize], Vector2(0,0)), holo, scope8x, suppresor, magsize);
                    }
                        magsize++;
                }
            }
            break;
        case 2:
            //mp5
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 31) {
                    if (magsize >= 1) {
                        Smoothing(100.f, MP5Control::control_mp5[magsize], Stuff::getPos(MP5::data[magsize], MP5::data[magsize - 1]), holo, scope8x, suppresor, magsize);
                    }
                    else {
                        Smoothing(100.f, MP5Control::control_mp5[magsize], Stuff::getPos(MP5::data[magsize], Vector2(0, 0)), holo, scope8x, suppresor, magsize);
                    }
                    magsize++;
                }
            }
            break;
        case 3:
            //m249
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 100) {
                    if (magsize >= 1) {
                        Smoothing(103.f, 103.F, Stuff::getPos(M249::data[magsize], M249::data[magsize - 1]), holo, scope8x, suppresor, magsize);
                    }
                    else {
                        Smoothing(103.f, 103.F, Stuff::getPos(M249::data[magsize], Vector2(0, 0)), holo, scope8x, suppresor, magsize);
                    }
                    magsize++;
                }
            }
            break;
        case 4:
            //semi
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 17) {
                    if (magsize >= 1) {
                        Smoothing(150.f, 150.F, Stuff::getPos(semi::data[magsize], semi::data[magsize - 1]), holo, scope8x, suppresor, magsize);
                    }
                    else {
                        Smoothing(150.f, 150.F, Stuff::getPos(semi::data[magsize], Vector2(0, 0)), holo, scope8x, suppresor, magsize);
                    }
                    magsize++;
                }
            }
            break;
        case 5:
            //m39
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 21) {
                    if (magsize >= 1) {
                        Smoothing(205.f, 205.f, Stuff::getPos(M39::data[magsize], M39::data[magsize - 1]), holo, scope8x, suppresor, magsize);
                    }
                    else {
                        Smoothing(205.f, 205.f, Stuff::getPos(M39::data[magsize], Vector2(0, 0)), holo, scope8x, suppresor, magsize);
                    }
                    magsize++;
                }
            }
            break;
        case 6:
            //lr
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                  if (magsize < 31) {
                      if (magsize >= 1) {
                          Smoothing(120.f, LRControl::control_lr[magsize], Stuff::getPos(LR::data[magsize], LR::data[magsize - 1]), holo, scope8x, suppresor, magsize);
                      }
                      else {
                          Smoothing(120.f, LRControl::control_lr[magsize], Stuff::getPos(LR::data[magsize], Vector2(0, 0)), holo, scope8x, suppresor, magsize);
                      }
                      magsize++;
                  }
            }
            break;
        case 7:
            //tommy
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 21) {
                    if (magsize >= 1) {
                        Smoothing(129.f, tommyControl::control_tommy[magsize], Stuff::getPos(tommy::data[magsize], tommy::data[magsize -1]), holo, scope8x, suppresor, magsize);
                    }
                    else {
                        Smoothing(129.f, tommyControl::control_tommy[magsize], Stuff::getPos(tommy::data[magsize], Vector2(0, 0)), holo, scope8x, suppresor, magsize);
                    }
                    magsize++;
                    }
            }
            break;
        case 8:
            //custom
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 25) {
                    if (magsize >= 1) {
                        Smoothing(100.f, customControl::control_custom[magsize], Stuff::getPos(custom::data[magsize], custom::data[magsize - 1]), holo, scope8x, suppresor, magsize);
                    }
                    else {
                        Smoothing(100.f, customControl::control_custom[magsize], Stuff::getPos(custom::data[magsize], Vector2(0, 0)), holo, scope8x, suppresor, magsize);
                    }
                    magsize++;
                }
            }

            break;
        }
    

    }
}


