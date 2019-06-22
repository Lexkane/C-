// PalindromFilter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string s)
{
	for (size_t i = 0; i < s.size() / 2; ++i)
	{
		if (s[i] != s[s.size() - i - 1])
		{
			return false;
		}
	}
	return true;
}


vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector <string>result;

	
	for (  auto& w: words)
	{
		if (IsPalindrom(w) && w.length() > minLength)
		{
			result.emplace_back(w);
		}
	}
	return result;
}

int main()
{  
   
    std::cout << "Hello World!\n"; 
}
