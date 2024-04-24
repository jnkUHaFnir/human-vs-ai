#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string data = "Your string with\nnew lines, and symbols! 123";
    std::regex regexPattern("[^a-zA-Z0-9 ]"); // Matches anything that is NOT a letter, number, or space
    
    // Replace matched characters with nothing (effectively removing them)
    std::string cleanedData = std::regex_replace(data, regexPattern, ""); 
    
    std::cout << cleanedData << std::endl;
    
    return 0;
}

The `re.sub` function searches for all characters not included in the set `a-zA-Z0-9 ` and replaces them with an empty string, effectively removing them.

### JavaScript

In JavaScript, you can achieve this with the `String.prototype.replace()` method combined with a regular expression:

```javascript
let data = "Your string with\nnew lines, and symbols! 123";
let cleanedData = data.replace(/[^a-zA-Z0-9 ]/g, '');

console.log(cleanedData);
