#include <iostream>
#include <string>  // include the string library

using namespace std;

int main(){
    string resp;  // use string data type instead of char
    index:
    cout<<endl;
    cout<<"just an example of course"<<endl;
    cout<<"type {open} to return to the index\n";
    cin>>resp;
    if (resp == "open"){  // use double quotes for strings
        goto index;
    }
    else if(resp == "2"){  // use quotes for numbers too
        return EXIT_SUCCESS;
    }

}
