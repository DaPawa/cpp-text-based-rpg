#ifndef OSDEPENDENT
#define OSDEPENDENT

#ifdef WINDOWS
#include "windows.h"
#endif // WINDOWS

/*This is a simple function that clears the screen
based on what operating system used, since they're different
for whatever reason*/
void clearScreen(){

    #ifdef WINDOWS

    system("PAUSE");
    system("CLS");

    #endif // WINDOWS
    #ifdef LINUX

    //Cont is just a variable that'll be used for getline()
    std::string cont;

    //Prompts player to press enter, flushes buffer and clears screen
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.clear();
    std::cin.ignore(1);
    std::getline(std::cin, cont);

    system("clear");

    #endif // LINUX
}
/*
void displayMap(int level){
    std::array<std::string, 10> map;
    int playerX, playerY;
    switch(level){
        case 1:
            map[0] = "###################";
            map[1] = "#O       #        #";
            map[2] = "#        ###      #";
            map[3] = "#        X #      #";
            map[4] = "########## #      #";
            map[5] = "#          X      #";
            map[6] = "#          #      #";
            map[7] = "#                 #";
            map[8] = "#          #       ";
            map[9] = "###################";
            playerX = 1; playerY = 1;
            break;

    }
    std::cout << "\nKEY:\nO = Player\n# = Wall\nX = Enemy\n" << std::endl;
    bool running = true;
    std::string newMap = map[playerX];
    std::cout << newMap << std::endl;
    std::cout << newMap[playerY] << std::endl;
    //#ifdef WINDOWS

    while(running == true){
        for(int i = 0; i < 10; i++){
            std::cout << map[i] << std::endl;
        }
        if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState(0x57)){
            if(map[playerX][playerY + 1] == static_cast<std::string>("#")) continue;
            if(map[playerX][playerY + 1] == static_cast<std::string>("X")) {std::cout << "Hit an enemy!" << std::endl; continue;}
            map[playerX][playerY] = " ";
            map[playerX][++playerY] = "O";
        }
        if(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x44)){
            if(map[playerX + 1][playerY] == static_cast<std::string>("#")) continue;
            if(map[playerX + 1][playerY] == static_cast<std::string>("X")) {std::cout << "Hit an enemy!" << std::endl; continue;}
            map[playerX][playerY] = " ";
            map[++playerX][playerY] = "O";
        }
        if(GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(0x53)){
            if(map[playerX][playerY - 1] == static_cast<std::string>("#")) continue;
            if(map[playerX][playerY - 1] == static_cast<std::string>("X")) {std::cout << "Hit an enemy!" << std::endl; continue;}
            map[playerX][playerY] = " ";
            map[playerX][--playerY] = "O";
        }
        if(GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x41)){
            if(map[playerX - 1][playerY] == static_cast<std::string>("#")) continue;
            if(map[playerX - 1][playerY] == static_cast<std::string>("X")) {std::cout << "Hit an enemy!" << std::endl; continue;}
            map[playerX][playerY] = " ";
            map[--playerX][playerY] = "O";
        }
    }

    //#endif // WINDOWS
}*/

#endif // OSDEPENDENT

