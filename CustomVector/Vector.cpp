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
//h.(header)


Vector :: Vector():N(0){}

Vector :: Vector(int NN)
{
N = NN;
Arr = new int [N];
for(int i = 0; i < N; i++)
Arr[i] = 0;
}
Vector :: Vector(int NN, int CC)
{
N = NN;
Arr = new int [N];
for(int i = 0; i < N; i++)
Arr[i] = CC;
}

Vector :: Vector(const Vector &A)
{
this->Arr = new int [A.N];
this->N = A.N;

if (&A != this)
{
for(int i = 0; i < this->N ; i++)
this->Arr[i] = A.Arr[i];
}
}

Vector :: ~Vector()
{
delete [] Arr;
}

int Vector :: GetLength()
{
return N;
}

void Vector :: QuickSort(int M, int T)
{
int I, J, X;
X = Arr[(M+T)/2];

do {
for(I=M;Arr[I]<X;I++){
}
for(J=T;Arr[J]>X;J--){
}
if (I <= J){
Swap(Arr[I],Arr[J]);
I++;
J--;
}
} while(!(I>J));

if (I<T) QuickSort(I,T);
if (M<J) QuickSort(M,J);

}

void Vector :: Swap(int &A,int &B)
{
int C;
C = A;
A = B;
B = C;
}


void Vector :: sort()
{
for(int i=0; i<N; i++)
for(int j=0; j<N-i-1; j++)
if(Arr[j]>Arr[j+1])
swap(Arr[j],Arr[j+1]);
}


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


return 0;
}



