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
      text[i] = toupper(text[i]);
    }
  }
  cout << text;
  return text;
}
[Sample Run](https://wandbox.org/permlink/bIcpmwzJaFQTJ1r3)