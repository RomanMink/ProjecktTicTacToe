//#pragma once
#ifndef one
#define one
int corners[4] = { 0,2,6,8 };
const int size = 3;
const int Fsize = 9;

void printFeild(char field[][3])
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << ' ' << field[i][j] << ' ';
            if (j < size - 1) std::cout << '|';
        }
        std::cout << '\n';
        if (i < size - 1) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}
int Pchoose()
{
    int a;
    std::cin >> a;
    return a - 1;
}
bool fillbox(char s, int p, char* field[])
{
    if (Fsize > p and p >= 0) {
        if (*field[p] == ' ') { *field[p] = s; return 1; }
        else { std::cout << "the place is taken "; }
    }
    else { std::cout << "invalid value"; }
    return 0;
}

void fillfield(char symbol, char* field[])
{
    while (true)
    {
        int place = Pchoose();
        if (fillbox(symbol,place, field)){break;}
    }
}


bool iswin(char* b[], char l)
{
    if ((*b[7] == l && *b[4] == l && *b[1] == l) ||
        (*b[0] == l && *b[4] == l && *b[8] == l) ||
        (*b[0] == l && *b[3] == l && *b[6] == l) ||
        (*b[0] == l && *b[1] == l && *b[2] == l) ||
        (*b[3] == l && *b[4] == l && *b[5] == l) ||
        (*b[6] == l && *b[7] == l && *b[8] == l) ||
        (*b[2] == l && *b[4] == l && *b[6] == l) ||
        (*b[2] == l && *b[5] == l && *b[8] == l)) {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool turn(char symbol, char* field[], char mode, char isP, char dif,const char trueP)
{
    if (mode == 'p')
    {
        fillfield(symbol, field);
    }
    else
    {
        if (isP == 'X')
        {
            fillfield(symbol, field);
        }
        else
        {
            // hard складнисть блокує iгрока якщо 2 вже соять
            if (dif == 'h')
            {
                for (int i = 0; i < Fsize; ++i)
                {
                    if (fillbox(trueP, i, field))
                    {
                        if (iswin(field, trueP) == 0)
                        {
                            *field[i] = ' ';
                            fillbox(symbol, i, field);
                            return 0;
                        }
                        *field[i] = ' ';
                    }
                }
            }
            // нормальна складнисть збирає ряд якщо 2 вже соять
            if (dif == 'n' or dif == 'h')
            {
                for (int i = 0; i < Fsize; ++i)
                {
                    if (fillbox(symbol, i, field))
                    {
                        if (iswin(field, symbol) == 0)
                        {
                            return 0;
                        }
                        *field[i] = ' ';
                    }
                }
                // ход по кутам
                for(int i = rand() % 5; i <4;i += 1 )
                    if (fillbox(symbol, corners[ i], field)) { return 0; }
            }
            //рандом ход
            while (true) {
                int place = rand() % Fsize;
                if (*field[place] != ' ') { continue; }
                if (fillbox(symbol, place, field)) { return 0; }
            }
        }
    }
}
void endgame(const char trueP, char symbol, char mode)
{
    if (trueP == symbol)
    {
        std::cout << "You win!";
        if (mode != 'p') { std::cout << "AI is defeated"; }
    }
    else
    {
        std::cout << "You lose!";
        if (mode != 'p') { std::cout << "AI destroy the world"; }
    }
}
#endif