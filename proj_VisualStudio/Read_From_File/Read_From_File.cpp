// Read_From_File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <vector>
#include <fstream> // this is included to allow me to open and read from files
#include <string>
#include <stdio.h> // allows us to use printf
#include <sstream> // allows us to use ostringstream to format strings without sprintf

// this allows me to  avoid using std:: for class calls like Class_Name::Property/Function
using namespace std; 

// this is a decleration for the compiler to know which functions can be called! 
void writeToFile(std::string input_string);
void readFile();
void addStringToVector();



int main()
{
	std::ostringstream fileString;

	// constructs string to output to file!
	for (int i = 0; i < 10; i++)
	{
		fileString << i << " : Output to file!" << endl;
	}
	
	
	writeToFile(fileString.str());

	readFile();

	return 0;
}

void writeToFile(std::string input_string)
{
	ofstream myFile;

	// std::ios::app is the open mode "append" meaning that new data will be written to the end of the file!
	myFile.open("example.txt", std::ios::app);

	myFile << input_string << endl;
}

void readFile()
{
	string line;

	// input file stream
	ifstream myFile("example.txt");
	if (myFile.is_open())
	{
		// getLine(fileName, variable) will input the line into the variable you choose. 
		while (getline(myFile, line))
		{
			cout << line << '\n';
		}

		myFile.close();
	}
	else
	{
		cout << "Unable to open the file";
	}
}

// will add the entire file to a vector so when we save the file we can rewrite it.
void addStringToVector()
{

}