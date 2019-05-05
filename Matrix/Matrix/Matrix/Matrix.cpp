// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream> 
#include <iomanip>
#include <memory>
#include <cmath>

class Grid {
	size_t _rows;
	size_t _columns;
	std::unique_ptr<int[]> data;

public:
	Grid(size_t rows, size_t columns)
		: _rows{ rows },
		_columns{ columns },
		data{ std::make_unique<int[]>(rows * columns) } {}

	size_t rows() const { return _rows; }

	size_t columns() const { return _columns; }

	int *operator[](size_t row) { return row * _columns + data.get(); }

	int &operator()(size_t row, size_t column) {
		return data[row * _columns + column];
	}

	Grid() {};
	~Grid() {};

	//overload of cin  operator for custom class for input
	friend std::istream& operator >> (std::istream& is, Grid& g)
	{

		is >> g._columns >> g._rows;
		return is;
	}

	//overload of cout operator for custom class for output
	friend std::ostream& operator << (std::ostream& os, Grid& g)
	{
		os << g._columns << " " << g._rows;
		return os;
	}
};

//we can create matrix as vector of vectors
//std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

using namespace std;
int main() {

	double n, m;
	int	even_count = 0;
	int odd_count=0;
	std::cout << "Enter Matrix Height" << endl;
	cin >> n;
	std::cout << "Enter Matrix Width"<<endl;
	cin >> m;

	//allocate matrix n*m on the heap
	

	double **matrix = new double*[n];
	for (int i = 0; i < n; ++i)
		matrix[i] = new double[m];


	//fill the Matrix
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cout << "Enter element on row i=  " << i << " and column j= " << j << endl;
			cin >> matrix[i][j];
		}


	//even count increases if even element,else odd increases	
   //so we counted all even and odd elements of the matrix
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (remainder(matrix[i][j],2)==0)
			{
				even_count++;
			}
			else odd_count++;
		}

	//now we iterate through matrix and transform it according to the rules
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{

			if (remainder(matrix[i][j],2) == 0)
			{
				//odd numbers we multiply with itself
				matrix[i][j] = (matrix[i][j])*(matrix[i][j]);
			}
			else
			{
				//even elements we divide by 2
				matrix[i][j] /=2;
			}
		}

	
	
	//here we output weight of odd and even numbers in the original matrix
	cout << setprecision(5) << "Specific weight of all odd numbers in the original matrix " << double(odd_count) / double(n * m) << "\n"
		<< "Specific weight of all even numbers in the original matrix" << 1. - double(odd_count) / double(n * m) << endl;


	//here we output transformed matrix
	cout << "Resulting matrix after transformation" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}

	
	//delete pointer for our matrix

	free (matrix);
	
	return 0;

};




