	#include <iostream>
	using namespace std;
	int main(){
		char resp[10]; //Fix 1
		int jawab;
		index:
		cout<<endl;
		cout<<"just an example of course"<<endl;
		cout<<"type {open} to return to the index\n";
		cin>>resp;
		if (strcmp(resp,"open")==0){ //Fix 2, Use strcmp
			goto index;
		}
		else if(jawab == 2)
        {
			return EXIT_SUCCESS;
		}
	}