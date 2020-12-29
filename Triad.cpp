#include "Triad.h"
#include <iostream>
using namespace std;

Triad::Triad(int _one, int _two, int _three) : one(_one), two(_two), three(_three) {}

Triad::Triad(const Triad& obj) {
	this->one = obj.one;
	this->two = obj.two;
	this->three = obj.three;
}

void Triad::increaseOne() {}

void Triad::increaseTwo() {}

void Triad::increaseThree() {}