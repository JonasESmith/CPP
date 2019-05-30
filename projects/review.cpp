#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {2,4,3,6,1,9};
  int evenSum = 0;
  int oddPrd = 1;
  for(int i = 0; i < numbers.size(); i++)
  {
    if(numbers[i] % 2 == 0)
    {
      evenSum += numbers[i];
    }
    else
    {
      oddPrd = oddPrd * numbers[i];
    }
  }
  
  std::cout << "Sum of even numbers is " << evenSum << "\n";
  std::cout << "Product of odd numbers is " << oddPrd;
}