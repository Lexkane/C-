#include<string>
#include <iostream>
#include<fstream>
#include <iosfwd>
#include "stdafx.h"
class Product
{
public:
	std::string name;
	std::string  date;
	std::string  measurement;
	int typecode;
	int checknumber;
	int price;
	int quantity;
	int totalprice;

public:
	Product(){};
	Product(std::string Name, std::string Date, std::string Measurement, int Typecode, int Checknumber, int Price, int Quantity, int TotalPrice){
		this->name = Name;
		this->date = Date;
		this->measurement = Measurement;
		this->typecode = Typecode;
		this->checknumber = Checknumber;
		this->price = Price;
		this->quantity = Quantity;
		this->totalprice = TotalPrice;
	};

	~Product(){};

	friend std::istream& operator >> (std::istream& is, Product& p) {
		is >> p.name >> p.date >> p.measurement >> p.typecode >> p.checknumber >> p.price >> p.quantity >> p.totalprice;
		return is;
	}

	friend std::ostream& operator << (std::ostream& os, Product& p) {
		os << "Name " << " " << p.name << " " << "Type " << p.typecode << " " << "Date " << p.date << "  " << "Measurement " <<
			"  " << p.measurement << "  " << "Checknumber " << "  " << p.checknumber << "  " << "Price " << "  " << p.price <<
			"  " << "Quantity " <<"  "<< p.quantity <<"  "<< "TotalPrice "<<"  "<< p.totalprice << ", " << std::endl;
		return os;
	}


	
};

