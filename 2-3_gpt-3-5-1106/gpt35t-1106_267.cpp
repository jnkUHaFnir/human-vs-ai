#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::string inputString = "Hello, World!";
  char formattedString[100];
  sprintf(formattedString, "The input string is: %s", inputString.c_str());
  
  std::ofstream file("output.txt");
  file << formattedString << std::endl;
  file.close();
  
  return 0;
}
