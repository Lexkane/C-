#pragma once
#include<iostream>
#include <cmath>


class Pixel
{
protected:
	int x;
	int y;
	int colour;
public:
	Pixel():x(0),y(0),colour(0){}
	Pixel(int xx,int yy,int c):x(xx),y(yy),colour(c){}
	Pixel(const Pixel& p):x(p.x),y(p.y),colour(p.colour){}
	int get_x() const {return x;}
	int get_y() const {return y;}
	int get_colour() const {return colour;}
	bool operator==(const Pixel& p) const
	{
		return ((x==p.x)&&(y==p.y)&&(colour==p.colour));
	}
	bool operator!=(const Pixel& p) const
	{
		return ((x!=p.x)&&(y!=p.y));
	}
	friend std::istream& operator>>(std::istream& is,Pixel& p)
	{
		is>>p.x>>p.y>>p.colour;
		return is;
	}
	friend std::ostream& operator<<(std::ostream& os,const Pixel& p)
	{
		os<<"("<<p.x<<","<<p.y<<") "<<p.colour<<std::endl;
		return os;
	}
};

Pixel gen_pixel()
{
	int x = rand()%100;
	int y = rand()%100;
	int c = rand()%3;
	return Pixel(x,y,c);
}

double vidstan(Pixel& p1,Pixel& p2)
{
	return std::sqrt(double((p2.get_x()-p1.get_x())*(p2.get_x()-p1.get_x())+(p2.get_y()-p1.get_y())*(p2.get_y()-p1.get_y())) );
}

double perimetr(Pixel p1,Pixel p2,Pixel p3)
{
	return (vidstan(p1,p2)+vidstan(p2,p3)+vidstan(p1,p3));
}

double square(Pixel p1,Pixel p2,Pixel p3)
{
	double p = perimetr(p1,p2,p3)/2;
	return std::sqrt(p*(p-vidstan(p1,p2))*(p-vidstan(p2,p3))*(p-vidstan(p1,p3)));
}
