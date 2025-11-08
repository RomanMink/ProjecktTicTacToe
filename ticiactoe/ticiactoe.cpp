// ticiactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Feild.h"


char Players[2]{ 'O','X' };


int main()
{
    char* ifield[Fsize]{};
    char field[size][size]{};
    int n = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            field[i][j] = ' ';
            ifield[n] = &field[i][j];
            ++n;
        }
    };
    
    //char* ifield[Fsize]{ &field[0][0] ,&field[0][1] ,&field[0][2] , &field[1][0] , &field[1][1] ,&field[1][2] ,&field[2][0] ,&field[2][1] ,&field[2][2] };
    std::cout << "------------------------GAME KRESTIKI NOLIKI-------------------------------\n";
    printFeild(field);
    std::cout << "To play print nmbers from 1 to 9:\n";

    char mode, difficulty = 'o';
    char buffer[50];
    std::cout << "Play aganst Bot or aganst Player?(b or p)";
    while (true)
    {
        std::cin >> buffer;
        mode = buffer[0];
        if (mode == 'b' or mode == 'p') { break; }
        else { std::cout << "invalid value print agan:"; }
    }
    if (mode == 'b') {
        std::cout << "Choose difikulty easy (e), normal (n),hard (h)";
           while (true)
           {
               std::cin >> buffer;
               difficulty = buffer[0];
               if (difficulty == 'e' or difficulty == 'n' or difficulty == 'h') { break; }
               else { std::cout << "invalid value print agan:"; }
           }
       }
    srand(time(NULL));
    int isP = rand() % 2;
    bool isPlayer = true;


    std::cout << "you play " << Players[isP] << "\n";
    const char truePlayer = Players[isP];
    int turns = 1;
    while (turns != 9)
    {
        turn(Players[isPlayer], ifield, mode, Players[isP], difficulty, truePlayer);
        printFeild(field);
        if (iswin(ifield, Players[isPlayer]) == 0) { endgame(truePlayer, Players[isPlayer], mode); break; }
        ++turns;
        isPlayer = !isPlayer;
        isP = !isP;
    }
    if (turns == 9)
    {
        std::cout << "Friendship\n";
    }

}