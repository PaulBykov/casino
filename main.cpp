﻿#include <iostream>
#include "settings.cpp"
#include <iomanip>
#include "game_machine.cpp"

using namespace std;

float balance = 0.0;
int chance = 20;
float bet = 0.0;

int main()
{
    _setmode(_fileno(stdout), _O_TEXT);
    _setmode(_fileno(stdin), _O_TEXT);
    _setmode(_fileno(stderr), _O_TEXT);
    setlocale(LC_ALL, "Rus");
    system("cls");
    char space = ' ';
    cout << setw(40) << setfill(space) << space;
    cout << " $$$$    $$$$    $$$$   $$$$$$  $$  $$   $$$$" << endl;
    cout << setw(40) << setfill(space) << space;
    cout << "$$  $$  $$  $$  $$        $$    $$$ $$  $$  $$" << endl;
    cout << setw(40) << setfill(space) << space;
    cout << "$$      $$$$$$   $$$$     $$    $$ $$$  $$  $$" << endl;
    cout << setw(40) << setfill(space) << space;
    cout << "$$  $$  $$  $$      $$    $$    $$  $$  $$  $$" << endl;
    cout << setw(40) << setfill(space) << space;
    cout << " $$$$   $$  $$   $$$$   $$$$$$  $$  $$   $$$$" << endl;
    
    cout << "\n \n";

    cout << setw(45) << setfill(space) << space;
    cout << "$$$$$    $$$$   $$  $$   $$$$   $$" << endl;
    cout << setw(45) << setfill(space) << space;
    cout << "$$  $$  $$  $$   $$$$   $$  $$  $$" << endl;
    cout << setw(45) << setfill(space) << space;
    cout << "$$$$$   $$  $$    $$    $$$$$$  $$" << endl;
    cout << setw(45) << setfill(space) << space;
    cout << "$$  $$  $$  $$    $$    $$  $$  $$" << endl;
    cout << setw(45) << setfill(space) << space;
    cout << "$$  $$   $$$$     $$    $$  $$  $$$$$$" << endl;

    cout << "\n \n \n";

    cout << "Ваш баланс: " << balance << endl << endl;

    cout << "1) Игра в БлэкДжэк " << endl;
    cout << "2) Зал игровых автоматов " << endl;
    cout << "3) Настройки " << endl;

    int decision; cin >> decision;
    
    switch (decision) {
        case(1): {

            // Вызвать метод для старта игры в блекджек
            break;
        }
        case(2): {
            system("cls");
            cout << "Сделайте ваши ставки: ";
            cin >> bet;
            system("cls");
            mashine();
            main();
            break;
        }
        case(3): {
            setup();
            system("cls");
            main();
            break;
        }
        default: {
            cout << "Ошибка ввода! Следуйте инструкциям при выполнении программы!";
        }
    }

    return 0;
}
 