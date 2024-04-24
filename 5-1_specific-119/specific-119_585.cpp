#include <iostream>

using namespace std;

int main(){
    char resp[10]; // Assuming the maximum input length is 10 characters
    index:
    cout << endl;
    cout << "just an example of course" << endl;
    cout << "type 'open' to return to the index" << endl;
    cin >> resp;

    if (strcmp(resp, "open") == 0) {
        goto index;
    }
    else if (strcmp(resp, "exit") == 0) {
        return EXIT_SUCCESS;
    }
    
    return 0;
}
