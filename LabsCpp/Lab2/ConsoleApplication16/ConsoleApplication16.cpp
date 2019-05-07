// ConsoleApplication16.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int main()
{
	ofstream outfile("Text.txt");

	if (!outfile)
	{
		cout<<"Error";
		_getch();
		return -1;
	}
	cout << "Enter your HDD:";
	char str[100];
	cin.get();
	cin.getline(str, 100);
	
	int per, v;
	cout << "\nEnter percent:";
	cin >> per;
	cout << "\nEnter extent in GB:";
	cin >> v;
	long long int p;
	p = (v*per);
	outfile << "Your HDD:" << str << endl;
	outfile << "Your Extent:" << v << endl;
	outfile << "Occupied space in bytes:" <<p*1024*1024*1024 << endl;

	outfile.close();

	_getch();
    return 0;
}

