#include "npstdlib.h"

int np_min(int number, int numberTwo)
{
	if (number < numberTwo) {
		return number;
	}
	else {
		return numberTwo;
	}
	return number;
}

int np_max(int number, int numberTwo)
{
	if (number > numberTwo) {
		return number;
	}
	else {
		return numberTwo;
	}
	return number;
}
