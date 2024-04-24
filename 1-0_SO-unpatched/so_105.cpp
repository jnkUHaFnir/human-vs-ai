    void backword(char* input, char output[][30])
    {
    	int index_c = 0;
    	int c = 0;
    	for (int i = 0;  strlen(input) > i; i++)
    	{
    
    		if (input[i] == ' ')
    		{
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
        memset(output, 0, sizeof(output));
    	backword("dfs sdfsdfsd dsffsdf", output);
    	cout << output[1]; //dubug
    	return 0;
    }