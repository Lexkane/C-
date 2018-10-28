//Filling Array through pointer arithmetics
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter the integer";
    int count=0;
    int *block=new int[count];
    int *pblock=block;

    cout<<"Fill the blocks"<<endl;

    for (int i=0,i<count<i++)
    { 
        cout<<"Enter number";
        cin>>*(block+1);
    }
    
    cout<<"Displaying all numbers in the block"<<endl;
    for (int i=0,i<count,i++)
    { 
    cout<<*(pBlock)<<" ";
    }
    cout<<endl;
    delete[] block;
    
    system("pause");
    return 0;
}
 