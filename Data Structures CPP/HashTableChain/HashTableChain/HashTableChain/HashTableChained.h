#include<iostream>
#include <list>
using namespace std;

class Hash
{
	int BUCKET;    

	// вказівник на таблицю пар
	list<int> *table;
public:
	Hash(int V);  // Конструктор

	// всатвка 
	void insertItem(int x);

	//видалення ключа
	void deleteItem(int key);

	// хеш функція для вставки
	int hashFunction(int x) {
		return (x % BUCKET);
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
	// отримання хеш функції
	int index = hashFunction(key);

	// знаходження ключа
	list <int> ::iterator i;
	for (i = table[index].begin();
		i != table[index].end(); i++) {
		if (*i == key)
			break;
	}

	// якщо ключ є видалення
	if (i != table[index].end())
		table[index].erase(i);
}

// відображення таблиці
void Hash::displayHash() {
	for (int i = 0; i < BUCKET; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " --> " << x;
		cout << endl;
	}
}
