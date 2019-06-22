// RockPapperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int random(int n, int m) {
	return rand() % (m - n + 1) + n;
}

enum Choice { Rock=1, Scissors=2, Paper=3 };

bool consume(istream& is, const char* p)
{
	while (*p)
		if (is.get() != *p++)
		{
			is.setstate(ios::failbit);
			return false;
		}
	return true;
}

istream& operator>>(std::istream& is, Choice& o)
{
	switch (is.get())
	{
	case 'R': if (consume(is, "ock") ){ o =Rock; return is; } break;
	case 'S': if (consume(is, "cissors")) { o = Scissors; return is; } break;
	case 'P': if (consume(is, "aper") ){ o = Paper; return is; } break;
	}
	is.setstate(std::ios::failbit);
		return is;
}

int main()
{
	string PlayerStatus;
	int program_result,program_generated_input,user_input;
	cout << " Hello, Please Enter Rock,Scissors or Paper \n";
	Choice input;
	cin >> input;	
	program_generated_input = random(1, 3);

	switch (input)
	 {
			case(Rock): user_input = 1;
			case(Scissors):user_input = 2;
			case(Paper): user_input = 3;
   default:	
	 if (user_input == program_generated_input) { cout << "This is draw.Try luck once more\n " << endl; }
	 if (user_input < program_generated_input || user_input!=3 ) { cout << "You are loser\n" << endl; }
	 else if ((user_input==3)&&(program_generated_input==1)){cout<<"You are a winner\n"<<endl; }
	 else if ((user_input==3)&&( program_generated_input==2)){cout << "You are loseer\n" << endl; }
	}
	cout << user_input << "/n" << endl;
	cout << program_generated_input << endl;

	return 0;
}
//Rock beats scissors   1>2
//Scissors beats paper   2>3 

//Rock Scissors Paper

//User Program Result
//1		1		draw
//1		2       win
//1		3		lose
//2		1		lose
//2		2		draw
//2		3		win
//3		1		win		
//3		2		lose
//3		3		draw

