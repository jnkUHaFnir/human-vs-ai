    #include <stdio.h>
    #include <stdlib.h>
    
    #ifdef MOCKING
    
    // load this struct with all functions protoypes to mock
    static struct mock_t {
    	void (*dummy)(void);
    } m;
    
    // a mocking function
    void mocked_dummy()
    {
    	printf("__%s__()\n",__func__);
    }
    
    // define all the "reset" values for mock
    void init_mocks(void)
    {
    	m.dummy = mocked_dummy;
    }
    
    // Last, enable all the functions to mock
    // Note: This needs to be done after all of the above, or your
    // pre-processor is likely to cause havok.
    #define dummy (m.dummy)
    
    #endif
    /*---- do not modify ----*/
    void dummy(void)
    {
        printf("__%s__()\n",__func__);
    }
    
    int factorial(int num) 
    {
        int                      fact = 1;
        printf("__%s__()\n",__func__);
        while (num > 1)
        {
            fact *= num;
            num--;
        }
        dummy();
        return fact;
    }
    /*---- do not modify ----*/
    
    int main(int argc, char * argv[])
    {
        #ifdef MOCKING
        init_mocks();
        #endif
        int (*fp)(int) = atoi(argv[1]);
        printf("fp = %x\n",fp);
        printf("factorial of 5 is = %d\n",fp(5));
        printf("factorial of 5 is = %d\n",factorial(5));
        return 1;
    }