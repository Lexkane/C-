// Matrix2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iostream> 
#include <iomanip>
#include <memory>
#include <cmath>

using namespace std;


void fill_matrix(int &n,int&m, int** matrix) 
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cout << "Enter element on row i=  " << i << " and column j= " << j << endl;
			cin >> matrix[i][j];
		}


}

void matrix_count(int &even_count, int &odd_count, int &n, int&m ,int** matrix)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (remainder(matrix[i][j], 2) == 0)
			{
				even_count++;
			}
			else odd_count++;
		}
	
}


void matrix_transform(int** &matrix, int &n, int&m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{

			if (remainder(matrix[i][j], 2) == 0)
			{
				//odd numbers we multiply with itself
				matrix[i][j] = (matrix[i][j])*(matrix[i][j]);
			}
			else
			{
				//even elements we divide by 2
				matrix[i][j] /= 2;
			}
		}
}


void result_matrix(int** &matrix, int&n, int&m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}
int main() {

	int n, m;
	int	even_count = 0;
	int odd_count = 0;
	std::cout << "Enter Matrix Height" << endl;
	cin >> n;
	std::cout << "Enter Matrix Width" << endl;
	cin >> m;

	//allocate matrix n*m on the heap
	int **matrix = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[m];
	}


	//fill the Matrix
	fill_matrix(n, m,matrix);

	//even count increases if even element,else odd increases	
   //so we counted all even and odd elements of the matrix
   //here we use remainder function which is useful for comparing remainder from double division
	matrix_count(odd_count, even_count,n,m,matrix);
	//now we iterate through matrix and transform it according to the defined rules



	matrix_transform(matrix,n,m);	


	//here we output transformed matrix
	cout << "Resulting matrix after transformation" << endl;
	result_matrix(matrix, n, m);

	//output results
	cout << setprecision(5)
		<< "Specific weight of all odd numbers in the original matrix " << double(odd_count) / double(n * m) << "\n"
		<< "Specific weight of all even numbers in the original matrix" << 1. - double(odd_count) / double(n * m) << endl;
	//delete pointer for our matrix

	delete(matrix);

	return 0;

};