#include <iostream>
#include "settings.cpp"
#include <iomanip>

using namespace std;

float balance = 0.0;
float chance = 20;

int main()
{
    setlocale(LC_ALL, "Rus");
    // Вывести надпись казино

    cout << "\n";

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

        // Игра в игровые автоматы
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
 