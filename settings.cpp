#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

extern float balance;
extern int chance;

inline void setup() {

	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));
	system("cls");

	cout << "1) ��������� ������ " << endl;
	cout << "2) �������� ���� ������ " << endl;
	cout << "3) �����-������ " << endl;
	cout << "��� ������: " << 1 + rand() % 10000 << endl;


	int decision; cin >> decision;
	system("cls");
	switch (decision) {
		case(1): {
			string num, cnn, srok;
			int sum;
			cout << "������� ����� �����: ";
			cin >> num;
			cout << "������� CNN: ";
			cin >> cnn;

			cout << "������� ����� ����������: ";
			cin >> sum;

			balance += sum;
			system("cls");
			cout << "����������� ����������. ��������!";
			this_thread::sleep_for(std::chrono::milliseconds(3000)); //sleep for 1 second
			system("cls");
			cout << "���������� ��������� �������! \n ��������������� ����� 2 �������...";
			this_thread::sleep_for(std::chrono::milliseconds(2000));
			break;
		}
		case(2): {
			cout << "�������� ����: \n 1 - ������ \n 2 - ������� \n 3 - ������� \n";
			cin >> decision;
			switch (decision) {
				case(1): {
					system("color 6");
					break;
				}
				case(2): {
					system("color 2");
					break;
				}
				case(3): {
					system("color 3");
					break;
				}
			}
			break;
		}
		case(3): {
			cout << "1) �������� ������ " << endl;
			cout << "2) �������� ����� � ������ " << endl;
			cin >> decision;
			switch (decision) {
				case(1): {
					cout << "������� ������: " << balance << endl;
					cout << "������� ����� ��������: " << endl;
					cin >> balance;
					break;
				}
				case(2): {
					
					cout << "������� �������� ������� �� ������ " << endl;
					cin >> chance;

				}
			}
			break;

		}
		default: {
			break;
		}
	
	}

}