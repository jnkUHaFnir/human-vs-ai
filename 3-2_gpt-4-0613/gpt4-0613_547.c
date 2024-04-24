C++ Code to handle this issue:

```cpp
#include<iostream>

using namespace std;

int main()
{
    int i=0, j=0;

    do
    {
        ++j;
        cin >> i;
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nInvalid Input. Try Again.\n\n";
        }
        else
            cout << "\n\n"<< i <<" " << j <<"\n\n";
    }
    while((i!=8) && (j<10));

    cout<<"\nj = "<<j<<"\n";
}   


