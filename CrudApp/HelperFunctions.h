#pragma once
#include <string>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>
#include <iostream>

using namespace std;

//Validator functions
//__________________________________________________________________________________
//function to check if input string  contains any digits
bool has_any_digits(const std::string& s)
{
	return std::any_of(s.begin(), s.end(), ::isdigit);
}

//function to check if our number is greater then zero
bool is_greater_then_zero(const int &i)
{
	return  i>=0 ? true : false;
}

//function to check if our number is less then 9999 (four digit max)
bool is_four_digit(const int&i)
{
	return i <= 9999 ? true : false;
}

//Templates
//____________________________________________________________________________________________
//template Iterator for copy
template<class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result)
{
	while (first != last) {
		*result = *first;
		++result; ++first;
	}
	return result;
}

//-------------------------------------------------------------------------------------------------------//
//template to read from file into map with Key as string Names and Values as our custom class values 
 /*template<typename T>
 void read_file_into_map( std::map<std::string, T> &map, std::string &path)
{
	while (!inFile.eof())
	{
		std::string temp;
		T p;
		std::string temp;
		file >> p;
		temp = p.getName();
		map.insert(std::make_pair(temp, p));
	}
	file.close();
}

//Template for custom class output
*/
 
/*
	 template <class T1, class T2>
	std{ std::ostream& operator <<(std::ostream& out, std::pair< T1, T2>& rhs)
	 {
		 out << "first: " << rhs.first << " second: " << rhs.second;
		 return out;
	 }
    }
 */
 
/*
template <typename T,typename S>
std::ostream & operator <<(std::ostream &os, std::map < std::pair<S,T> > &m)
{
	for (const auto &p : m)
	{
		os << p.first << ": ";
		for (int x : p.second) os << x << ' ';
		os << std::endl;
	}
	return os;
}

*/

/*
template <typename T, typename S>
std::ostream & operator << (std::ostream &os, std::map<const std::pair <S,T>> &m)
{
	for (const auto &p : m)
	{
		os << p.first << " ";
		for (auto &x : p.second)
		{
			os << x << std::endl;
		}
		
	}
	return os;
} */

/*
 namespace custom{
template <typename Arg>
  std::istream& operator >> (std::istream& is, Arg&& arg)
{
	is>> std::forward<Arg>(arg);
	
	return is;
}
  }
 */

/*
template<typename T>

void read_file_to_the_vector( std::ifstream &file, std::vector<T>& data)
{


	if (file.is_open()) {

		while (!file.eof())
		{

			T s;
			file >> s;
			std::string temp;
			temp = s.name;
			data.push_back(make_pair(temp,s));

		}
	}

	else {std::cout << "Error";}

	file.close();

	
}

*/
/*	 template <typename T,typename S>
 void  from_file_to_map (std::ifstream &file, std::map<S,T> &m)
 {
	 
		 while (!file.eof())
		 {
			 T a;
			 file >> a;
			 S temp = a.getName();
			m.insert(std::make_pair(temp, a));
		 }
	
	 
 }

 */
 template<typename T>
void read_file_to_vector(vector<pair<string,T>>& data, string &filename) 
{

ifstream fin(filename);


while (!fin.eof()) 
{
	pair<string, T> temp;
	T s;
	fin >> s;
	temp.first = s.name;
	temp.second = s;
	data.emplace_back(temp);
	


}

fin.close();
}
 
 /*
 template <typename T>
 void from_file_to_vector(std::ifstream &file, std::vector< std::pair<std::string, T>> &m)
 {
	 if (file.is_open())
	 {
		 while (!file.eof())
		 {
			 T a;
			 file >> a;
			 std::string temp = a.getName();
			 m.emplace(std::make_pair(temp, a));
		 }
	 }
	 file.close();
 }
 */

/*
 template<typename Pred>
 void read_into_set( std::multiset<Product, Shop>& ps, const string& str)
 {
	 ifstream fin(str);
	 if (fin.is_open())
	 {
		 while (!fin.eof())
		 {
			 Event ev;
			 fin >> ev;
			 ps.insert(ev);
		 }
	 }
	 fin.close();
 }

 */
 /*
 
 template <typename T>
  std::vector<T> read_file_into_vector(std::string &file_name, std::vector<T> &vec)
 {   std::vector<T> result;
	 std::ifstream file(file_name);
	 std::copy(std::istream_iterator<T>(file), std::istream_iterator<T>(), std::back_inserter(result));
	 return result;
  };
 
  */
  





 // read file into map of current values
//for (std::vector<Shops>::const_iterator i = path.begin(); i != path.end(); ++i)
//std::cout << *i << ' ';

//std::copy(input_iterator<Shop>(file), input_iterator<Shop>(), std::back_inserter(data));