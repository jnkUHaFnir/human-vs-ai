cpp
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
string capitalizeFirstLetter(string text);
int main() {
  char sentence[100];
  for (;;) {
    cin.getline(sentence, 100);
    if (strcmp(sentence, "0"))
      capitalizeFirstLetter(sentence);
    else
      break;
  }
  return 0;
}
string capitalizeFirstLetter(string text) {
  for (string::size_type i = 0; i < text.length(); i++) {
    if (i == 0) {
      text[i] = toupper(text[i]);
    }
    if (text[i] == ' ') {
      ++i;
      if (i < n)
          text[i] = toupper(text[i]);
    }
  }
  cout << text;
  return text;
}
[Sample Run](https://wandbox.org/permlink/bIcpmwzJaFQTJ1r3)
<hr>
My Version : 
cpp
#include <cctype>
#include <iostream>
#include <string>
std::string capitalizeFirstLetter(std::string text) {
  bool newWord = true;
  for (auto &&i : text)
    if (newWord) {
      i = std::toupper(i);
      newWord = false;
    } else if (i == ' ')
      newWord = true;
  return text;
}
int main() {
  std::string sentence;
  while (std::getline(std::cin, sentence))
    std::cout << capitalizeFirstLetter(sentence) << std::endl;
}
[Sample Run](https://wandbox.org/permlink/KlCaQU79ulxhTyMA)