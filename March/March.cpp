#include <iostream>
#include <cstdio>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#define n 10
 
using namespace std;
 
struct ORDER
{string getaccount;
int payaccount;
int sum;
}PRICE[n];
 
 
int main()
{int checkaccount;
int tmp;
string tnp;
int sum1=0;
int tmp1;
ORDER PRICE[n];
 
setlocale(LC_ALL, "ukrainian");
for(int i=0; i<n; i++)
{cout<<"Уведiть розрахунковий рахунок "<<i+1<<"-го платника: ";
cin>>PRICE[i].payaccount;
cout<<"Уведiть розрахунковий рахунок "<<i+1<<"-го одержувача: ";
cin>>PRICE[i].getaccount;
cout<<"Уведiть суму "<<i+1<<"-ої операцiї в грн.: ";
cin>>PRICE[i].sum;}
 
 int i,j;
 for (i=0; i<n; ++i)
 {for (j = i+1; j<n; ++j)
 {if(PRICE[i].payaccount>PRICE[j].payaccount)
     {tmp=PRICE[i].payaccount;
     PRICE[i].payaccount=PRICE[j].payaccount;
     PRICE[j].payaccount=tmp;
     tnp=PRICE[i].getaccount;
     PRICE[i].getaccount=PRICE[j].getaccount;
     PRICE[j].getaccount=tnp;
     tmp1=PRICE[i].sum;
     PRICE[i].sum=PRICE[j].sum;
     PRICE[j].sum=tmp1;}
   }  
 }
 
cout<<"----------------------------------------------------------------\n";
cout<<"|№ "<<"|  Рахунок платника  "<<"|  Рахунок одержувача  "<<"|   Сума, грн.  |\n";
cout<<"----------------------------------------------------------------\n";
for(int i=0; i<n; i++)
{cout<<"|"<<setw(2)<<i+1<<"|"<<setw(20)<<PRICE[i].payaccount<<"|"<<setw(22)<<PRICE[i].getaccount<<"|"<<setw(15)<<PRICE[i].sum<<"|\n";}
cout<<"----------------------------------------------------------------\n";
 
int cont;
do {
cout<<"\nУведiть розрахунковий рахунок платника,\nщоб отримати суму, зняту з рахунку: ";
cin>>checkaccount;
for (int i=0; i<n; i++)
{if(checkaccount==PRICE[i].payaccount)
sum1+=PRICE[i].sum;}
 
if(sum1==0)
cout<<"\nРозрахунковий рахунок платника не iснує!";
else cout<<"\nСума, знята з рахунку "<<checkaccount<<": "<<sum1<<" грн.";
sum1=0;
cout<<"Продовжити роботу?\n1 - так\t0 - ні\n";
cin>>cont;
}
while (cont!=0);
 
return 0;
}