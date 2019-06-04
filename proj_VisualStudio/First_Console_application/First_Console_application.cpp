// ProgramName    : First_Console_application.cpp 
// ProgrammerName : Jonas Smith
// Purpose		  : Learn C++

#include <iostream>
#include <cmath>


int main()
{
	bool keepIterating = true;

	while (keepIterating)
	{
		std::cout << "Enter number of iterations:";

		int IterationValue;
		std::cin >> IterationValue;

		// this method very basically takes the input of i and squares it until it reaches the threshold of the last iterationValue.
		for (int i = 0; i < IterationValue; i++)
		{
			std::cout << pow(i, 2) << "\n";
		}

		char userInput;
		bool continueBool = true;

		while (continueBool)
		{
			std::cout << "would you like to continue? (y/n) : ";
			std::cin >> userInput;

			if (userInput == 'y')
			{
				keepIterating = true;
				continueBool  = false;
			}
			else if (userInput == 'n')
			{
				keepIterating = false;
				continueBool  = false;
			}
			else
			{
				continueBool = true;
			}
		}
	}
}

