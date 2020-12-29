#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

Date::Date(int day, int month, int year) :Triad(day, month, year) {}

Date::Date(const Date& obj) : Triad(obj) {}

void Date::setDay(int day) {
	one = day;
	normalize();
}

void Date::setMonth(int month) {
	two = month;
	normalize();
}

void Date::setYear(int year) {
	three = year;
	normalize();
}

void Date::setString(string str) {
	string temp;
	if (str[1] == '.') {
		temp = str.substr(0, 1);
		str.erase(0, 2);
	}
	else if (str[2] == '.') {
		temp = str.substr(0, 2);
		str.erase(0, 3);
	}
	one = stoi(temp);
	if (str[1] == '.') {
		temp = str.substr(0, 1);
		str.erase(0, 2);
	}
	else if (str[2] == '.') {
		temp = str.substr(0, 2);
		str.erase(0, 3);
	}
	two = stoi(temp);
	three = stoi(str);
	normalize();
}

int Date::getDay()
{
	return one;
}

int Date::getMonth()
{
	return two;
}

int Date::getYear()
{
	return three;
}

/*
1.1.1111
1.01.1111
01.1.1111
01.01.1111
*/

bool Date::check() {
	bool ch = 1;
	if (((two == 4) || (two == 6) || (two == 9) || (two == 11)) && (one > 30))
		ch *= 0;
	else if (((two == 1) || (two == 3) || (two == 5) || (two == 7) || (two == 8) || (two == 10) || (two == 12)) && (one > 31))
		ch *= 0;
	else if (((two == 2) && (one > 28) && (three % 4 != 0)) || ((two == 2) && (one > 29) && (three % 4 == 0)))
		ch *= 0;
	return ch;
}

void Date::normalize() {
	while (!check())
		if ((two == 2) && (one > 28)) {
			if (three % 4 != 0) {
				one -= 28;
				two++;
			}
			else if ((three % 4 == 0) && (one > 29)) {
				one -= 29;
				two++;
			}
		}
		else if (((two == 4) || (two == 6) || (two == 9) || (two == 11)) && (one > 30)) {
			one -= 30;
			two++;
		}
		else if (((two == 1) || (two == 3) || (two == 5) || (two == 7) || (two == 8) || (two == 10)) && (one > 31)) {
			one -= 31;
			two++;
		}
		else if (((two == 12) && (one > 31))) {
			one -= 31;
			two = 1;
			three++;
		}
}

void Date::increaseOne() {
	one++;
	normalize();
}

void Date::increaseTwo() {
	if (two == 12) {
		three++;
		two = 1;
	}
	else
		two++;
}

void Date::increaseThree() {
	three++;
}

void Date::daysToDate(int n) {
	one += n - 697;
	normalize();
}

int Date::DateToDays() {
	int days = 0;
	for (int i = 1; i <= two; i++) {
		if ((i == 1) || (i == 3) || (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 12))
			days += 31;
		if ((i == 4) || (i == 6) || (i == 9) || (i == 11))
			days += 30;
		if (i == 2)
			days += 28;
	}
	days += one;
	if (three % 4 == 0) {
		days += three * 365.4;
		if (one >= 2)
			days++;
	}
	else if (three % 4 != 0) {
		int tempYear = three;
		while (tempYear % 4 != 0) {
			tempYear--;
			days += 365;
		}
		days += three * 365.4;
	}
	return days;
}


bool Date::highPitched() {
	return three % 4 == 0;
}

int Date::daysBetweenDates(Date obj)
{
	return abs(DateToDays() - obj.DateToDays());
}

ostream& operator<<(ostream& out, const Date obj)
{
	out << obj.one << "." << obj.two << "." << obj.three << endl;
	return out;
}

Date operator-(Date left, int right)
{
	int days = left.DateToDays();
	days -= right;
	left.setDay(1);
	left.setMonth(1);
	left.setYear(1);
	left.daysToDate(days);
	return left;
}

bool operator>(Date left, Date right) {
	return left.DateToDays() > right.DateToDays();
}

bool operator<(Date left, Date right) {
	return left.DateToDays() < right.DateToDays();
}

bool operator==(Date left, Date right) {
	return left.DateToDays() == right.DateToDays();
}
