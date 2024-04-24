#include <string>
#include <cctype>

std::string filterData(const std::string& input) {
  std::string filteredData;
  for (const char c : input) {
    if (isalnum(c) || c == ' ') {
      filteredData += c;
    }
  }
  return filteredData;
}
std::string dataFromWebPage = "This is exa\nmpl!e da\nta123";
std::string filteredData = filterData(dataFromWebPage);
