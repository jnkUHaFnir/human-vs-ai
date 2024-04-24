#include <regex>
#include <string>

// ...

// Assuming you've already obtained the data through libcurl
std::string data = /* ... */;

// Only keep letters, digits, and spaces
std::regex pattern("[^a-zA-Z0-9 ]+");
data = std::regex_replace(data, pattern, "");

// Remove line breaks (replace with spaces)
data = std::regex_replace(data, std::regex("[\r\n]+"), " ");
