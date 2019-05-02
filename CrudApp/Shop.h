#pragma once
#include<string.h>
#include <iostream>
#include <string>
#include <iosfwd>
#include <fstream>
#include <vector>
#include "HelperFunctions.h"

using namespace std;
class Shop
{
//class attributes
public:
	std::string name;
	int number;


public:
	//class default constructor
	//class custom constructor
	/*Shop(std::string Name, int Number){
		this->name = Name;
		this->number = Number;
	};

	*/

	Shop() {};

	Shop(const string& Name, const int& Number)
		: name(Name),
		  number(Number)
	{}
	~Shop(){};
	//class methods
	//class getter
	string getName()
	{
		return this->name;
	}
	//overloading of istream for class
	
	friend std::istream& operator >> (std::istream& is, Shop& s) 
	{
		is >> s.name >>s.number;
		return is;
	}
	

	/*
	friend istream& operator>>(istream& is, Shop &sh)
	{
		getline(is, sh.name);
		getline(is, sh.number);
		

		
		
		return is;
	}

	*/

	//overloading of the ostream for class
	friend std::ostream& operator << (std::ostream& os, Shop& s)
	{
		os << s.name << " " << s.number << std::endl;
		return os;
	}

	//input add data function for class

	void shop_add()
	{
		int check = 1;
		
		vector <Shop> shoplist;
		cout << "Input Data for Shops you wish to add in format as below" << endl;
		cout << "\nPlease Input  Shop Name  and Shop Number" << endl;
			do
			{
				Shop shop;
				cin >>shop;
				// here we check if name doesn't contain any numbers and if number are greater then 0
				if (shop.number>0 && !has_any_digits(shop.name))

				{
					shoplist.push_back(shop);
					cout << "Added" << shop.getName() << "successfully"<<std::endl;
				}
				else { cout << "Enter shop data in correct format" << endl; }
				cout << "Continue input?\n1 - yes\t0 - no\n" << endl;
				cin >> check;
			} while (check != 0);

		cout << "Writing values to file..." << std::endl;
		//open file in append mode to add new data
		ofstream outputFile("Data/shoplist.txt",ios::app);
		for (auto f : shoplist)
		{
			outputFile << f;
		}
		//clearing our collections
		shoplist.clear();


	}

   	void shop_display()
	{
		string line;
		int checker=1;
		while (checker != 0)
		{
			std::ifstream inFile("Data/shoplist.txt");
			//if (!inFile.is_open()) {
				//std::cout << "Can't open file";
				//exit(1);
			//}

			cout << "\nShop data: " << std::endl;
			cout << "\n|Name      | Number     |" << std::endl;
			cout << "\n|_______________________|" << std::endl;
			while (getline(inFile, line))
			{
				cout << line << endl;
			}

			cout << "\n\nContinue output?\n1 - yes\t0 - no\n";
			cin >> checker;
			inFile.close();
		}

	}

	
	//Here we use vectors and map structures
	void shop_delete()
	{
		int checker = 1;
		std::string names;
		std::ifstream inFile("Data/shoplist.txt");
		std::string path = "Data/shoplist.txt";
		std::vector<string> names_to_remove;
		std::vector<Shop> products_after_delete;
		//Read names of shops we need to remove into vector
		while (checker != 0)
		{
			cout << "Put here names of shops to remove" << std::endl;
			cin >> names;
			//checking for certain conditions  name doesn't contain digits
			if (!has_any_digits(names))
			{
				//pushing names we should remove into vector
				cout << "Name is valid"<<std::endl;
				//names_to_remove.push_back(names);
				//cout << "Added" << names << "to the remove list" << std::endl;
			}

			else { cout << "\n Name can't can't contain numbers" << std::endl;}

			cout << "\n\nContinue delete?\n1 - yes \t 0 - no\n";
			cin >> checker;
		}
			
			//Read into our map current values
			std::map<std::string, Shop> map_of_current_shops;
			while (!inFile.eof())
			{
				std::string temp;
				Shop sh;
				inFile >> sh;
				temp = sh.getName();
				//put Name,Shop pairs into our map
				map_of_current_shops.insert(std::make_pair(temp, sh));
			}
			//closing file
			inFile.close();
			//loop through vector  and remove object from set if it has such keys		 
			for (auto& shops : map_of_current_shops)

				for (const auto& names : names_to_remove)

				{
					//remove from map if our condition is met
					if (names == shops.first)
					{
						//we delete map element if it key is same as in our vector to remove
						cout << "Deleted" << names << "from data" << std::endl;
						map_of_current_shops.erase(names);

					}
				}
			std::ofstream outputFile("Data/shoplist.txt");
			//Push our renewed map values into vector of shops values 
			for (const auto maps : map_of_current_shops)
			{
				products_after_delete.push_back(maps.second);
			}

			//output into file our renewed vector of shop values
			for (auto resultvector : products_after_delete)
			{
				outputFile << resultvector << endl;
			}


		//closing file
		outputFile.close();
		//cleaning our Collections
		names_to_remove.clear();
		map_of_current_shops.clear();
		products_after_delete.clear();

	}


	//Here we used vector and map
	void shop_edit()
	{
		int checker = 1;
		// loop while checker value not equals 0
		while (checker != 0)

		{

			string tempstr;

			std::vector<pair<string, Shop>> shop_vect;
			//std::ifstream ShopFile("shoptlist.txt");
			string path = "Data\shoplist.txt";
					
			read_file_to_vector(shop_vect, path);
			cout<< "Enter element to find";
			cin >> tempstr;

			for (auto &[key,value] : shop_vect)
			{
				if ( key == tempstr)
				{
					cout << "Found product " << value << endl;
				}
			}



			/*
			{
				for (auto &vec : current_shop)
				{
					cout << vec.getName() << endl;
				}


			*/
			//Check if name exists in our map

			//if (map_of_current_shops.count(temp_name) > 0)
				//checking if there is at least one such name in our map of keys and values

			//clearing our collections
			//current_shop.clear();

			cout << "\n\nContinue edit?\n1 - yes \t 0 - no\n";
			cin >> checker;

		
		}

	}

};