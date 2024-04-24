#include <iostream>
using namespace std;

int main(){
    string resp;
    index:
    cout<<endl;
    cout<<"Just an example, of course"<<endl;
    cout<<"Type {open} to return to the index\n";
    cin>>resp;
    if (resp == "open"){
        goto index;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    string resp;

    do {
        cout<<endl;
        cout<<"Just an example, of course"<<endl;
        cout<<"Type {quit} to exit. Type {open} to do it again.\n";
        cin>>resp;
    } while (resp == "open");

    return 0;
}
