#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char resp[20]; // Assuming the input won't exceed 20 characters

    while(true){
        cout<<endl;
        cout<<"just an example of course"<<endl;
        cout<<"type 'open' to return to the index\n";
        cin.ignore(); // Ignore any characters in the input buffer
        cin.getline(resp, 20); // Read a line of input
        
        if (strcmp(resp, "open") == 0){  // Compare the strings
            continue; // Go back to the index
        }
        else if(strcmp(resp, "quit") == 0){
            return EXIT_SUCCESS;
        }
    }

    return 0;
}
