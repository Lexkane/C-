// Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 

using namespace std;

void vector_counter (vector<int>&q)
{
	int counter = 0;
	for (auto a : q) {
		if (a==true)
		{
			counter += 1;
		}
	}
	cout << counter;

}

void string_parser (string &s,int &i, vector<int> &q )
{
	
	if (s == "WORRY")

	{
		q[i] = 1;

	}

	if (s == "QUIET")
	{
		q[i] = 0;
	}

	if (s == "COME")
	{
			if (i > 0)
			{ 
				for (int j=i;j>0;--j)
				{
					q.push_back(0);
				}

				//vector < int> temp;
				//temp.assign(0, i);
				//q.insert(
					//q.end(),
					//temp.begin(),
					//temp.end())
				//);
				
				//q.insert(q.end(), temp.begin(), temp.end());
				//q.push_back(temp);
				//std::copy(temp.begin(), temp.end(), std::back_inserter(q));
				//temp.clear();
				//for (int j = 0; j <= i; j++)
				//{q.push_back(0);}
			}

			if (i < 0)
			{
				//for (int i = 0; i < abs(token2); i++)
				//{	q.pop_back();}
				q.erase(q.end() + i, q.end());
			}
	}
}

int main()
{
	int number;
	cin >> number;
	vector <int> queue;
	//queue.assign(0, 0);

	for (int i=0;i<number;i++)
	{
		
		string s;
		cin >> s;

		if (s != "WORRY_COUNT")
		{
			int command;
			cin >> command;
			string_parser(s,command, queue);
		}

		if (s == "WORRY_COUNT")
		{
			vector_counter(queue);
		}
	}

	return (0);
}
