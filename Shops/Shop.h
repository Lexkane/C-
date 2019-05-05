#include<string.h>
#include <iostream>
#include <string>
#include <iosfwd>
#include <fstream>
#include "stdafx.h"
class Shop
{
public:
	std::string name;
	int number;

public:
	Shop(){};
	Shop(std::string Name, int Number){
		this->name = Name;
		this->number = Number;
	};
	~Shop(){};

	friend std::istream& operator >> (std::istream& is, Shop& s) {
		is >> s.name >> s.number;
		return is;
	}

	friend std::ostream& operator << (std::ostream& os, Shop& s) {
		os << "Name " << s.name << " ShopNumber " << s.number << ","<<std::endl;
		return os;
	}
	

	
};