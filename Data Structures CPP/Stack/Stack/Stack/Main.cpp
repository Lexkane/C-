#include <iostream>
#include <exception>
#include "Stack.h"


int main()
{
	Stack<int> stack;
	//std::cout << stack.top() << std::endl;

	stack.push(11);
	stack.push(24);
	stack.push(46);
	stack.push(51);
	stack.push(42);
	stack.push(141);
	stack.push(623);
	stack.push(521);
	stack.push(21);

	while (!stack.empty())
	{
		std::cout << stack.top() << " - " << stack.size() << std::endl;
		stack.pop();
	}

	
	//stack.pop(); Перевірка на catch помилки

	system("pause");
	return 0;

}