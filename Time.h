#pragma once
#include "Triad.h"
#include <iostream>
using namespace std;

class Time : public Triad {
public:
	Time(int seconds = 0, int minutes = 0, int hours = 0);
	Time(Time& obj);
	void setSeconds(int seconds);
	void setMinutes(int minutes);
	void setHours(int hours);
	void setString(string str);
	int getSeconds();
	int getMinutes();
	int getHours();
	bool check();
	void normalize();
	void increaseOne() override;
	void increaseTwo() override;
	void increaseThree() override;
	int timeToSeconds();
	int timeToMinutes();
	int seconsBetweenTimes(Time& obj);
	friend ostream& operator<< (ostream& out, const Time obj);
	friend Time operator+ (Time left, int right);
	friend Time operator- (Time left, int right);
	friend bool operator> (Time left, Time right);
	friend bool operator< (Time left, Time right);
	friend bool operator== (Time left, Time right);
};