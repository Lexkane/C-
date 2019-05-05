#include <iostream>
#include <cstdio>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstdlib>
#define n 10

using namespace std;


//визначення структури
typedef struct MARSH {
public:
    string start;
    string finish;
    int number;
} MARSH;


//перевизначення порядку порівняння для застосуваня qsort

int CompareMarsh(const MARSH *m1, const MARSH *m2) {
    int result = (m1->number < m2->number) ? -1 : (m1->number > m1.number);
    if (0 != result) return result;

    int result = strcmp(m1->start, m2->start);
    if (0 != result) return result

    if (m1->finish < m2->finish) return -1;
    if (m1->finish > m2->finish) return 1;

    return 0;
}

int main() {
    //створення масиву структури MARSH
    MARSH Massive[n];
    int numberToDisplay;
    byte isInMassive = false;
    byte q = false;


    int checkaccount;
    int tmp;
    string tnp;
    int sum1 = 0;
    int tmp1;

    setlocale(LC_ALL, "ukrainian");

//введення струтури з консолі
    for (int i = 0; i < n - 1; i++) {
        cout << "Уведіть " << i << " початок маршуту " << endl;
        cin >> Massive->start;
        cout << "Уведiть " << i << " кінець маршуту" << endl;
        cin >> Massive->finish;
        cout << "Уведiть" << i << "номер маршуту " << endl;
        cin >> Massive->number;
    }

//сортування струтури Mарш застосовуючи функцію qsort
    qsort(Massive, n, sizeof(MARSH), CompareMarsh);

    /*int i, j;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (PRICE[i].payaccount > PRICE[j].payaccount) {
                tmp = PRICE[i].payaccount;
                PRICE[i].payaccount = PRICE[j].payaccount;
                PRICE[j].payaccount = tmp;
                tnp = PRICE[i].getaccount;
                PRICE[i].getaccount = PRICE[j].getaccount;
                PRICE[j].getaccount = tnp;
                tmp1 = PRICE[i].sum;
                PRICE[i].sum = PRICE[j].sum;
                PRICE[j].sum = tmp1;
            }
        }
    }

     */



    do {
        cout << "\n Уведіть номер маршуту котрий потрібно вивсети";
        cin >> numberToDisplay;
        for (int i = 0; i < n - 1; i++) {
            if (numberToDisplay == Massive[i].number) {
                cout << "----------------------------------------------------------------\n";
                cout << "|№ марштуку " << "|    " << "|  Початок маршуту  " << "| Кінець маршуту  |\n";
                cout << "----------------------------------------------------------------\n";
                cout << "|" << setw(2) << Massive->number
                "|" << setw(20) << Massive->start
                "|" << setw(22) << Massive->finish << "|" << "\n";
                cout << "----------------------------------------------------------------\n";
                isInMassive = true;
            }
        }

        if (isInMassive == false) { cout << "\n Такого маршуту не iснує!"; }
        cout << "Продовжити роботу?\n1 - так\t0 - ні\n";
        cin >> q;
    } while (q != 0);
    //очищуємо пам'ять
    delete Massive;
    return 0;
}