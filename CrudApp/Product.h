#pragma once
#include <string.h>
#include <iostream>
#include <string>
#include <iosfwd>
#include <fstream>
#include <vector>
#include <algorithm>
#include "HelperFunctions.h"

using namespace std;

class Product
{
	//class fields
public:
	std::string  name;
	std::string  date;
	std::string  measurement;
	int typecode;
	int checknumber;
	int price;
	int quantity;
	long int totalprice;

public:
	//class constructors
	//default constructor
	

	//custom constructor
	Product() {};
	Product(std::string Name, std::string Date, std::string Measurement, int Typecode, int Checknumber, int Price, int Quantity)
	{
		this->name = Name;
		this->date = Date;
		this->measurement = Measurement;
		this->typecode = Typecode;
		this->checknumber = Checknumber;
		this->price = Price;
		this->quantity = Quantity;
		this->totalprice=this->price*this->quantity;
	};

	//Class destructor
	~Product() {};

	//Custom getter methods
	string getName()
	{
		return this->name;
	}

	int price_getter()
	{
		return this->price;
	}

	int quantity_getter()
	{
		return this->quantity;
	}


	//overload of cin  operator for custom class for input
	friend std::istream& operator >> (std::istream& is, Product& p) 
	{
		
		is >> p.name >> p.date >> p.measurement >> p.typecode >> p.checknumber >> p.price >> p.quantity >> p.totalprice;
		p.totalprice = p.price*p.quantity;
		return is;
	}

	//overload of cout operator for custom class for output
	friend std::ostream& operator << (std::ostream& os, Product& p)
	{
		os << p.name << " " << p.typecode << " " << p.date << "  " << " " <<
			p.measurement << "  " << p.checknumber << "  " << p.price << "  " <<
			p.quantity << "  " << p.totalprice << " " << std::endl;
		return os;
	}

	//Input products from console to txt
	//Here we use vector
	void product_add()
	{
		int check = 1;
		//create vector of Products
		vector <Product> productlist;
		cout << "Input Data for Products you wish to add in format  as below" << endl;
		cout << "\nName Date Measurement TypeCode CheckNumber Price Quantity" << endl;
		while (check != 0)
		{
			//Read our Products
			Product prdct;
			cin >> prdct;

			//Check if our product values of strings doesn't contain numbers and numbers are greater then zero
			if (prdct.typecode > 0 && prdct.checknumber > 0 && prdct.price > 0 && prdct.quantity > 0 && prdct.totalprice > 0
				&& !has_any_digits(prdct.name))
				//put in vector products if values satisfy our condition
				//numbers must be >0 and name must not contain any numbers
			{
				productlist.push_back(prdct); 

				cout << "Added" << prdct.getName() << "successfully" << std::endl;
			}
			// if values don't meet our checking we print error message 
			else { cout << "Please use numbers for name and numbers should be positive " << endl; }
			//continue console input marker
			std::cout << "Continue input?\n1 - yes\t0 - no\n" << endl;
			std::cin >> check;
		}

		// We write to file only after input is finished in append mode, so we add new data
		ofstream outputFile("Data/productlist.txt", ios::app);
		//output data from vector into file
		for (auto f : productlist)
		{
			outputFile << f << endl;
		}
		cout << "Writing values to file..." << std::endl;
		//clearing our collections
		productlist.clear();
	}

	// Display products from txt to console
	//here we don't use any data structures and read line by line from file
	void product_display()
	{
		string line;
		int checker = 1;
		while (checker != 0)
		{
			std::ifstream inFile("Data/productlist.txt");
			if (!inFile.is_open())
			{
				std::cout << "Can't open file";
				exit(1);
			}
			cout << "\nProduct data: ";

			cout << "\n|Name| Type| Date| Measurement  | CheckNumber  | Price| Quantity  |TotalPrice   |" << std::endl;
			cout << "\n______________________________________________________________________________|" << std::endl;

			while (getline(inFile, line))
			{
				cout << line << endl;
			}
			//closing file 
			inFile.close();
			//check if continue output
			cout << "\n\nContinue output?\n1 - yes\t0 - no\n";
			cin >> checker;

		}
	}


	//here we use vector to store names to be deleted
	//and also we use map with Names as Keys and Products as values
	void product_delete()
	{
		int checker = 5;
		std::ifstream inFile("Data/productlist.txt");
		std::string path = "Data/productlist.txt";
		std::vector<string> names_to_remove;
		std::vector<Product> products_after_delete;
		std::map<std::string, Product> map_of_current_products;
		//Read into our map current values from file

		
		while (!inFile.eof())
		{
			std::string temp;
			Product prod;
			inFile >> prod;
			temp = prod.getName();
			//put our Name as Key Product as Value into map 
			map_of_current_products.insert(std::make_pair(temp, prod));
		}
		

		//Read names of products we need to remove into vector
		while (checker != 0)
		{
			std::string names;
			cout << "Put here names of products to remove" << std::endl;
			cin >> names;
			//checking for certain conditions  name doesn't contain digits
			//if  //(!has_any_digits(names))
			//{
				//if so we push it into vecor of values to be removed
				names_to_remove.push_back(names);

			//}

			//else { cout << "\n Name can't can't containt numbers" << std::endl; }
			cout << "\n\nContinue edit?\n1 - yes \t 0 - no\n";
			cin >> checker;
		}
		//loop through vector  and remove object from set if it has such keys		 
		for (auto& products : map_of_current_products)

			for (const auto& names : names_to_remove)

			{
				//remove from vector if our condition is met
				if (names == products.first)
				{
					//we delete map element if it key is same as in our vector to remove
					cout << "Deleted" << names << "from data" << std::endl;
					map_of_current_products.erase(names);

				}
			}
		inFile.close();
		std::ofstream outputFile("Data/productlist.txt");
		//Push our renewed map values into vector of values 
		for (const auto maps : map_of_current_products)
		{
		     products_after_delete.push_back(maps.second);
		}

		//output into file our renewed vector values
		for (auto resultvector : products_after_delete)
		{
			outputFile << resultvector << endl;
		}

		//closing file
		outputFile.close();
		//cleaning our Collection
		names_to_remove.clear();
		map_of_current_products.clear();
		products_after_delete.clear();
	}



	//Here we use Map and Vector for edit
  
	void product_edit()
  {
	   int checker = 1;
	   // loop while checker value not equals 0
	
		std::ifstream inFile("Data/productlist.txt");
		std::map<std::string, Product> map_of_current_values;
		std::vector <Product> current_prod;
		string temp_name;
//		int temp_number;
		//std::map<std::string, Product> map_of_values_to_update; 
		//std::vector <Product> products_to_update;
		//inFile.close();

		//if we couldn't open file we output error and exit
        

		inFile.close();
		
		// read file into map of current values

		while (!inFile.eof())
		{
			std::string temp;
			Product prod;
			inFile >> prod;
			temp = prod.getName();
			map_of_current_values.insert(std::make_pair(temp, prod));
			
		}
		inFile.close();
		
		do
		{	//Read Name of the Product we wish to edit
			cout << "Please enter Name of the Product you wish to edit" << endl;
			cin >> temp_name;
			//Read Number of the Product we wish to edit
			//cout << "Please enter Check number of the Product you wish to edit" << endl;
			//cin >> temp_number;

			//Check if name exists in our map

			if (map_of_current_values.count(temp_name) > 0)
				//checking if there is at least one such name in our map of keys and values

			{
				std::cout << "Number and Name found \n Now input Product information what you want to change" << endl;
				Product pr;
				//read our values of the product class
				cin >> pr;
				//check if input satisfies our conditions , string doesn't contain numbers, numbers greater then zero
				if (pr.typecode > 0 && pr.checknumber > 0 && pr.price > 0 && pr.quantity > 0 && pr.totalprice > 0
					&& !has_any_digits(pr.name))
				{
					//loop through our map and update product values if we found it 
					for (auto map_iter : map_of_current_values)
					{
						if (map_iter.second.getName() == temp_name)
							//if we find object that has same name as input for edit
						{
							//change it values to our input
							map_iter.second = pr;
							cout << "Changed  value of the shop" << temp_name << "sucsessfully" << std::endl;
						}

					}
					//open file for updating edited value
					std::ofstream outputFile("Data/productlist.txt");
					//Push our renewed map values into vector of values 
					for (const auto maps : map_of_current_values)
					{
						current_prod.push_back(maps.second);
					}

					//output into file our renewed vector values
					for (auto resultvector : current_prod)
					{
						outputFile << resultvector << endl;
					}
					//closing file
					outputFile.close();
				}
				else
				{
					cout << "Enter correct format numbers should be higher then zero and name shouldn't contain any digits" << endl;
				}
			}

			// if we didn't find name and number in our vector
			else { cout << "Sorry but this Number and this Name aren't found in the file " << endl; }

			//clearing our collections
			current_prod.clear();
			map_of_current_values.clear();
			cout << "\n\nContinue edit?\n1 - yes \t 0 - no\n";
			cin >> checker;
		} while (checker != 0);

  }
	
};