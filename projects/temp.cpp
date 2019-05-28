#include <iostream>


int main() {
  
  double tempf;
  double tempc;
  
  // Ask the user
  std::cout << "Please enter the current temperature : ";
  std::cin >> tempf;
  
  // conversion
  tempc = (tempf - 32) / 1.8;
  
  std::cout << "The temp is " << tempc << " degrees Celsius.\n";
  
}