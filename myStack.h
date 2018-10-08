// Name: zero871015(B10615032)
// Date: 2018/10/01
// Last Update: 2018/10/01
// Problem statement: Stack implement.

#pragma once
#include <iostream>
using namespace std;

template <class t>
class myStack
{
public:
	myStack();
	myStack(int size);
	~myStack();
	t& operator[](int index);
	void push(t x);
	t pop();
	t back();
	int count();
	void Show();
private:
	int size;
	int top;
	t *data;
};

template<class t>
myStack<t>::myStack()
{
	this->size = 1;
	this->top = 0;
}

template<class t>
myStack<t>::myStack(int size)
{
	if (size <= 0)
		throw std::invalid_argument("Size should > 0");
	this->size = size;
	this->data = new t[size];
	this->top = 0;
}

template<class t>
myStack<t>::~myStack()
{
}

template<class t>
t & myStack<t>::operator[](int index)
{
	if (index >= top)
	{
		throw std::invalid_argument("The index illegal!");
	}
	return this->data[index];
}

template<class t>
void myStack<t>::push(t x)
{
	if (top != size)
	{
		this->data[top] = x;
		top++;
	}
	else
	{
		throw std::invalid_argument("The stack is full!");
	}
}

template<class t>
t myStack<t>::pop()
{
	if (top != 0)
	{
		top--;
		return this->data[top + 1];
	}
	else
	{
		throw std::invalid_argument("Nothing can pop!");
	}
}

template<class t>
t myStack<t>::back()
{
	if(top==0)
		throw std::invalid_argument("Nothing in stack!");
	return this->data[top-1];
}

template<class t>
int myStack<t>::count()
{
	return top;
}

template<class t>
void myStack<t>::Show()
{
	for (int i = 0; i < this->top; i++)
	{
		std::cout << this->data[i];
	}
}
