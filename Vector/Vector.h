#pragma once
#include <iostream>
using namespace std;

class Vector
{
protected:
int* Arr;
int N;
void QuickSort(int M, int T);
void Swap(int &A,int &B);
public:
Vector();
Vector(int NN);
Vector(int NN, int CC);
Vector(const Vector& A);
~Vector();

void sort();

int& operator[](int i) const
{
return Arr[i];
}
int GetLength();
};
