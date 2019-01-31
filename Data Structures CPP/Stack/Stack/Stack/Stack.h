#pragma once

#include <iostream>
#include <exception>



template <typename T>
struct Stack
{
	Stack() : _top(NULL), _size(0)
	{}


	struct Node
	{
		Node(T el) : data(el), next(NULL)
		{}
		Node(T el, Node* node) : data(el), next(node)
		{}
		Node* next;
		T data;
	};

	void push(const T);
	void pop();
	T& top();
	int size();
	bool empty();

private:
	Node* _top; // вказівник на верхній елемент
	int _size; //poзмір стеку
};

template <typename T>
void Stack<T>::push(const T el)
{
	try
	{
		if (_top != NULL) //Якщо стек не  порожній ініціалізуємо ноду
		{
			Node* temp = new Node(el, _top); //нова нода вказує на кінець стеку
			_top = temp; //новий елеемн іде вниз
		}
		else
		{
			_top = new Node(el); //вперше створюємо ноду
		}
		_size++; // збільшуємо лічильник
	}
	catch (std::bad_alloc)
	{
		std::cout << "std::bad_alloc" << std::endl;
	}
}

template <typename T>
void Stack<T>::pop()
{
	try
	{
		if (_top == NULL)  //Перевіримо чи стек не є пустим
			throw std::out_of_range("Er Out of range");// Помилка виходу за межі

		Node* temp = _top; //зберігаємо останній елемент в темп
		_top = _top->next;//передостанній елемент стає останнім
		delete temp; // видалення останнього елемента
		_size--;//зменшення лічильника
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <typename T>
T& Stack<T>::top()
{
	try
	{
		if (_top == NULL)
			throw std::out_of_range("Er Stack is empty!");// Чи стек є пустим

		return _top->data; //з останнього елемента забираємо дані
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <typename T>
int Stack<T>::size()
{
	return _size; // отримуємо розмір
}

template <typename T>
bool Stack<T>::empty()
{
	return _size == 0 ? true : false;   // перевіряємо чи стек є порожнім
}
