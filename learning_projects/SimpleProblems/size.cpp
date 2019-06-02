#include <iostream>
#include <vector>

int main() {
  
  std::vector<std::string> grocery = {"Hot Pepper Jam", "Dragon Fruit", "Brussel Sprouts"};
    
  
  // Add more 
  grocery.push_back("Chicken Breast");
  grocery.push_back("Broccoli");
  grocery.push_back("Sweat Potatoes");
  
  std::cout << grocery.size() << "\n";
  
}