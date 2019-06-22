// VectorReverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <vector>
#include <iostream>
using namespace std;

void Reverse(vector<int> &vec)
{
	vector<int> temp;
	int a;
	for ( i = vec.size()-1; i >= 0; i--) // if i>=0 segmentation error
	{
		a = vec[i];
		temp.push_back(a);
	}

	vec.clear();
	vec = temp;
	temp.clear();
}
int main()
{
	vector<int> numbers = { 1, 5, 3, 4, 2 };
	Reverse(numbers);

	for (auto &v : numbers)
	{
		cout << v << " ";
	}
	system("pause");
	return (0);
}
