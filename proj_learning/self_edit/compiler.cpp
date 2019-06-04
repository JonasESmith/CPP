#include <iostream>
#include <fstream> // file stream for reading the main.cpp file
#include <string>  // allows us to use getline
#include <vector>  // allows us to user vectors... duh

// allows us to skip using std::
using namespace std;

std::string removeSpaces(string inputValue);
void addToList(int i, string newLine);
void writeToFile();

vector<string> codeVector;

int main() {
    // I want this to get all content from main.cpp and rewrite and compile it 
    ofstream mainFile;

    string line;
    ifstream myFile("main.cpp");
    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
            // adds the line of code to the string vector.
            // with this we can interpret the code and determine what to do with it
            codeVector.push_back(line);
        }
    }

    myFile.close();

    int lineToAdd;
    string lineBefore = "{";
    // this is very basic but adds a basic output string
    for(int i = 0; i < codeVector.size(); i++)
    {
        if( removeSpaces( codeVector[i]) == removeSpaces( lineBefore))
        {
            lineToAdd = i++;
        }
    }


    // adds the new line to list
    addToList(lineToAdd, "std::cout << \"this line was added \\n\";");


    for (int i = 0; i < codeVector.size(); i++)
    {
        std::cout << codeVector[i] << "\n";
    }

    writeToFile();

    return 0;
}

std::string removeSpaces(string inputValue)
{
    string valueWithoutSpaces;

    for(int i = 0; i < inputValue.size(); i++)
        if(inputValue[i] != ' ')
            valueWithoutSpaces += inputValue[i];

    return valueWithoutSpaces;
}

void addToList(int index, string newLine)
{
    codeVector.push_back("");

    for(int i = codeVector.size() - 1; i > index; i--)
    {
        codeVector[i] = codeVector[i-1];
    }

    codeVector[index + 1] = newLine;
}

void writeToFile()
{
    std::ofstream outPutFile;

    outPutFile.open("main.cpp");

    for(int i = 0 ; i < codeVector.size(); i++)
    {
        outPutFile << codeVector[i] << "\n";
    }

    outPutFile.close();
}