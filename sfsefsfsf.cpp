#include <iostream>
#include "Recoil Data.hpp"
#include "Vector2.hpp"
#include <Windows.h>
#include <chrono>
#include <cmath>
#include <Lmcons.h>
#include <ctime>

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
    // c-style casts lolol
    mouse_event(MOUSEEVENTF_MOVE, (int)vals.x, (int)vals.y, 0, 0);
}

void Smoothing(float delay, float animation, Vector2 in,bool holo,bool scope8x,bool suppresor) {
    int x_ = 0, y_ = 0, t_ = 0;
    int xmult, ymult;
    if (holo && !suppresor) {
         xmult = (int)(in.x * 1.2 / 4) / sens / 1;
         ymult = (int)(in.y  * 1.2/ 4) / sens / 1;
    }
    else if (scope8x && !suppresor) {
        xmult = (int)(in.x * 3.84 / 4) / sens / 1;
        ymult = (int)(in.y * 3.84 / 4) / sens / 1;
    }
    else if (suppresor && !holo && !scope8x) {
        xmult = (int)(in.x * 0.8 / 4) / sens / 1;
        ymult = (int)(in.y * 0.8 / 4) / sens / 1;
    }
    else if (suppresor && holo) {
        xmult = (int)(in.x * 1.2 * 0.8 / 4) / sens / 1;
        ymult = (int)(in.y * 1.2 * 0.8 / 4) / sens / 1;
    }
    else if (suppresor && scope8x) {
        xmult = (int)(in.x * 3.84 * 0.8 / 4) / sens / 1;
        ymult = (int)(in.y * 3.84 * 0.8 / 4) / sens / 1;
    }
    else if(!holo && !scope8x && !suppresor) {
        xmult = (int)(in.x / 4) / sens / 1;
        ymult = (int)(in.y / 4) / sens / 1;
    }
    if (randomize) {
        xmult = xmult + rand() % 2 / 2;
        ymult = ymult + rand() % 2 / 2;
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
    SetConsoleTextAttribute(hConsole, 11);
    std::cout << "Weapon: " << "                         ";
    switch (choice) {

         case 0:
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "none, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, mp5, m249, semi, m39, lr" << std::endl;
              break;

         case 1:
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "ak, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "mp5, m249, semi, m39, lr" << std::endl;
              break;

         case 2:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "mp5, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "m249, semi, m39, lr" << std::endl;
              break;

         case 3:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, mp5, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "m249, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "semi, m39, lr" << std::endl;
              break;

         case 4:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, mp5, m249, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "semi, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "m39, lr" << std::endl;
              break;
         case 5:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, mp5, m249, semi, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "m39, ";
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "lr" << std::endl;
             break;
         case 6:
             SetConsoleTextAttribute(hConsole, 12);
             std::cout << "ak, mp5, m249, semi, m39, ";
             SetConsoleTextAttribute(hConsole, 10);
             std::cout << "lr" << std::endl;

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
        if (GetAsyncKeyState(VK_INSERT) & 0x8000) {

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
        if (GetAsyncKeyState(VK_DELETE) & 0x8000) {

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
        if (GetAsyncKeyState(VK_F7) & 0x8000) {
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
        if (GetAsyncKeyState(VK_F9) & 0x8000) {
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
        if (GetAsyncKeyState(VK_F12) & 0x8000) exit(0);

        switch (choice) {
        case 0:
            break;
        case 1:
            //ak
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {

                if (magsize < 31) {
                    Smoothing(133.f, AssaultRifleControl::control_ak[magsize], AssaultRifle::data[magsize],holo,scope8x,suppresor);
                    magsize++;
                }
            }
            break;
        case 2:
            //mp5
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 31) {
                    Smoothing(100.f, MP5Control::control_mp5[magsize], MP5::data[magsize], holo,scope8x,suppresor);
                    magsize++;
                }
            }
            break;
        case 3:
            //m249
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 100) {
                    Smoothing(110.f, 110.f, M249::data[magsize], holo,scope8x,suppresor);
                    magsize++;
                }
            }
            break;
        case 4:
            //semi
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 100) {
                    Smoothing(103.f, 103.f, semi::data[0], holo, scope8x,suppresor);
                    magsize++;
                }
            }
            break;
        case 5:
            //m39
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                if (magsize < 100) {
                    Smoothing(205.f, 205.f, M39::data[0], holo, scope8x, suppresor);
                    magsize++;
                }
            }
            break;
        case 6:
            //lr
            while (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000) {

                  if (magsize < 31) {
                      Smoothing(100.f,LRControl::control_lr[magsize], LR::data[magsize], holo, scope8x, suppresor);
                      magsize++;
                  }
            }
            break;
        }
    }
}


