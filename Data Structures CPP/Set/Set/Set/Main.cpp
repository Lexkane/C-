#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

void show(int i)
{
	cout << i << ", ";
}

int main()
{
	//множина
	set<int> st;

	if (st.empty())
		for (int i = 0; i < 5; i++)
			st.insert(i);

	for (int i = 0; i < 6; i++)
		st.emplace(i);											// Вставка 5

	cout << "Ms: " << st.max_size() << endl;					// Максимальний розмір
	cout << "S: " << st.size() << endl;							// розмір

	for_each(st.begin(), st.end(), show); cout << endl;
	for_each(st.rbegin(), st.rend(), show); cout << endl;


	st.emplace_hint(st.begin(), 50);							// Вставка в кінець з пересортуванням
	cout << "Emplace_hint: ";
	for_each(st.begin(), st.end(), show); cout << endl;

	auto itFind = st.find(4);
	cout << "Find: ";
	cout << *itFind << endl;

	//мультимножина

	multiset<int> mst; cout << endl;

	if (mst.empty())
		for (int i = 0; i < 5; i++)
			mst.insert(i);

	for (int i = 0; i < 6; i++)
		mst.emplace(i);											// Вставити все

	cout << "Multiset: ";
	for_each(mst.begin(), mst.end(), show); cout << endl;

	auto eqr = mst.equal_range(3);
	cout << "Equal_range: ";
	for_each(eqr.first, eqr.second, show); cout << endl;

	//Хеш тайблиця

	unordered_set<int> ust; cout << endl;

	if (ust.empty())
		for (int i = 0; i < 5; i++)
			ust.insert(i);

	for (int i = 0; i < 6; i++)
		ust.emplace(i);

	cout << "Unordered_set: ";
	for_each(ust.begin(), ust.end(), show); cout << endl;

	//Хеш мультитаблиця

	unordered_multiset<int> umst; cout << endl;

	if (umst.empty())
		for (int i = 0; i < 5; i++)
			umst.insert(i);

	for (int i = 0; i < 6; i++)
		umst.emplace(i);

	cout << "Unordered_multiset: ";
	for_each(umst.begin(), umst.end(), show); cout << endl;

	cout << "Bucket_count: " << umst.bucket_count() << endl;
	cout << "Bucket_size: " << umst.bucket_size(3) << endl;				// Вивід всіх елементів 
	cout << "Num bucket for elem. 5: " << umst.bucket(5) << endl;

	unordered_multiset<char*> ums; cout << endl;
	auto fn = ums.hash_function();										// Виклик хеш-функції

	cout << "that: " << fn((char*)"that") << endl;
	cout << "than: " << fn((char*)"than") << endl;

	system("pause");
	return 0;
}