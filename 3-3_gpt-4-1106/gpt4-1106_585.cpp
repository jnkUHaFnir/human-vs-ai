#include <iostream>
#include <string> // Include this to use std::string

using namespace std;

int main() {
    string resp; // Use std::string instead of char

index:
    cout << endl;
    cout << "Just an example of course" << endl;
    cout << "Type {open} to return to the index\n";
    cin >> resp; // This will read a single word into the string
    if (resp == "open") { // Compare string to another string
        goto index;
    }
    else if (resp == "2") { // Now you're comparing strings, so put 2 in quotes
        return EXIT_SUCCESS;
    }

    return 0; // It's good practice to return 0 at the end of main if the program ends successfully
}
#include <iostream>
#include <string>

using namespace std;

int main() {
    string resp;

    while (true) {
        cout << endl;
        cout << "Just an example of course" << endl;
        cout << "Type 'open' to continue or '2' to exit:\n";
        getline(cin, resp); // If you want to read entire lines, including spaces
        if (resp == "open") {
            continue; // Loop continues, which will effectively go back to the start
        }
        else if (resp == "2") {
            break; // Exit the loop and the program. Equivalent to return EXIT_SUCCESS;
        }
    }

    return 0;
}
