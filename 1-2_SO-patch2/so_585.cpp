	#include <iostream>
	using namespace std;
	int main(){
		std::string resp; //Fix 1
		int jawab;
		index:
		cout<<endl;
		cout<<"just an example of course"<<endl;
		cout<<"type {open} to return to the index\n";
		cin>>resp;
		if (resp =="open"){ //Fix 2
			goto index;
		}
		else if(jawab == 2)
	    {
			return EXIT_SUCCESS;
		}
	}
	