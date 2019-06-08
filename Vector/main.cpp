#include <iostream>
#include "Vector.h"
#include "Vector.cpp"

using namespace std;

int main()
{
Vector A(5,100);
cout<<A.GetLength()<<'\n';

A[1] = 99;

A.sort();

for(int i = 0; i < A.GetLength(); i++)
{
cout<<A[i]<<'\n';
}


return (0);
}
