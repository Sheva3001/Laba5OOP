#include "Time.h"
#include <iostream>
#include <string>
using namespace std;

Time::Time(int seconds, int minutes, int hours) :Triad(seconds, minutes, hours) {}

Time::Time(Time& obj) :Triad(obj) {}

void Time::setSeconds(int seconds) {
	one = seconds;
	normalize();
}

void Time::setMinutes(int minutes) {
	two = minutes;
	normalize();
}

void Time::setHours(int hours) {
	three = hours;
	normalize();
}

void Time::setString(string str) {
	string temp;
	if (str[1] == ':') {
		temp = str.substr(0, 1);
		str.erase(0, 2);
	}
	else if (str[2] == ':') {
		temp = str.substr(0, 2);
		str.erase(0, 3);
	}
	three = stoi(temp);
	if (str[1] == ':') {
		temp = str.substr(0, 1);
		str.erase(0, 2);
	}
	else if (str[2] == ':') {
		temp = str.substr(0, 2);
		str.erase(0, 3);
	}
	two = stoi(temp);
	one = stoi(str);
	normalize();
}

int Time::getSeconds()
{
	return one;
}

int Time::getMinutes()
{
	return two;
}

int Time::getHours()
{
	return three;
}

bool Time::check() {
	return ((one < 60) && (two < 60) && (three < 24));
}

void Time::normalize() {
	while (!check()) {
		if (one >= 60) {
			one -= 60;
			two++;
		}
		if (two >= 60) {
			two -= 60;
			three++;
		}
		if (three >= 24)
			three -= 24;
	}
}

void Time::increaseOne() {
	one++;
	normalize();
}

void Time::increaseTwo() {
	two++;
	normalize();
}

void Time::increaseThree() {
	three++;
	normalize();
}

int Time::timeToSeconds() {
	return three * 3600 + two * 60 + one;
}

int Time::timeToMinutes()
{
	return three * 60 + two;
}

int Time::seconsBetweenTimes(Time& obj) {
	return abs(timeToSeconds() - obj.timeToSeconds());
}

ostream& operator<<(ostream& out, const Time obj) {
	out << obj.three << ":" << obj.two << ":" << obj.one << endl;
	return out;
}

Time operator+(Time left, int right) {
	int sec = left.timeToSeconds() + right;
	left.setHours(0);
	left.setMinutes(0);
	left.setSeconds(sec);
	left.normalize();
	return left;
}

Time operator-(Time left, int right) {
	int sec = left.timeToSeconds() - right;
	left.setHours(0);
	left.setMinutes(0);
	left.setSeconds(sec);
	left.normalize();
	return left;
}

bool operator>(Time left, Time right) {
	return left.timeToSeconds() > right.timeToSeconds();
}

bool operator<(Time left, Time right) {
	return left.timeToSeconds() < right.timeToSeconds();
}

bool operator==(Time left, Time right) {
	return left.timeToSeconds() == right.timeToSeconds();
}
