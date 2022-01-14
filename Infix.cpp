/**
* [Suha Cho]
* [Infix.cpp]
**/

#include "Infix.h"
#include <iostream>

using namespace std;


Infix::Infix() //default constructor
{
	infixExp = "";
}


Infix::Infix(string infix) //constructor
{
	set(infix); //set the initial value of infixExp
}


bool Infix::precedence(char first, char second)
{
	bool result = false;

	//assign a number that represents the precedence of operation
	int p1 = getPrecedence(first); 
	int p2 = getPrecedence(second);

	//compare the precedence between two operators
	if (p1 <= p2) 
	{
		result = true;
		return result;
	}
	else
		return result;
}



int Infix::getPrecedence(char opr)
{
	if (opr == '+' || opr == '-')
	{
		return 1;
	}
	else if (opr == '*' || opr == '/') //higher precedence operators
	{
		return 2;
	}
}


void Infix::set(string infix) //mutator
{
	infixExp = infix;
}


string Infix::get() //accessor
{
	return infixExp;
}


string Infix::toPostfix()
{
	string postfixExp;
	LinkedStack<char> aStack;
	
	for (int i=0; i < infixExp.length(); i++)
	{
		if (infixExp[i] == ' ')
		{
			continue; //spaces considered valid
		}

		//if ch is an operand
		switch (infixExp[i])
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				postfixExp += infixExp[i]; //append operand to end of postfix expression
				break;

			case '(':
				aStack.push(infixExp[i]); //save '(' on stack
				break;
			
			//if ch is an operator
			case '+':
			case '-':
			case '*':
			case '/':
				//process stack operators of greater precedence
				while (!(aStack.isEmpty()) && (aStack.peek() != '(') && 
						(precedence(infixExp[i], aStack.peek()))) 
					{
						char temp = aStack.peek(); //to the end of postfixExp
						postfixExp += temp;	
						aStack.pop();
					}
				aStack.push(infixExp[i]); //save the operator
				break;
					
			case ')': //pop stack until matching '('
				while (aStack.peek() != '(')
					{
						char temp = aStack.peek(); //to the end of postfixExp
						postfixExp += temp;
						aStack.pop(); 
					}
				aStack.pop(); //remove the open parenthesis
				break;
		}
	}

	//Append to postfixExp the operators remaining in the stack
	while (!aStack.isEmpty())
	{
		char temp = aStack.peek(); //to the end of postfixExp
		postfixExp += temp;
		aStack.pop();
	}

	return postfixExp;
}



double Infix::evaluate()
{
	double result = 0;
	LinkedStack<double> aStack;
	string number;

	if (infixExp == "") //An empty expression(empty string) evaluates to zero
		{
			return result;
		}

	string postfixExp = toPostfix(); //assign the postfix value

	for (int i = 0; i < postfixExp.length(); i++)
	{
		switch (postfixExp[i])
		{
		//if ch is an operand
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			number = postfixExp[i];
			aStack.push(stod(number)); //convert string type to double
			break;

		//else if ch is an operator
		default:
			// op2
			double op2 = aStack.peek(); //top of the stack
			aStack.pop(); //pop the stack

			// op1
			double op1 = aStack.peek(); //top of the stack
			aStack.pop(); //pop the stack

			if (postfixExp[i] == '+')
			{
				result = op1 + op2;
			}
			else if (postfixExp[i] == '-')
			{
				result = op1 - op2;
			}
			else if (postfixExp[i] == '*')
			{
				result = op1 * op2;
			}
			else
			{
				if (op2 != 0){
					result = op1 / op2;
				}
				else{
					throw runtime_error("Can't divide by zero!"); //attempt to divide by zero
				}
			}
		aStack.push(result); //push result onto the stack
		break;
		}
	}
	return result;
}


