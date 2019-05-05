#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstdlib>
#define n 10

using namespace std;



//визначення структури
typedef struct {
public:

	string start;
	string finish;
	int number;

} MARSH;




int main() {

	//створення масиву структури MARSH

	MARSH Massive[n];
	int numberToDisplay;
	bool numberІsInMassive = false;
	int q;

	setlocale(LC_ALL, "ukrainian");

	//введення струтури з консолі
	for (int i = 0; i < n; i++) {
		int j = i;
		cout << "Уведіть " << j+1 << " місце початку маршуту " << endl;
		cin >> Massive[i].start;
		cout << "Уведiть " << j+1 << " місце кінця маршуту" << endl;
		cin >> Massive[i].finish;
		cout << "Уведiть " << j+1 << " номер маршуту " << endl;
		cin >> Massive[i].number;
	}

	//сортування масиву струтур Mаршутів по зростанню номерів

	int i, j;
	for (i = 0; i < n - 1; ++i)
	for (j = 0; j < n - i - 1; ++j)
	{
		//якщо попередній номер в структурі більший за наступний тоді
		if (Massive[j].number > Massive[j + 1].number)
		{
			//міняємо структури місцями в масиві

			MARSH temp = Massive[j];
			Massive[j] = Massive[j + 1];
			Massive[j + 1] = temp;
		}

	}

   do {
		cout << "\n Уведіть номер маршуту котрий потрібно вивеcти";
		cin >> numberToDisplay;
		for (int i = 0; i < n - 1; i++) {
			if (Massive[i].number==numberToDisplay) {
				cout << "----------------------------------------------------------------\n";
				cout << "|№ марштуку " << "|    " << "|  Початок маршуту  " << "| Кінець маршуту  |\n";
				cout << "----------------------------------------------------------------\n";
				cout << "|" << setw(2) << Massive[i].number<<
					"|" << setw(20) << Massive[i].start<<
					"|" << setw(22) << Massive[i].finish << "|" << "\n";
				cout << "----------------------------------------------------------------\n";
				numberІsInMassive = true;
			}

		}

		if (numberІsInMassive == false) { cout << "\n Такого маршуту не iснує!" << end;; }
		cout << "Продовжити роботу?\n1 - так\t0 - ні\n";
		cin >> q;
	} while (q != 0);

   //очищуємо пам'ять
	delete Massive;
	return 0;
}
