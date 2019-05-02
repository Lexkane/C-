// CrudApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "pch.h"
#include <iostream>
#include "Shop.h"

using namespace std;
int main()
{
	Shop *sh = new Shop();
	int option = 1;
	cout << "Shop info:";
	cout << "\n0 - Back to menu";
	cout << "\n1 - Add shop";
	cout << "\n2 - Edit shop";
	cout << "\n3 - Delete shop";
	cout << "\n4 - Display shops\n";
	cin >> option;
	switch (option)
	{
	case 0: exit(0); 
	case 1:sh->shop_add(); 
	case 2:sh->shop_edit(); 
	case 3:sh->shop_delete(); 
	case 4:sh->shop_display(); 
	default:break;
	}
	
	delete sh;
    return 0; 
}
