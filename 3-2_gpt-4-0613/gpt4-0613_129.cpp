#include <fstream>
#include <iostream>

const int MAX_NUMBERS = 4;
const int MAX_DIGITS = 15;

int main() {
  std::ifstream file("numbers.txt");
  if (!file) {
    std::cerr << "Couldn't open the file.";
    return 1;
  }

  char numbers[MAX_NUMBERS][MAX_DIGITS+1] = {0}; // +1 for '\0'
  
  for (int i = 0; i < MAX_NUMBERS; i++) {
    file.getline(numbers[i], MAX_DIGITS+1);
    if (file.fail()) {
      file.clear();
      file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  // print the numbers for testing
  for (int i = 0; i < MAX_NUMBERS; i++) {
    std::cout << numbers[i] << std::endl;
  }

  return 0;
}
