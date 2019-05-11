#include <iostream>
using namespace std;

void findPairOfSum(int arrayOfNum[],int arraySize, int num)
{
    for (int i=0;i<arraySize;i++)
    {
        for (int j=i;j<arraySize;j++)
        {
            if (arrayOfNum[i]+arrayOfNum[j]==sum)
            cout<<"("<<arrayOfNum[i]<<","<<arrayOfNum[j]<<")"<<endl;
        }
    }
}
int main()
{
    int arr [5]=[1,2,3,4,5,6,8,9,10];
    int sum=20;
    
   findPairOfSum(arr,arr.length,sum);

    return 0;
}