#include "HashTableOpen.h"
#include <iostream>
#include <cstddef>

using namespace std;

int main() {
	
	HashMap<int, int> *h = new HashMap<int, int>;
	h->insertNode(1, 6);
	h->insertNode(2, 5);
	h->insertNode(3, 8);
	h->insertNode(4, 9);
	h->insertNode(5, 10);
	h->insertNode(6, 11);
	
	h->display();
	cout << h->sizeofMap() << endl;
	cout << h->deleteNode(2) << endl;
	cout << h->sizeofMap() << endl;
	cout << h->isEmpty() << endl;
	cout << h->get(2);


	system("pause");
	return 0;
}