#pragma once
#include "pch.h"
#include <iostream>
#include <cmath>


using namespace std;

int main(int argc, char **argv) 
{
	double a, b, c, x1, x2, d;
	cin >> a >> b >> c;
	d = b*b - 4 * a*c;

	if (a != 0 && d > 0)
	{
		x1 = (-b + (sqrt(d))) / (2 * a);
		x2 = (-b - (sqrt(d))) / (2 * a);
		cout << x1 << " " << x2;
	}

	if (a != 0 && d == 0)
	{
		x1 = -b / (2 * a);
		cout << x1;
	}

	if (a == 0)
	{
		x1 = -c / b;
		cout << x1;

	}
	if ( d < 0)
	{
		cout << "No roots found";
	}

	

	return 0;
}
