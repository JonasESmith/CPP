#include <iostream>

int main() 
{
    int conditionalSwitch = 3;

    // get user input
    std::cout << "Enter a number in the range of 0-10 : ";
    std::cin >> conditionalSwitch;

    if(conditionalSwitch > 3)
    {
        std::cout << "Andrew is a nerd >:)";
    }
    else if (conditionalSwitch < 3)
    {
        std::cout << "Jonas is a nerd >:(";
    }
    else
    {
        std::cout << "Neither is a nerd :)";
    }
}