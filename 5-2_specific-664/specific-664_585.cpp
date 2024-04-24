#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char resp[20]; // Assuming the input will be less than 20 characters
    index:
    cout << endl;
    cout << "just an example of course" << endl;
    cout << "type {open} to return to the index\n";
    cin >> resp;
    
    if (strcmp(resp, "open") == 0) {
        goto index;
    }
    else {
        return EXIT_SUCCESS;
    }
}
