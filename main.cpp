#include <iostream>
#include "Infix.h"

void displayTest(Infix& infix);
void printLine(int length);

int main()
{
	Infix tester;
	std::string testStrings[] = {
		"",
		"1+2-3",
		"(4 + 5) * 6",
		"(7 + 8) * (9 - 0)",
		"8 + 9 * (0 + 1) - 2 / 3 * 4 + 5",
		"1 + ((2 + 3) * (4 - 5) - 6) / (7 - 7)" };

	for (auto test : testStrings)
	{
		try
		{
			printLine(60);
			tester.set(test);
			displayTest(tester);

		}
		catch (std::runtime_error& e)
		{
			std::cout << "ERROR: " << e.what() << std::endl;
		}
	}

	return 0;
}

void displayTest(Infix& infix)
{

	std::cout << "Infix Expression: " << infix.get() << std::endl;
	std::cout << "Postfix Expression: " << infix.toPostfix() << std::endl;
	std::cout << "Evaluated: " << infix.evaluate() << std::endl;

}

void printLine(int line)
{
	std::cout << std::endl;

	for (int i = 1; i <= line; i++)
	{
		std::cout << "=";
	}

	std::cout << std::endl << std::endl;
}