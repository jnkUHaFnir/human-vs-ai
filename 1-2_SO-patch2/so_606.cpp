    int partition(char** arr, int p, int r) 
    {
    	char *pivot = arr[r];
    	int i = p - 1;
    	int j = 0;
    	for(j = p; j <= r; j++) 
    	{
    		if(strcmp(arr[j], pivot) <= 0)
    		{
    			i = i + 1;
    			char *temp = arr[i];
    			arr[i] = arr[j];
    			arr[j] = temp;
    		}
    	}
    
    	if(i < r)
    		return i;
    	else 
    		return i - 1;
    }
    
    void quicksort(char **arr, int left, int right) 
    {
    	if(left < right)
    	{
    		int index = partition(arr, left, right);
    		quicksort(arr, left, index - 1);      
    		quicksort(arr, index + 1, right);
    	}
    }
    
    void print(char **arr, int size)      
    {
    	for(int i = 0; i<size; i++)
    		cout << arr[i] << ", ";
    	cout << "\n";
    }
    
    int main()
    {
    	int n;      
    	cout << "Enter Number of Elements: ";
    	cin >> n;
    	cout << "Enter Elements in Array to be sorted:\n";
    
    	char buf[255];
    
    	char **arr = new char*[n];
    	for(int i = 0; i < n; i++)
    	{
    		cout << "Enter " << i << "th element: ";
    		cin >> buf;
    		arr[i] = strdup(buf);
    	}
    
    	quicksort(arr, 0, (n - 1));
    	cout << "Sorted:\n";
    	print(arr, n);
    	cout << "\n";
    
    	for(int i = 0; i < n; i++)
    		delete[] arr[i];
    	delete[]arr;
    
    	return 0;
    }