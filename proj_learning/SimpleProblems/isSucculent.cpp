#include <iostream>

// Define needs_water() here:

std::string needs_water(int days, bool is_succulent)
{
  std::string returnValue = "";
  
  if(is_succulent == false && days > 3)
  {
    returnValue = "Time to water the plant.";
  }
  else if (is_succulent && days <= 12)
  {
    returnValue = "Don't water the plant!";
  }
  else if (is_succulent && days >= 13)
  {
    returnValue = "Go ahead and give the plant a little water.";
  }
  else
  {
    returnValue = "Don't water the plant!";
  }
  
  return returnValue;
}


int main() {
  
  std::cout << needs_water(10, false) << "\n";
  
}