#include <iostream>

int main() {
  
  double weight = 0.0;
  int planetNum;
  double newWeight = 0.0;
  
  // earth weight
  std::cout << "What is your current Earth Weight : ";
  std::cin >> weight;
  
  // Enter planet you want to fight on
  std::cout << "#	Planet	Relative Gravity\n";
  std::cout << "1	Venus	  0.78 \n";
  std::cout << "2	Mars	  0.39 \n";
  std::cout << "3	Jupiter	2.65 \n";
  std::cout << "4	Saturn	1.17 \n";
  std::cout << "5	Uranus	1.05 \n";
  std::cout << "6	Neptune	1.23 \n";
  std::cout << "Enter the planet # you want to fight on : ";
  std::cin >> planetNum;
  
  switch(planetNum)
  {
    case 1 :
      newWeight = weight * 0.78;
      break;
    case 2 :
      newWeight = weight * 0.39;
      break;
    case 3 :
      newWeight = weight * 2.65;
      break;
    case 4 :
      newWeight = weight * 1.17;
      break;
    case 5 :
      newWeight = weight * 1.05;
      break;
    case 6 :
      newWeight = weight * 1.23;
      break;
    default :
      newWeight = weight;
      break;
  }
  
  std::cout << "Your planet weight will be " << newWeight << "\n";
}