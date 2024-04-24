#include <iostream>
using namespace std;

int main() {
    string resp;
    index:
    cout << endl;
    cout << "just an example of course" << endl;
    cout << "type {open} to return to the index\n";
    cin >> resp;
    if (resp == "open") {
        goto index;
    } else if (resp == "exit") {
        return EXIT_SUCCESS;
    }
    return 0;
}
