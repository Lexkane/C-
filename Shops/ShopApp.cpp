// ShopApp.cpp : main project file.
#pragma once
//include "stdafx.h"
#include"Product.h"
#include"Shop.h"
#include <vector>
#include <string>


using namespace std;

void shop_input()
{
	int check = 1;
	Shop shop;
	vector <Shop> shoplist;
	cout <<" Please Input Name  ShopNumber" << endl;
	do
	{
		cin>>(shop);
		shoplist.push_back(shop);
		cout << "Continue input?\n1 - yes\t0 - no\n" << endl;
		cin >> check;
	} while (check != 0);

	ofstream outputFile("Data/shoplist.txt");
	//outputFile << "This is ShopList"<<endl;
	for (auto f : shoplist)
	{  outputFile << f; }


}


void product_input()
{
	int check = 1;
	vector <Product> productlist;
	cout << "Please Input Name Date Measurement TypeCode CheckNumber Price Quantity TotalPrice" << endl;
	do
	{
		Product product;
		cin >> product;
		productlist.push_back(product);
		cout << "Continue input?\n1 - yes\t0 - no\n" << endl;
		cin >> check;
	} while (check != 0);

		ofstream outputFile("Data/productlist.txt");
		//outputFile << "productlist";
		for (auto f : productlist)
		{  outputFile << f << endl;	}

}


void shop_display()
{
	string line;
	int checker;
	while (checker != 0)
	{
		std::ifstream inFile("Data/shoplist.txt");
		if (!inFile.is_open()) {
			std::cout << "Can't open file";
			exit(1);
		}

		cout << "\nShop data: ";
		cout << "\n________________________";
		cout << "\n|Name      | Number     |";
		cout << "\n|__________|____________|" << endl;
		while (getline(inFile, line))
		{
			cout << line << endl;
		}

		cout << "\n\nContinue output?\n1 - yes\t0 - no\n";
		cin >> checker;
		inFile.close();
	}

}
	void product_display()
	{
		string line;
		int checker;
		while (checker != 0)
		{
			std::ifstream inFile("Data/productlist.txt");
			if (!inFile.is_open())
			{
				std::cout << "Can't open file";
				exit(1);
			}
			cout << "\nProduct data: ";
			cout << "\n________________________________________________________________________________________________________________";
			cout << "\n|Name      | Type       | Date       | Measurement  | CheckNumber  | Price            | Quantity  |TotalPrice   |";
			cout << "\n|__________|____________|____________|______________|______________|__________________|___________|_____________|"<<endl;

			while (getline(inFile, line))
			{
				cout << line << endl;
			}

			cout << "\n\nContinue output?\n1 - yes\t0 - no\n";
			cin >> checker;
			inFile.close();


		}
	}



	int main()	{
		int choice;
	menu:
		do
		{
			system("cls");
			cout << "Menu:";
			cout << "\n0 - Exit";
			cout << "\n1 - Shop info";
			cout << "\n2 - Product info\n";
			cin >> choice;


			while (choice != 0){

				if (choice == 0)
				{
					exit(1);
				}
				if (choice == 1)
				{
					goto shop_info;
				}

				if (choice == 2)
				{
					goto product_info;
				}

				else {
					break;
				}

			}


		shop_info:
			while (choice != 0)
			{
				//system("cls");
				cout << "Shop info:";
				cout << "\n0 - Back to menu";
				cout << "\n1 - Add shop";
				cout << "\n2 - Edit shop";
				cout << "\n3 - Delete shop";
				cout << "\n4 - Display shops\n";
				cin >> choice;

				if (choice == 0)
				{
					goto menu;
				}
				if (choice == 1)
				{
					shop_input(); break;
				}

				if (choice == 2)
				{
					continue;
				}

				if (choice == 4)
				{
				 shop_display(); break;

				}

				else {
					break;
				}

			}

		product_info:
			while (choice != 0)
			{
				//system("cls");
				cout << " Input Product info:";
				cout << "\n0 - Back to menu";
				cout << "\n1 - Add product";
				cout << "\n2 - Edit product";
				cout << "\n3 - Delete product";
				cout << "\n4 - Display products \n";
				cin >> choice;



				if (choice == 0)
				{
					goto menu;
				}
				if (choice == 1)
				{
					product_input(); break;
				}

				if (choice == 2)
				{
					continue;
				}
				if (choice == 4)
				{
					product_display(); break;

				}

				else {
					break;
				}

			}
		} while (choice != 0);

		return 0;
}








