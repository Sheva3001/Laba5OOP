#pragma once
#include <iostream>
using namespace std;

class Triad {
protected:
	int one, two, three;
public:
	Triad(int _one = 0, int _two = 0, int _three = 0);
	Triad(const Triad& obj);
	virtual void increaseOne()=0;
	virtual void increaseTwo()=0;
	virtual void increaseThree()=0;
};