cpp
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string capitalizeFirstLetter(string text);
int main() {
  char sentence[100];
  while (cin.getline(sentence, 100))
    cout << capitalizeFirstLetter(sentence) << '\n';
}
string capitalizeFirstLetter(string text) {
  for (string::size_type i = 0; i < text.length(); i++) {
    if (i == 0)
      text[i] = toupper(text[i]);
    if (text[i] == ' ') {
      ++i;
      if (i < text.length())
        text[i] = toupper(text[i]);
    }
  }
  return text;
}
___[Sample Run](https://wandbox.org/permlink/sUueskpQkWscnVwK) :___
_Input :_
hello world
foo bar
_Output :_
Hello World
Foo Bar
<hr>
My Version : 
cpp
#include <cctype>
#include <iostream>
#include <string>
std::string capitalizeFirstLetter(std::string text) {
  bool newWord = true;
  for (auto &&i : text) {
    if (newWord) {
      i = std::toupper(i);
      newWord = false;
    }
    if (std::isspace(i))
      newWord = true;
  }
  return text;
}
int main() {
  std::string sentence;
  while (std::getline(std::cin, sentence))
    std::cout << capitalizeFirstLetter(sentence) << std::endl;
}
[Sample Run](https://wandbox.org/permlink/jUuZwJ42256tBRCM)