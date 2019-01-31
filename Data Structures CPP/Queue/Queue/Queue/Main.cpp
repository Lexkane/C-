#include <queue>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "Queue.h"

	using namespace std;

	void display(char* str)
	{
		cout << str << endl;
	}
	

	int main()
	{
		

		queue<char*> qu;
		queue<char*> qu2;

		if (qu.empty() || qu2.size() == 0)
		{
			qu.push((char*)"1 push");
			qu.emplace((char*)"2 emplace");
			qu.push((char*)"3 push");

			qu2.push((char*)"4 push");
			qu2.emplace((char*)"5 emplace");
			qu2.push((char*)"6 push");
		}

		qu.swap(qu2);

		while (!qu.empty())
		{
			
			cout << qu.front() << endl;
			qu.pop();
		}

		cout << " --- done --- " << endl;

		while (!qu2.empty())
		{
			cout << qu2.front() << endl;
			qu2.pop();
		}
		cout << " --- done! --- " << endl;

		//Priority_queue

		priority_queue<int> prq;

		prq.emplace(15);
		prq.emplace(125);
		prq.emplace(83);
		prq.emplace(76);

		while (!prq.empty())
		{
			cout << prq.top() << endl;
			prq.pop();
		}
		cout << " --- done! --- " << endl;
	system("pause");
	return 0;
}