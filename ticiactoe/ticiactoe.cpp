// ticiactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Feild.h"
const int size = 3;
const int Fsize = 9;
int corners[4] = { 0,2,6,8 };
char ox[2]{ 'O','X' };


int main()
{

    char field[size][size]{};
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            field[i][j] = ' ';
        }
    };

    char* ifield[Fsize]{ &field[0][0] ,&field[0][1] ,&field[0][2] , &field[1][0] , &field[1][1] ,&field[1][2] ,&field[2][0] ,&field[2][1] ,&field[2][2] };
    std::cout << "------------------------GAME KRESTIKI NOLIKI-------------------------------\n";
    printFeild(field);
    std::cout << "To play print nmbers from 1 to 9:\n";

    char mode, dif = 'o';
    char buffer[50];
    while (true)
    {
        std::cout << "Play aganst Bot or aganst Player?(b or p)";
        std::cin >> buffer;
        mode = buffer[0];
        if (mode == 'b' or mode == 'p') { break; }
    }
    if (mode == 'b') {
           while (true)
           {
               std::cout << "Choose difikulty easy (e), normal (n),hard (h)";
               std::cin >> buffer;
               dif = buffer[0];
               if (dif == 'e' or dif == 'n' or dif == 'h') { break; }
           }
       }
    srand(time(NULL));
    int isP = rand() % 2;


    std::cout << "you play " << ox[isP] << "\n";
    
    int turns = 1;
    while (turns != 9)
    {
        turn('X', ifield, mode, ox[isP], dif, ox[isP]);
        printFeild(field);
        if (iswin(ifield, 'X') == 0) { endgame(isP, ox, 'X', mode); break; }
        ++turns;
        turn('O', ifield, mode, ox[!isP], dif, ox[isP]);
        printFeild(field);
        if (iswin(ifield, 'O') == 0) { endgame(isP, ox, 'O', mode); break; }
        ++turns;
    }
    if (turns == 9)
    {
        std::cout << "Friendship\n";
    }
}