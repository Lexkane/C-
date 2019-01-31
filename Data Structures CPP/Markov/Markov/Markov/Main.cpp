#include <iostream>
#include "Markov.h"
using namespace std;


int main()


{
	//Перевірка чи сума в кожному рядку рівна 1
	double m[3][3] = { { 0, 0, 1 },
					{ 0.5, 0, 0.5 },
					{ 1, 0, 0 } };

	
	if (checkMarkov(m))
		cout << " True ";
	else
		cout << " False ";



	system("pause");
	return 0;
}