
#include <iostream>
#include <map>
#include <unordered_map>

#include <algorithm>
#include <iterator>

using namespace std;

void show(pair<int, char> p)
{
	cout << p.first << " = " << p.second << ", ";
}

int main()
{
	// MAP
	map<int, char> mt;

	if (mt.empty())
		for (int i = 0; i < 5; i++)
			mt.insert(make_pair(i, char(70 + i)));

	for (int i = 0; i < 6; i++)
		mt.emplace(make_pair(i, char(70 + i)));						// Вставка 5 елементів

	cout << "Maxsize: " << mt.max_size() << endl;						// Максимальний розмір
	cout << "Size: " << mt.size() << endl;								// Реальний розмір

	for_each(mt.begin(), mt.end(), show); cout << endl;
	for_each(mt.rbegin(), mt.rend(), show); cout << endl;


	mt.emplace_hint(mt.begin(), make_pair(50, char(90)));			// Вставка вниз з сортуванням
		cout << "Put element down: ";
	for_each(mt.begin(), mt.end(), show); cout << endl;

	auto itFind = mt.find(3);										// Пошук елемента з ключем
	cout << "Find: ";
	cout << itFind->first << " = " << itFind->second;

	cout << endl << "At(4): " << mt.at(4) << endl;

	//Mультимапа

	multimap<int, char> mmp; cout << endl;

	if (mmp.empty())
		for (int i = 0; i < 5; i++)
			mmp.insert(make_pair(i, char(70 + i)));

	for (int i = 0; i < 6; i++)
		mmp.insert(make_pair(i, char(75 + i)));						// Вставка

	cout << "Multimap: ";
	for_each(mmp.begin(), mmp.end(), show); cout << endl;

	auto eqr = mmp.equal_range(3);
	cout << "Equal_range: ";
	for_each(eqr.first, eqr.second, show); cout << endl;



	//Невпорядкована мапа

	unordered_map<int, char> ump; cout << endl;

	if (ump.empty())
		for (int i = 0; i < 5; i++)
			ump.insert(make_pair(i, char(70 + i)));

	for (int i = 0; i < 6; i++)
		ump.insert(make_pair(i, char(70 + i)));

	cout << "Unordered_map: ";
	for_each(ump.begin(), ump.end(), show); cout << endl;

	cout << "At(4): " << ump.at(4) << endl;

	//Невпорядкована Мультимапа

	unordered_multimap<int, char> ummp; cout << endl;

	if (ummp.empty())
		for (int i = 0; i < 5; i++)
			ummp.insert(make_pair(i, char(70 + i)));

	for (int i = 0; i < 6; i++)
		ummp.insert(make_pair(i, char(75 + i)));

	cout << "Unordered_multimap: ";
	for_each(ummp.begin(), ummp.end(), show); cout << endl;


	cout << "Bucket_count: " << ummp.bucket_count() << endl;
	cout << "Bucket_size: " << ummp.bucket_size(3) << endl;				// Вивід елементів
	cout << "Num bucket for elem. 5: " << ummp.bucket(5) << endl;

	unordered_multimap<int, char> ums; cout << endl;
	auto fn = ums.hash_function();										// Вивід хеш-функції

	cout << "that: " << fn(12) << endl;
	cout << "than: " << fn(10) << endl;

	system("pause");
	return 0;
}