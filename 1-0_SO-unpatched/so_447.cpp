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
    if (text[i] == ' ')
      if (++i < text.length())
        text[i] = toupper(text[i]);
  }
  return text;
}
___[Sample Run](https://wandbox.org/permlink/i49epWjtDONIHAc6) :___
_Input :_
hello world
foo bar
_Output :_
Hello World
Foo Bar
<hr>
My Version (Requires C++20) : 
cpp
#include <cctype>
#include <iostream>
#include <string>
std::string capitalizeFirstLetter(std::string text) {
  for (bool newWord = true; auto &&i : text) {
    i = newWord ? std::toupper(i) : i;
    newWord = std::isspace(i);
  }
  return text;
}
int main() {
  std::string sentence;
  while (std::getline(std::cin, sentence))
    std::cout << capitalizeFirstLetter(sentence) << std::endl;
}
[Sample Run](https://wandbox.org/permlink/elwLY9eBK4D7otHo)