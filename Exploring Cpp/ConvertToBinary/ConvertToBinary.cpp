//binary numbers converter

#include "stdafx.h"
#include <iostream>
using namespace std;
void convert (int n);

int main()
{
    int number=0;
    cout<<"Enter the number to convert";
    cin>>number;
    convert(number);
    cout<<endl;    
    
    system("pause");
    return 0;
}

void convert(int namespace)
{
    int temp;
    temp=n%2;
    if (n>=2)
    {
        convert (n/2);
    }
    cout<<tmp;
}
