#include "Date.h"
#include "Time.h"
#include <iostream>
using namespace std;

void Dates() {
	Date date(0, 0, 0);
	string str; int command = -1;
	cout << "Введите дату:" << endl;
	cin >> str;
	date.setString(str);
	Triad* p = &date;
	while (command != 0) {
		cout << "Выберите действие:" << endl
			<< "1. Увеличить на день" << endl
			<< "2. Увеличить на месяц" << endl
			<< "3. Увеличить на год" << endl
			<< "0. Выход" << endl;
		cin >> command;
		switch (command)
		{
		case 1:
			p->increaseOne();
			cout << date;
			break;
		case 2:
			p->increaseTwo();
			cout << date;
			break;
		case 3:
			p->increaseThree();
			cout << date;
			break;
		}
	}
}

void Times() {
	Time time(0, 0, 0);
	string str; int command = -1;
	cout << "Введите время:" << endl;
	cin >> str;
	time.setString(str);
	Triad* p = &time;
	while (command != 0) {
		cout << "Выберите действие:" << endl
			<< "1. Увеличить на секунду" << endl
			<< "2. Увеличить на минуту" << endl
			<< "3. Увеличить на час" << endl
			<< "0. Выход" << endl;
		cin >> command;
		switch (command)
		{
		case 1:
			p->increaseOne();
			cout << time;
			break;
		case 2:
			p->increaseTwo();
			cout << time;
			break;
		case 3:
			p->increaseThree();
			cout << time;
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int com = 0;
	cout << "1. Работа с датой" << endl
		<< "2. Работа со временем" << endl;
	cin >> com;
	if (com == 1)
		Dates();
	else if (com == 2)
		Times();
	return 0;
}