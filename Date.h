#pragma once
#include "Triad.h"
#include <iostream>

class Date : public Triad {
public:
	Date(int day = 0, int month = 0, int year = 0);
	Date(const Date& obj);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setString(string str);
	int getDay();
	int getMonth();
	int getYear();
	bool check();
	void normalize();
	void increaseOne() override;
	void increaseTwo() override;
	void increaseThree() override;
	void daysToDate(int n);
	int DateToDays();
	bool highPitched();
	friend ostream& operator<< (ostream& out, const Date obj);
	friend Date operator- (Date left, int right);
	friend bool operator> (Date left, Date right);
	friend bool operator< (Date left, Date right);
	friend bool operator== (Date left, Date right);
	int daysBetweenDates(Date obj);
};