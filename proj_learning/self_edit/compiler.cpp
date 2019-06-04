#include <iostream>
#include <fstream> // file stream for reading the main.cpp file
#include <string>  // allows us to use getline
#include <vector>  // allows us to user vectors... duh

// allows us to skip using std::
using namespace std;

std::string removeSpaces(string inputValue);

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

    string lineBefore = "{";

    for(int i = 0; i < codeVector.size(); i++)
    {
        cout << codeVector[i] << "\n";
        if( removeSpaces( codeVector[i]) == removeSpaces( lineBefore))
        {
            cout << "    // They are equal!\n";
        }
    }

    int i;
    printf ("Checking if processor is available...");
    if (system(NULL)) puts ("Ok");
        else exit (EXIT_FAILURE);
    printf ("Executing command DIR...\n");
    i=system ("dir");
    printf ("The value returned was: %d.\n",i);
     printf ("Executing command ./main...\n");
    i=system ("psexec -i -s main.exe");
    printf ("The value returned was: %d.\n",i);
    
    cout << i << "\n";

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