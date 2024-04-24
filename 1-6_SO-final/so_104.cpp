    void backword(char* input, char output[][30])
    {
    	int index_c = 0;
    	for (int i = 0, c = 0; strlen(input)>i; i++)
    	{
    
    		if (input[i] == ' ')
    		{
    			output[c][index_c++] = '\0'; // add end of string symbol
    			c++;
    			index_c = 0;
    		}
    		output[c][index_c++] = input[i];
    	}
    	cout << output[1]; //debug
    }
    
    int main()
    {
    	char output[30][30];
    	backword("dfs sdfsdfsd dsffsdf", output);
    	cout << output[1]; //dubug
    	return 0;
    }