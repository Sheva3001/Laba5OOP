#include "Date.h"
#include "Time.h"
#include <iostream>
using namespace std;

void Dates() {
	Date date(0, 0, 0);
	string str; int command = -1;
	cout << "������� ����:" << endl;
	cin >> str;
	date.setString(str);
	Triad* p = &date;
	while (command != 0) {
		cout << "�������� ��������:" << endl
			<< "1. ��������� �� ����" << endl
			<< "2. ��������� �� �����" << endl
			<< "3. ��������� �� ���" << endl
			<< "0. �����" << endl;
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
	cout << "������� �����:" << endl;
	cin >> str;
	time.setString(str);
	Triad* p = &time;
	while (command != 0) {
		cout << "�������� ��������:" << endl
			<< "1. ��������� �� �������" << endl
			<< "2. ��������� �� ������" << endl
			<< "3. ��������� �� ���" << endl
			<< "0. �����" << endl;
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
	cout << "1. ������ � �����" << endl
		<< "2. ������ �� ��������" << endl;
	cin >> com;
	if (com == 1)
		Dates();
	else if (com == 2)
		Times();
	return 0;
}