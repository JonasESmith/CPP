#include <iostream>
#include <fstream> // file stream for reading the main.cpp file
#include <string>  // allows us to use getline
#include <vector>  // allows us to user vectors... duh

// allows us to skip using std::
using namespace std;


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

    return 0;
}