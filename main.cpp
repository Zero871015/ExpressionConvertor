// Name: zero871015(B10615032)
// Date: 2018/10/01
// Last Update: 2018/10/08
// Problem statement: Infix to prefix and postfix.

#include <iostream>
#include <string>
#include "myStack.h"
using namespace std;
#define MAX_SIZE 30

string ToPostOrder(string str);
void MyReverse(string &str);

int main()
{
	string str;
	string postOrder,preOrder;
	try
	{
		cin >> str;
		str.insert(0, "(");
		str.insert(str.length(), ")");
		cout << "Let " << str <<" to postfix:"<< endl;
		postOrder = ToPostOrder(str);
		cout << "The result: " << postOrder << endl;
		cout << endl;

		cout << "Let " << str << " to prefix:" << endl;
		cout << "First, reverse the infix:" << endl;
		MyReverse(str);
		cout << "Now infix: " << str << endl;
		cout << "Do postfix convert:" << endl;
		preOrder = ToPostOrder(str);
		MyReverse(preOrder);
		cout << "Reverse again." << endl;
		cout << "The result: " << preOrder << endl;
	}
	catch (const std::invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}

int operatorPriority(char c)
{
	if (c == '+' || c == '-')return 1;
	else if (c == '*' || c == '/' || c == '%')return 2;
	else if (c == ')')return 3;
	else if (c == '(')return 0;
	else return -1;
}

string ToPostOrder(string str)
{
	string ans;
	myStack<char> s(MAX_SIZE);
	printf("Infix Scanned\tStack\t\tPostfix Expression\n");
	for (int i = 0; i < (int) str.length(); i++)
	{
		//If it is a operator.
		if (operatorPriority(str[i])!=-1)
		{
			//State of ().
			if(str[i]=='(')
				s.push(str[i]);
			else if (str[i] == ')')
			{
				while(s.back()!='(')
				{
					ans += s.back();
					s.pop();
				}
				s.pop();
			}
			//Stack is empty.
			else if (s.count() == 0)
				s.push(str[i]);
			//The priority is biger than stack.
			else if (operatorPriority(str[i]) > operatorPriority(s.back()))
			{
				s.push(str[i]);
			}
			else
			{
				do
				{
					ans += s.back();
					s.pop();
					if (s.count() == 0)
					{
						break;
					}
				} while (operatorPriority(str[i]) <= operatorPriority(s.back()));
				s.push(str[i]);
			}
		}
		//Or it just arithmetic element.
		else
		{
			ans += str[i];
		}
		//Step by step show the information.
		cout << str[i] << "\t\t";
		s.Show();
		cout << "\t\t";
		cout << ans << endl;
	}
	return ans;
}

void MyReverse(string & str)
{
	string temp;
	for (int i = str.length()-1; i >=0; i--)
	{
		if (str[i] == ')')
			temp += '(';
		else if (str[i] == '(')
			temp += ')';
		else
			temp += str[i];
	}
	str = temp;
}