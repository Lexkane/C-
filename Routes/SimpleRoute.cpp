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



//���������� ���������
typedef struct {
public:

	string start;
	string finish;
	int number;

} MARSH;




int main() {

	//��������� ������ ��������� MARSH

	MARSH Massive[n];
	int numberToDisplay;
	bool number�sInMassive = false;
	int q;

	setlocale(LC_ALL, "ukrainian");

	//�������� �������� � ������
	for (int i = 0; i < n; i++) {
		int j = i;
		cout << "������ " << j+1 << " ���� ������� ������� " << endl;
		cin >> Massive[i].start;
		cout << "����i�� " << j+1 << " ���� ���� �������" << endl;
		cin >> Massive[i].finish;
		cout << "����i�� " << j+1 << " ����� ������� " << endl;
		cin >> Massive[i].number;
	}

	//���������� ������ ������� M������ �� ��������� ������

	int i, j;
	for (i = 0; i < n - 1; ++i)
	for (j = 0; j < n - i - 1; ++j)
	{
		//���� ��������� ����� � �������� ������ �� ��������� ���
		if (Massive[j].number > Massive[j + 1].number)
		{
			//������ ��������� ������ � �����

			MARSH temp = Massive[j];
			Massive[j] = Massive[j + 1];
			Massive[j + 1] = temp;
		}

	}

   do {
		cout << "\n ������ ����� ������� ������ ������� ����c��";
		cin >> numberToDisplay;
		for (int i = 0; i < n - 1; i++) {
			if (Massive[i].number==numberToDisplay) {
				cout << "----------------------------------------------------------------\n";
				cout << "|� �������� " << "|    " << "|  ������� �������  " << "| ʳ���� �������  |\n";
				cout << "----------------------------------------------------------------\n";
				cout << "|" << setw(2) << Massive[i].number<<
					"|" << setw(20) << Massive[i].start<<
					"|" << setw(22) << Massive[i].finish << "|" << "\n";
				cout << "----------------------------------------------------------------\n";
				number�sInMassive = true;
			}

		}

		if (number�sInMassive == false) { cout << "\n ������ ������� �� i���!" << end;; }
		cout << "���������� ������?\n1 - ���\t0 - �\n";
		cin >> q;
	} while (q != 0);

   //������� ���'���
	delete Massive;
	return 0;
}
