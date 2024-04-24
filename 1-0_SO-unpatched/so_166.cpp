    #include <iostream>
    #include <cstdlib>
    #include <vector>
    #include <algorithm>
    using namespace std;
    
    int main(){
        string m;
        int n;
        cout << "How many elements would you like to sort?" << endl;
        cin >> n;  //index for the array
        cout << "Enter " << n << " numbers seperated by a comma to be sorted" <<   endl;
        cin >> m;
        
        
        //string c[n]={m};
        vector<int> unsortedNumbers;
        const char* p=m.c_str();
        int i=0;
        while(i<n){
            i++;
            unsortedNumbers.push_back(atoi(p));
            while(*p>='0'&&*p<='9') p++;
            if(i<n)p++;
        }
        //std::sort(m.begin() , m.end());  //sorting string m
        sort(unsortedNumbers.begin(), unsortedNumbers.end());
        for_each(unsortedNumbers.begin(), unsortedNumbers.end(), [](int x){cout<<x<<" ";});
        //now we have a sorted array and its type is double[]
        char arr[n][m.length()];
        for(int i=0;i!=n;i++) {
            if(i!=n-1) sprintf(arr[i],"%d,",unsortedNumbers[i]);
            else sprintf(arr[i],"%d",unsortedNumbers[i]);
        }
        m.clear();
        for(auto i:arr)  m+=i;
        cout<<m;
    }