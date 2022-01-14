/**
* [Suha Cho]
* [Infix.h]
**/

#ifndef INFIX_H
#define INFIX_H

#include "LinkedStack.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

class Infix
{
private:
	string infixExp; //The infix expression. Should default to empty string.

	 /**
	 * precedence is a private method that determines the precedence 
	   between two operators given as chars.
	 * @param first is first operator.
	 * @param second is second operator.
	 * @return true if the first operator is of less or equal precedence 
			   to the second operator; otherwise, false.
	 */
	bool precedence(char first, char second);

	/**
	 * getPrecedence is a private method that returns a number 
	   that represents the precedence of operation.
	 * @param opr is given operator.
	 * @return 1 if the given operator is equal to '+' or '-'; if it's equal to '*' or '/' return 2.
	 * @pre this helper function should be used when other methods that need the precedence of operation.
	 */
	int getPrecedence(char opr);

public:
	Infix(); //default constructor
	Infix(string infix); //constructor to set the initial value of infixExp.
	void set(string infix); //Mutator method for infixExp.
	string get(); //Accessor method for infixExp.

	/**
	 * toPostfix is a method to store infix expression in postfix.
	 * @return the stored infix expression in postfix notation.
	 * @pre the infix expressions will be made up of only integers 0 to 9 and the operators will be *, /, +, and –.
	 *		the expressions should be properly written infix with no errors.
	 *		it should handle use or lack of spaces properly.
	 */
	string toPostfix();

	/**
	 * evaluate is a function that converts the infix expression into postfix notation and evaluates it.
	 * @return the evaluated result in postfix notation.
	 * @pre this function should detect an attempt to divide by zero and throw exception.
	 */
	double evaluate();
};

#endif
