#include <string>
#include <iostream>

int main()
{
    char* str = "123";
    std::string s(str);
    try {
        int num = std::stoi(s);
        // Use num variable
    }
    catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
``` 

In the above code, we first convert the character array into a string and then pass it to std::stoi() function. If the conversion succeeds, it returns the integer value, otherwise it throws an std::invalid_argument or std::out_of_range exception which we catch and print an error message.

Using this method provides robust and clear error handling instead of returning zero which can easily cause errors and confusion in the program.
