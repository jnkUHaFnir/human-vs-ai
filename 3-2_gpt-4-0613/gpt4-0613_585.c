This should work better for you. Please note that, when you enter a number (2), it should be in string format ("2"), not an integer number (2). 

And also "goto" is generally discouraged in modern c++ as it can make code less readable and maintainable. Consider using a loop, such as a 'while' or 'do-while' loop, instead. 

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string resp;

    do {
        cout << "\njust an example of course" << endl;
        cout << "type {open} to return to the index\n";
        cin >> resp;
    } while (resp == "open");

    if(resp == "2")
    {
        return EXIT_SUCCESS;
    }
}
