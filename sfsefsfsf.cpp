#include <iostream>
#include "Recoil Data.hpp"
#include "Vector2.hpp"
#include <Windows.h>
#include <chrono>
#include <cmath>
#include <Lmcons.h>


using namespace std;
float sens = 0.6f;
int fov;
boolean randomize = true;

float ArRpmMilis = 1000.0f / (450 / 60.0f);

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
    // c-style casts lolol
    mouse_event(MOUSEEVENTF_MOVE, (int)vals.x, (int)vals.y, 0, 0);
}


void Smoothing(float delay, float animation, Vector2 in,bool holo,bool scope8x) {
    int x_ = 0, y_ = 0, t_ = 0;
    int xmult, ymult;
    if (holo) {
         xmult = (int)(in.x * 1.2 / 4) / sens / 1;
         ymult = (int)(in.y  * 1.2/ 4) / sens / 1;
    }
    else if (scope8x) {
        xmult = (int)(in.x * 3.84 / 4) / sens / 1;
        ymult = (int)(in.y * 3.84 / 4) / sens / 1;
    }
    if(!holo && !scope8x) {
        xmult = (int)(in.x / 4) / sens / 1;
        ymult = (int)(in.y / 4) / sens / 1;
    }
    
    
    if (randomize) {
        xmult = xmult + rand() % 2 / 4;
        ymult = ymult + rand() % 2 / 4;
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


    std::cout << R"(  ___    ___ ___  ___  ___  __    ___  ___     
 |\  \  /  /|\  \|\  \|\  \|\  \ |\  \|\  \    
 \ \  \/  / | \  \\\  \ \  \/  /|\ \  \ \  \   
  \ \    / / \ \  \\\  \ \   ___  \ \  \ \  \  
   \/  /  /   \ \  \\\  \ \  \\ \  \ \  \ \  \ 
 __/  / /      \ \_______\ \__\\ \__\ \__\ \__\
|\___/ /        \|_______|\|__| \|__|\|__|\|__|
\|___|/                                        
                                               
                                               )" << '\n';
   

    //cba fucking around with getting username shits too hard in c++ so im using some random memory adress
    string idk = "negr";
    std::cout << "Welcome: " << &idk;
}

void print(boolean holo, boolean scope8x,int choice) {
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
    SetConsoleTextAttribute(hConsole, 11);
    std::cout << "Weapon: " << "                         ";
    switch (choice) {

         case 0:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, mp5, m249, semi" << endl;
              break;

         case 1:
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "ak, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "mp5, m249, semi" << endl;
              break;

         case 2:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "mp5, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "m249, semi" << endl;
              break;

         case 3:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, mp5, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "m249, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "semi" << endl;
              break;

         case 4:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, mp5, m249, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "semi" << endl;
              break;
    }

    SetConsoleTextAttribute(hConsole, 11);
    std::cout << endl;
    std::cout << "Scope: " << "                          ";
    if (holo) {
        SetConsoleTextAttribute(hConsole, 10);
        std::cout << "holo, ";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "8x, none" << endl;
    }
    else if (scope8x) {
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "holo, ";
        SetConsoleTextAttribute(hConsole, 10);
        std::cout << "8x, ";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "none" << endl;
    }
    else {
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "holo, 8x, ";
        SetConsoleTextAttribute(hConsole, 10);
        std::cout << "none" << endl;
    }
    
}

int main()
{
    SetConsoleTitle(L"Yukii");
    printStart();

    int choice = 0;
    boolean holo = false;
    boolean scope8x = false;

    while (true) {
        
        int magsize = 0;
        if (GetAsyncKeyState(VK_END) & 0x8000) {
            if (choice == 1) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice);
                Sleep(500);
            }
            else {
                choice = 1;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice);
                Sleep(500);

            }

        }
        if (GetAsyncKeyState(VK_PRIOR) & 0x8000) {
            if (choice == 2) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice);
                Sleep(500);
            }
            else if(choice == 1 || choice == 0) {
                choice = 2;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice);
                Sleep(500);

            }

        }
        if (GetAsyncKeyState(VK_NEXT) & 0x8000) {
            if (choice == 3) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice);
                Sleep(500);
            }
            else if (choice == 1 || choice == 0|| choice == 2) {
                choice = 3;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice);
                Sleep(500);

            }

        }
        if (GetAsyncKeyState(VK_HOME) & 0x8000) {
            if (choice == 4) {
                choice = 0;
                Beep(1000, 100);
                system("CLS");
                print(holo, scope8x, choice);
                Sleep(500);
            }
            else if (choice == 1 || choice == 0 || choice == 2 || choice == 3) {
                choice = 4;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice);
                Sleep(500);

            }

        }

        
        if (GetAsyncKeyState(VK_F9) & 0x8000) {
            if (holo) {
                Beep(1000, 100);
                holo = false;
                scope8x = false;
                system("CLS");
                print(holo, scope8x, choice);
                Sleep(500);
            }
            else{
                holo = true;
                scope8x = false;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice);
                Sleep(500);
            }

        }
        if (GetAsyncKeyState(VK_F10) & 0x8000) {
            if (scope8x) {
                Beep(1000, 100);
                scope8x = false;
                holo = false;
                system("CLS");
                print(holo, scope8x, choice);
                Sleep(500);
            }
            else {
                scope8x = true;
                holo = false;
                Beep(800, 100);
                system("CLS");
                print(holo, scope8x, choice);
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
                    Smoothing(133.f, AssaultRifleControl::control_ak[magsize], AssaultRifle::data[magsize],holo,scope8x);
                    magsize++;
                }
            }
            break;
        case 2:
            //mp5
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 31) {
                    Smoothing(100.f, MP5Control::control_mp5[magsize], MP5::data[magsize], holo,scope8x);
                    magsize++;
                }
            }
            break;
        case 3:
            //m249
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 100) {
                    Smoothing(110.f, 110.f, M249::data[magsize], holo,scope8x);
                    magsize++;
                }
            }
            break;
        case 4:
            //semi
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 100) {
                    Smoothing(103.f, 103.f, semi::data[0], holo, scope8x);
                    magsize++;
                }
            }
            break;
        }

    }

}


