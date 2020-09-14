/*****************************************************
Author:Trey Causey
Date: 6/11/08
Purpose: This program is designed to convert an infix
	expression that is entered by a user to a 
	postfix expression.
*****************************************************/
#include<iostream>
#include"infixToPostfix.h"

using namespace std;

int main()
{
	infixToPostfix expression; //object expression of the type infixToPostfix
	
	cout<<"This program is designed to convert an infix expression into \n"
		<<"a postfix expression."<<endl;
	expression.getInfix();
	expression.convertToPostfix();
	cout<<"The infix expression "<<expression.showInfix()<<" when converted to \n"
		<<"postfix expression is "<<expression.showPostfix();
	cout<<endl;
	cout<<endl;
	system("pause");

}