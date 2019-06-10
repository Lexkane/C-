#include <iostream>

using namespace std;

void print_matrix(const int *k, size_t columns, size_t rows) {
	for (int i=0;i<rows;i++) {
		for (int j=0;j<columns;j++) {
			cout << k[i*columns+j] << " ";
		}

		cout << endl;
	}
}

int* max_element(const int *k, size_t columns, size_t rows) {
	int *max_el = new int[rows];

	for (int i=0;i<rows;i++) {
		max_el[i] = k[i*columns];
		for (int j=1;j<columns;j++) {
			if (k[i*columns+j] > max_el[i]) {
				max_el[i] = k[i*columns+j];
			}
		}
	}

	bool swp;

	do {
		swp = false;
		for(int i = 0; i < rows - 1; i++) {
			if (max_el[i] > max_el[i+1]){
				swap(max_el[i], max_el[i+1]);
				swp = true;
			}
		}
	} while(swp);

	return max_el;
}

int main() {
	size_t columns = 0;
	cout << "Columns: ";
	cin >> columns;

	size_t rows = 0;
	cout << "Rows: ";
	cin >> rows;

	int *k = new int[columns*rows];

	for (int i=0;i<rows;i++) {
		for (int j=0;j<columns;j++) {
			cin >> k[i*columns+j];
		}
	}

	cout << endl << endl;

	print_matrix(k, columns, rows);

	cout << endl << endl;

	int *maxel = new int[rows];
	maxel = max_element(k, columns, rows);

	cout << "Max elements: ";

	for (int i=0;i<rows;i++) {
		cout << maxel[i] << " ";
	}

	return 0;
}
