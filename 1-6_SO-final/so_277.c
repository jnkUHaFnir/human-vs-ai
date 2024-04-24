    int sort(int N, struct Foo *array)
    {
    	int temp;
    	int i, j;
    	for (i = 0; i< N; i++) {
    		for (j = i; j < N; j++) {
    			if (array[j].fieldint < array[j - 1].fieldint) {
    				temp = array[j - 1].fieldint;
    				array[j - 1].fieldint = array[j].fieldint;
    				array[j].fieldint = temp;
    			}
    		}
    	}
    	return 0;
    }
    
    int main()
    {
    	int number = 3;
    	struct Foo arr[number];
    	int i;
    	for (i = 0; i < number; i++)
    	{
    		arr[i].fieldint = rand(); //random number
    		arr[i].fieldchar = 'A' + (char)(rand() % 26); //random letter
    		arr[i].fieldfloat = (float)i;
    	}
    
    	sort(number, arr);
    	for (i = 0; i < number; i++)
    		printf("Structure %d:\nfield int:%d\nfield char:%c\nfield float:%f\n\n",
    			i + 1, arr[i].fieldint, arr[i].fieldchar, arr[i].fieldfloat);
    	getch();
    	return 0;
    }