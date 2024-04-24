#include <iostream>
#include <string> // Include for std::string

using namespace std;

int main() {
    string resp; // Change type from char to std::string
    index:
    cout << endl;
    cout << "Just an example of course" << endl;
    cout << "Type 'open' to return to the index \n";
    cin >> resp;

    if (resp == "open") {
        goto index; // Not generally recommended, but works for your example
    } 
    else if (resp == "2") { // Notice the comparison is with a string "2" not integer 2
        return EXIT_SUCCESS;
    }
}
