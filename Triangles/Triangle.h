#pragma once
#include <iostream>
#include <cmath>
#include "Pixel.h"


class Triangle
{
protected:
	Pixel p1;
	Pixel p2;
	Pixel p3;
public:
	Triangle():p1(),p2(),p3(){}
	Triangle(Pixel pp1,Pixel pp2,Pixel pp3):p1(pp1),p2(pp2),p3(pp3){}
	Triangle(const Triangle& t):p1(t.p1),p2(t.p2),p3(t.p3){}
	double get_square() const {return square(p1,p2,p3);}
	double get_colour_t() const {return (p1.get_colour()+p2.get_colour()+p3.get_colour());}
	bool operator<(const Triangle t) const
	{
		return (*this).get_colour_t()<t.get_colour_t();
	}
	bool operator==(const Triangle t) const
	{
		return (*this).get_colour_t()==t.get_colour_t();
	}
	friend std::istream& operator>> (std::istream& is,Triangle t)
	{
		is>>t.p1>>t.p2>>t.p3;
		return is;
	}
	friend std::ostream& operator<<(std::ostream& os,const Triangle t)
	{
		os<<"A: "<<t.p1;
		os<<"B: "<<t.p2;
		os<<"C: "<<t.p3;
		os<<std::endl;
		return os;
	}
};
