// ProgramName    : Element_in_vector.cpp 
// ProgrammerName : Jonas Smith
// Purpose        : Find element in vector.

#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h> // this allows us to use Random! :) 
#include <time.h>   // time 

int main()
{	/* initialize random seed: */
	srand(time(NULL));

	int dimOfArray = rand() % 1000;

	std::vector<int> intVector;

	for (int i = 0; i < dimOfArray; i++)
	{
		intVector.push_back(i * rand() % 100);
	}

	// o
	std::cout << "Size of array : " << dimOfArray;

	// init new vecotr to count each element, and update the total corresponding number.
	std::vector< std::vector <int> > totalNumVector;

	bool existsInVector;

	for (int i = 0; i < intVector.size(); i++)
	{
		int totalNumVectorSize = totalNumVector.size();

		existsInVector = false;

		for (int j = 0; j < totalNumVectorSize; j++)
		{
			if (intVector[i] == totalNumVector[j][0])
			{
				// increments the value inside the second position of each nested vector
				totalNumVector[j][1]++;
				existsInVector = true;
			}
		}

		if (!existsInVector)
		{
			// adds a new vector to the list of vectors
			totalNumVector.push_back(std::vector<int>());

			// then it inits the vecotr values with the value of the corresponding vecotr and the count 
			totalNumVector[totalNumVector.size() - 1].push_back(intVector[i]);
			totalNumVector[totalNumVector.size() - 1].push_back(1);
		}
	}

	// sort array descending
	int temp = 0;

	for (int i = 0; i < totalNumVector.size(); i++)
	{
		for (int j = i + 1; j < totalNumVector.size(); j++)
		{
			if (totalNumVector[i][0] < totalNumVector[j][0])
			{
				temp = totalNumVector[i][0];
				totalNumVector[i][0] = totalNumVector[j][0];
				totalNumVector[j][0] = temp;
			}
		}
	}

	for (int i = 0; i < totalNumVector.size(); i++)
	{
		std::cout << totalNumVector[i][0] << " " << totalNumVector[i][1] << "\n";
	}
}

// this definitely doesn't work :) 
template <typename T>
T console(T message)
{
	std::cout << message << "\n";
}