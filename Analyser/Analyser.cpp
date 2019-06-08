#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <stack>
#include <math.h>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

void clear_str(string& str, char ch)
{
	string::iterator it;
	for(it = str.begin(); it != str.end(); it++)
		if (*it == ch) str.erase(it--);
	if(*(str.end()-1) != '=')
		str.push_back('=');
}
void replace_str(string& str)
{
	while( str.find("sin") != string::npos)
	{
		str.replace(str.find("sin"), 3, "$");
	}
	while( str.find("cos") != string::npos)
	{
		str.replace(str.find("cos"), 3, "#");
	}
	while( str.find("sqrt") != string::npos)
	{
		str.replace(str.find("sqrt"), 4, "&");
	}
	while( str.find("e") != string::npos)
	{
		str.replace(str.find("e"), 1, "2.718281828459045");
	}
	while( str.find("pi") != string::npos)
	{
		str.replace(str.find("pi"), 2, "3.1415");
	}
	for( int i = 0; i < str.size(); i++)
	{
		if(isalpha(str[i]))
		{
			string temp;
			temp += str[i];
			while(isalpha(str[i+1]))
			{
				temp += str[i+1];
				i++;
			}
			string arg;
			cin >> arg;
			while(str.find(temp) != string::npos)
				str.replace(str.find(temp), temp.size(), arg);
		}
	}
}

void trigonometrical(string &str)
{
	while ( str.find("sin") != string::npos )
	{
		string tmp;
		size_t found;
		found = str.find("sin");
		size_t first = found + 3;
		size_t second = str.find_first_of(')', first);
		string digit(str.begin()+first+1, str.begin() + first + (second - first));
		istringstream strin(digit);
		double alpha;
		strin >> alpha;
		double sinus = sin(alpha);
		ostringstream strout;
		strout.precision(3);
		strout << sinus;
		string result = strout.str();
		str.replace(str.begin() + found, str.begin() + second + 1, result.begin(), result.end());
	}

	while ( str.find("cos") != string::npos )
	{
		string tmp;
		size_t found;
		found = str.find("cos");
		size_t first = found + 3;
		size_t second = str.find_first_of(')', first);
		string digit(str.begin()+first+1, str.begin() + first + (second - first));
		istringstream strin(digit);
		double alpha;
		strin >> alpha;
		double sinus = cos(alpha);
		ostringstream strout;
		strout.precision(3);
		strout << sinus;
		string result = strout.str();
		str.replace(str.begin() + found, str.begin() + second + 1, result.begin(), result.end());
	}
}
string RPN(string str)
{
	stack <pair<char, unsigned>, vector< pair<char, unsigned> > > stk;
	string res;
	for( int i = 0; i < str.size(); i++)
	{



		if(isdigit(str[i]))
		{
			string temp;
			temp += str[i];
			//i++;
			while(isdigit(str[i+1]) || str[i+1] == '.' )
			{
				temp += str[i+1];
				i++ ;
			}
			res += temp;
			res += ' ';
		}
		else if( str[i] == '*')
		{
			pair<char, unsigned> p(str[i], 3);
			while(true)
			{
				if( stk.empty())
				{
					stk.push(p);
					break;
				}
				else
				{
					bool flag = true;
						if(stk.top().second >= p.second)
							flag = false;
					if (flag)
					{
						stk.push(p);
						break;
					}
					else
					{
						while(!stk.empty() && stk.top().second >= p.second)
						{
							res += stk.top().first;
							res += ' ';
							stk.pop();
						}
						continue;
					}
				}
			}
		}


		else if( str[i] == '/')
		{
			pair<char, unsigned> p(str[i], 3);
			while(true)
			{
				if( stk.empty())
				{
					stk.push(p);
					break;
				}
				else
				{
					bool flag = true;
						if(stk.top().second >= p.second)
							flag = false;
					if (flag)
					{
						stk.push(p);
						break;
					}
					else
					{
						while(!stk.empty() && stk.top().second >= p.second)
						{
							res += stk.top().first;
							res += ' ';
							stk.pop();
						}
						continue;
					}
				}
			}
		}


		else if( str[i] == '^')
		{
			pair<char, unsigned> p(str[i], 5);
			while(true)
			{
				if( stk.empty())
				{
					stk.push(p);
					break;
				}
				else
				{
					bool flag = true;
						if(stk.top().second >= p.second)
							flag = false;
					if (flag)
					{
						stk.push(p);
						break;
					}
					else
					{
						while(!stk.empty() && stk.top().second >= p.second)
						{
							res += stk.top().first;
							res += ' ';
							stk.pop();
						}
						continue;
					}
				}
			}
		}

		else if( str[i] == '+')
		{
			pair<char, unsigned> p(str[i], 2);
			while(true)
			{
				if( stk.empty())
				{
					stk.push(p);
					break;
				}
				else
				{
					bool flag = true;
						if(stk.top().second >= p.second)
							flag = false;
					if (flag)
					{
						stk.push(p);
						break;
					}
					else
					{
						while(!stk.empty() && stk.top().second >= p.second)
						{
							res += stk.top().first;
							res += ' ';
							stk.pop();
						}
						continue;
					}
				}
			}
		}

		else if( str[i] == '-')
		{
			pair<char, unsigned> p(str[i], 2);
			while(true)
			{
				if( stk.empty())
				{
					stk.push(p);
					break;
				}
				else
				{
					bool flag = true;
						if(stk.top().second >= p.second)
							flag = false;
					if (flag)
					{
						stk.push(p);
						break;
					}
					else
					{
						while(!stk.empty() && stk.top().second >= p.second)
						{
							res += stk.top().first;
							res += ' ';
							stk.pop();
						}
						continue;
					}
				}
			}
		}


		else if( str[i] == '`')
		{
			pair<char, unsigned> p(str[i], 4);
			while(true)
			{
				if( stk.empty())
				{
					stk.push(p);
					break;
				}
				else
				{
					bool flag = true;
						if(stk.top().second >= p.second)
							flag = false;
					if (flag)
					{
						stk.push(p);
						break;
					}
					else
					{
						while(!stk.empty() && stk.top().second >= p.second)
						{
							res += stk.top().first;
							res += ' ';
							stk.pop();
						}
						continue;
					}
				}
			}
		}

		else if( str[i] == '$')
		{
			pair<char, unsigned> p(str[i], 6);
			while(true)
			{
				if( stk.empty())
				{
					stk.push(p);
					break;
				}
				else
				{
					bool flag = true;
						if(stk.top().second >= p.second)
							flag = false;
					if (flag)
					{
						stk.push(p);
						break;
					}
					else
					{
						while(!stk.empty() && stk.top().second >= p.second)
						{
							res += stk.top().first;
							res += ' ';
							stk.pop();
						}
						continue;
					}
				}
			}
		}


		else if( str[i] == '#')
		{
			pair<char, unsigned> p(str[i], 6);
			while(true)
			{
				if( stk.empty())
				{
					stk.push(p);
					break;
				}
				else
				{
					bool flag = true;
						if(stk.top().second >= p.second)
							flag = false;
					if (flag)
					{
						stk.push(p);
						break;
					}
					else
					{
						while(!stk.empty() && stk.top().second >= p.second)
						{
							res += stk.top().first;
							res += ' ';
							stk.pop();
						}
						continue;
					}
				}
			}
		}

		else if( str[i] == '&')
		{
			pair<char, unsigned> p(str[i], 4);
			while(true)
			{
				if( stk.empty())
				{
					stk.push(p);
					break;
				}
				else
				{
					bool flag = true;
						if(stk.top().second >= p.second)
							flag = false;
					if (flag)
					{
						stk.push(p);
						break;
					}
					else
					{
						while(!stk.empty() && stk.top().second >= p.second)
						{
							res += stk.top().first;
							res += ' ';
							stk.pop();
						}
						continue;
					}
				}
			}
		}
		else if( str[i] == '(')
			stk.push( make_pair(str[i], 1));

		else if( str[i] == ')')
		{
			while( stk.top().second != 1)
			{
				res += stk.top().first;
				res += ' ';
				stk.pop();
			}
			if(stk.top().second == 1)
				stk.pop();
			str[i] == ' ';
		}
		else if( i == (str.size() - 1) && !stk.empty())
		{
			while(!stk.empty())
			{
				res += stk.top().first;
				res += ' ';
				stk.pop();
			}
		}
		else continue;
	}
	return res;
}
bool my_isdigit(string str)
{
	bool digit = true;
	for(string::iterator i = str.begin(); i != str.end(); i++)
	{
		if(!isdigit(*i) && *i != '.') digit = false;
	}
	return digit;
}
double calculate(string str)
{
	str = RPN(str);
	int i= str.size()-1;
	while(isspace(str[i]))
	{
		i--;
		str.erase(str.end()-1);
	}
	stack<double> st;
	stringstream str_in(str);
	str_in << str;
	while(!str_in.eof())
	{
		string temp;
		str_in >> temp;
		if(my_isdigit(temp))
		{
			istringstream xx(temp);
			double a;
			xx >> a;
			st.push(a);
		}
		else
		{
			if(temp == "+")
			{
				double right = st.top();
				st.pop();
				double left = st.top();
				st.pop();
				st.push(left + right);
			}
			else if(temp == "-")
			{
				double right = st.top();
				st.pop();
				double left = st.top();
				st.pop();
				st.push(left - right);
			}
			else if(temp ==  "*")
			{
				double right = st.top();
				st.pop();
				double left = st.top();
				st.pop();
				st.push(left * right);
			}
			else if(temp ==  "/")
			{
				try
				{

					double right = st.top();
					st.pop();
					if(right == 0)
						throw 0;
					double left = st.top();
					st.pop();
					st.push(left / right);
				}
				catch(...)
				{
					cout << "Error dividing by 0. Exiting...\n";
					system("pause");
					exit(1);
				}
			}
			else if(temp == "^")
			{
				double right = st.top();
				st.pop();
				double left = st.top();
				st.pop();
				st.push(pow(left, right));
			}
			else if(temp == "`")
				st.top() *= (-1);
			else if(temp == "$")
				st.top() = sin(st.top());
			else if(temp == "#")
				st.top() = cos(st.top());
			else if(temp == "&")
			{
				try
				{
					if(st.top() < 0) throw 0;
					st.top() = sqrt(st.top());
				}
				catch(...)
				{
					cout << "Cannot take sqrt of number < 0.\n";
					system("pause");
					exit(1);
				}
			}
		}


		}
		return st.top();
	}

void check_minus(string& str)
{
	for(int i=0; i<str.size(); i++)
	{
		if(str[i] == '-' && i != str.size()-1)
		{
			if(i == 0) str[i] = '`';
			else if( str[i-1] == '(' && isdigit(str[i+1])) str[i] = '`';
			else if( !isdigit(str[i-1]) && str[i-1] != ')') str[i] = '`';
		}
	}
}
int  main()
{
	string s;
	getline(cin, s);
	time_t ticks = clock();
	clear_str(s, ' ');
	replace_str(s);
	check_minus(s);
	double res = calculate(s);
	stringstream sst;
	sst << res;
	string a = sst.str();
	int pos = a.find(".");
	if(pos == string::npos) cout << a << ".000";
	else 
		for(unsigned i=0; i<=pos+3; i++)
			cout << a[i];
	cin.get();
	return (0);
}

