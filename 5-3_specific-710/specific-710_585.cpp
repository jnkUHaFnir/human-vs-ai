#include <iostream>
#include <cstring> // For strcmp function

using namespace std;

int main(){
    char resp[10]; // Allowing space for 9 characters + null terminator
    index:
    cout<<endl;
    cout<<"just an example of course"<<endl;
    cout<<"type {open} to return to the index\n";
    cin>>resp;

    if (strcmp(resp, "open") == 0){
        goto index;
    }
    else if (atoi(resp) == 2) { // Convert string to integer for comparison
        return EXIT_SUCCESS;
    }

    return 0;
}
