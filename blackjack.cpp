#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>
#include <map>
#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>

extern float balance;
extern float bet;

using namespace std;

inline void GetCard(int& hand, vector< vector<wstring> >& coloda, vector< vector<wstring> >& player, int& temp);


inline int GetSum(vector< vector<wstring> >& player) {
	int sum = 0;
	map<wstring, int> point; // дешифратор: величина карты = кол-во очков

	point[L"2"] = 2;
	point[L"3"] = 3;
	point[L"4"] = 4;
	point[L"5"] = 5;
	point[L"6"] = 6;
	point[L"7"] = 7;
	point[L"8"] = 8;
	point[L"9"] = 9;
	point[L"10"] = 10;
	point[L"J"] = 10;
	point[L"Q"] = 10;
	point[L"K"] = 10;
	point[L"A"] = 11;
	for (int i = 0; i < player.size(); i++) {
		
		sum += point[player[i][0]];

	}
	
	return sum;

}

inline void jack() {
	setlocale(LC_ALL, "Rus");
	const int n = 52;
	
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	vector< vector<wstring> > coloda;
	coloda.resize(n, vector <wstring>(2));
	vector<wstring> cards = {L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"10", L"J", L"Q", L"K", L"A"};
	vector<wstring> mast = { L"♠", L"♥", L"♣", L"♦" }; //{ "♠", "♥", "♣", "♦" };

	vector< vector<wstring> > diller;
	diller.resize(11, vector <wstring>(2, L"0"));

	srand((unsigned)time(NULL));
	int i = 0, j = 2;
	while(i < 52){ 
		coloda[i][0] = cards[i / 4]; // заполняю колоду цифрами
		coloda[i][1] = mast[i % 4]; // заполняю колоду мастямиы
		i++;
	}

	int temp = rand() % 52, hand_diller = 0;
	GetCard(hand_diller, coloda, diller, temp);
	GetCard(hand_diller, coloda, diller, temp);

	vector< vector<wstring> > player;
	player.resize(11, vector <wstring>(2, L"0"));

	do { temp = rand() % 52; } while (coloda[temp][0] == L"0");
	int hand = 0;
	GetCard(hand, coloda, player, temp);
	GetCard(hand, coloda, player, temp);
	
	tp:
	while (GetSum(player) < 21) {
		wcout << L"Ваши карты: " << endl;
		i = 0;
		while (player[i][0] != L"0") {
			wchar_t symbol = L'-', space = L' ';
			wcout << L" " << setw(9) << setfill(symbol) << symbol << endl;
			wcout << L"|";
			if (player[i][0] == L"10") {
				wcout << setw(5) << setfill(space) << space;
			}
			else {
				wcout << setw(6) << setfill(space) << space;
			}
			wcout << player[i][0] << L" " << player[i][1] << L"|" << endl;
			for (int j = 0; j < 6; j++) {
				wcout << L"|";
				wcout << setw(9) << setfill(space) << space << L"|" << endl;
			}
			wcout << L" " << setw(9) << setfill(symbol) << symbol << endl;

			i++;
		}
		wcout << L"Ваши очки: " << GetSum(player) << endl;
		wcout << L"Желаете взять ещё карту? (1 - да, 2 - нет)" << endl;
		int decision = 0;
		wcin >> decision;
		system("cls");
		switch (decision) {
			case(1):{
				
				GetCard(hand, coloda, player, temp);
				goto tp;
				break;
			}
			default: {
				break;
			}
				   
		}
		break;
	}


	if (GetSum(player) <= 21) {
		wcout << L"Ваши карты: " << endl;
		i = 0;
		while (player[i][0] != L"0") {
			wchar_t symbol = L'-', space = L' ';
			wcout << L" " << setw(9) << setfill(symbol) << symbol << endl;
			wcout << L"|";
			if (player[i][0] == L"10") {
				wcout << setw(5) << setfill(space) << space;
			}
			else {
				wcout << setw(6) << setfill(space) << space;
			}
			wcout << player[i][0] << " " << player[i][1] << L"|" << endl;
			for (int j = 0; j < 6; j++) {
				wcout << L"|";
				wcout << setw(9) << setfill(space) << space << L"|" << endl;
			}
			wcout << L" "  << setw(9) << setfill(symbol) << symbol << endl;

			i++;
		}
		wcout << L"Ваши очки: " << GetSum(player) << endl;
		while (GetSum(diller) <= 18 && GetSum(diller) < GetSum(player)) {
			GetCard(hand_diller, coloda, diller, temp);
		}

		wcout << L"Карты Диллера: " << endl;
		i = 0;
		while (diller[i][0] != L"0") {
			wchar_t symbol = L'-', space = L' ';
			wcout << L" " << setw(9) << setfill(symbol) << symbol << endl;
			wcout << L"|";
			if (player[i][0] == L"10") {
				wcout << setw(5) << setfill(space) << space;
			}
			else {
				wcout << setw(6) << setfill(space) << space;
			}
			wcout << diller[i][0] << L" " << diller[i][1] << L"|" << endl;
			for (int j = 0; j < 6; j++) {
				wcout << L"|";
				wcout << setw(9) << setfill(space) << space << L"|" << endl;
			}
			wcout << L" " << setw(9) << setfill(symbol) << symbol << endl;

			i++;
		}

		wcout << L"Сумма диллера: " << GetSum(diller) << endl;


		if (GetSum(diller) > GetSum(player) && GetSum(diller) < 22) {
			wcout << L"Победа диллера!" << endl;
			balance -= bet;
		}
		else if (GetSum(diller) == GetSum(player) && GetSum(diller) < 22) {
			wcout << L"Ничья!" << endl;
		}
		else {
			wcout << L"Вы победили!" << endl;
			balance += bet;
		}
	}
	else {
		wcout << L"Ваши карты: " << endl;
		i = 0;
		while (player[i][0] != L"0") {
			wchar_t symbol = L'-', space = L' ';
			wcout << L" " << setw(9) << setfill(symbol) << symbol << endl;
			wcout << L"|";
			if (player[i][0] == L"10") {
				wcout << setw(5) << setfill(space) << space;
			}
			else {
				wcout << setw(6) << setfill(space) << space;
			}
			wcout << player[i][0] << L" " << player[i][1] << L"|" << endl;
			for (int j = 0; j < 6; j++) {
				wcout << L"|";
				wcout << setw(9) << setfill(space) << space << L"|" << endl;
			}
			wcout << setw(9) << setfill(symbol) << symbol << endl;

			i++;
		}
		wcout << L"Ваши очки: " << GetSum(player) << endl;
		wcout << L"Вы проиграли!" << endl;
		balance -= bet;
	}


	this_thread::sleep_for(std::chrono::milliseconds(10000));
}

inline void GetCard(int& hand, vector< vector<wstring> >& coloda, vector< vector<wstring> >& player, int& temp) {
	// hand -  кол-во карт в руке
	do { temp = rand() % 52; } while (coloda[temp][0] == L"0"); // генерируем новую карту, пока не встретится та, что еще есть в колоде 
	player[hand][0] = coloda[temp][0];
	player[hand][1] = coloda[temp][1];
	coloda[temp][0] = L"0";
	hand++;
}