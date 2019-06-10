#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>
#include <ctime>
#include <queue>
#include "Pixel.h"
#include "Triangle.h"

using namespace std;

bool sort_square(Triangle t1,Triangle t2)
{
	return (t1.get_square()<t2.get_square());
}

bool sort_square_colour(Triangle t1,Triangle t2)
{
	return ((t1.get_square()<t2.get_square())&&(t1<t2));
}

template<typename T>
class Command
{
public:
	virtual void execute(T&)=0;
};

template<typename T>
class Sort_Colour:public Command<T>
{
public:
	virtual void execute(T& t)
	{
		sort(t.begin(),t.end());
	}
};

template<typename T>
class Sort_Square:public Command<T>
{
public:
	virtual void execute(T& t)
	{
		sort(t.begin(),t.end(),sort_square);
	}
};

template<typename T>
class Sort_Square_Colour:public Command<T>
{
public:
	virtual void execute(T& t)
	{
		sort(t.begin(),t.end(),sort_square_colour);
	}
};

template<typename T>
class Unique_Colour:public Command<T>
{
public:
	virtual void execute(T& t)
	{
		sort(t.begin(),t.end());
		unique(t.begin(),t.end());
	}
};

int main()
{
	srand(time(NULL));
	vector<Pixel> p;
	generate_n(back_inserter(p),4,gen_pixel);
	copy(p.begin(),p.end(),ostream_iterator<Pixel>(cout));
	vector<Triangle> t;
	for(unsigned i=0;i<p.size();i++)
		for(unsigned j=0;j<p.size();j++)
			for(unsigned k=0;k<p.size();k++)
				if((p[i]!=p[j])&&(p[j]!=p[k])&&(p[i]!=p[k]))
					t.push_back(Triangle(p[i],p[j],p[k]));
					
	copy(t.begin(),t.end(),ostream_iterator<Triangle>(cout));
	priority_queue<Command<vector<Triangle>>*> c;
	c.push(new Sort_Colour<vector<Triangle>>);
	c.push(new Sort_Square<vector<Triangle>>);
	c.push(new Sort_Square_Colour<vector<Triangle>>);
	c.push(new Unique_Colour<vector<Triangle>>);
	c.top()->execute(t);
	c.pop();
	for(vector<Triangle>::iterator it4=t.begin();it4!=t.end();it4++)
	cout<<it4->get_colour_t()<<endl;
	c.top()->execute(t);
	c.pop();
	for(vector<Triangle>::iterator it4=t.begin();it4!=t.end();it4++)
	cout<<it4->get_square()<<endl;
	c.top()->execute(t);
	c.pop();
	for(vector<Triangle>::iterator it4=t.begin();it4!=t.end();it4++)
	cout<<it4->get_colour_t()<<" "<<it4->get_square()<<endl;
	c.top()->execute(t);
	c.pop();
	system("pause");
	return (0);
}

