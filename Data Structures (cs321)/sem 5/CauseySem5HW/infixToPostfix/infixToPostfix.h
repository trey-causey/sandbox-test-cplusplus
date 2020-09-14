/************************************************
infixToPostfix.h
Author: Trey Causey
Date: 6/10/08
**************************************************/
#include <iostream>
#include <string>
#include "myStack.h"

using namespace std;

class infixToPostfix: public stackType<char>
{
public:
	void getInfix();
	//Function to store the infix expression
	string showInfix();
	//Function to output the infix expression
	string showPostfix();
	//Function to output the postfix expression
	void convertToPostfix();
	//Function to convert the infix expression to a postfix expression
	bool precedence();
	//Function to determine the precedence between two operators
	infixToPostfix();
	//Constructor
	~infixToPostfix();
	//Deconstructor

private:
	string infixString; //variable to hold the infix expression
	stackType<char> stack; //object stack of the class stackType
	string postfixString; //variable to hold the postfix expression

};


void infixToPostfix::getInfix()
{
	cout<<"Enter in the infix expression, "
		<<"for example, (3+5)/(9-2): ";
	getline(cin, infixString);


}


string infixToPostfix::showInfix()
{
	return infixString;
}


string infixToPostfix::showPostfix()
{
	return postfixString;
}


void infixToPostfix::convertToPostfix()
{
	char ch; //variable to hold currently scanned symbol
	int i = 0; //index to traverse expression
	
	stack.initializeStack();
	
	while(i < infixString.length())
	{
		if(!stack.isFullStack())
		{
			ch = infixString[i];

			switch(ch)
			{
			case '0': case '1': case '2': case '3': case '4': 
			case '5': case '6': case '7': case '8': case '9':
				postfixString += ch;
				break;
			case '(':
				stack.push(ch);
				break;
			case ')':
				while(stack.top() != '(')	
				{
					postfixString += stack.top();
					stack.pop();
				} //end while

					stack.pop();
				break;
			case '+': case '-': case '*': case '/':
				stack.push(ch);
				precedence();
				break;
			case '=':
				while(!stack.isEmptyStack())
				{
					postfixString += stack.top();
					stack.pop();
				}
				break;
			default:
				break;
			} //end switch
		} //end if
		
		i++; //increment index to traverse expression

	} //end while
}


bool infixToPostfix::precedence()
{
	return 1;
}


infixToPostfix::infixToPostfix()
{
	infixString = " ";
	postfixString = " ";
}


infixToPostfix::~infixToPostfix()
{

}