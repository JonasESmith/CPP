#include <iostream>

// Define is_palindrome() here:

bool is_palindrome(std::string text)
{
  bool Value;

  if(text.size() % 2 == 0)
  {
    Value = true;
  }
  else
  {
    for(int i = 0; i < (text.size() / 2); i++)
    {
      if(text[i] != text[text.size() - i] && i != text.size() - 1)
        Value = false;
      else
        Value = true;
    }
  }
}

int main() {
  std::cout << is_palindrome("madam") << "\n";
  std::cout << is_palindrome("ada") << "\n";
  std::cout << is_palindrome("lovelace") << "\n";
}