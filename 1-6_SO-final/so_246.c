	#include <time.h>
	#include <xmmintrin.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#define NUMBER_OF_VALUES 33554432
	int main()
	{
	    int *values;
	    int result = posix_memalign((void *)&values, 16, NUMBER_OF_VALUES * sizeof(int));
	    if (result)
	    {
		printf("Failed to mem allocate \n");
		exit(-1);
	    }
	    clock_t start, end;
	    start = clock();
	    memset(values, 0, sizeof(int) * NUMBER_OF_VALUES);
	    end = clock();
	    printf("memset time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    start = clock();
	    {
	    	int index = 0;
		char *temp = (char *)values;
		for(; index < NUMBER_OF_VALUES * sizeof(int); index++)
		    temp[index] = 0;
	    }
	    end = clock();
	    printf("char-wise for-loop array indices time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    start = clock();
	    {
		int index = 0;
		int *temp = values;
		for (; index < NUMBER_OF_VALUES; index++)
		    temp[index] = 0;
	    }
	    end = clock();
    
	    printf("int-wise for-loop array indices time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    start = clock();
	    {
	        int index = 0;
	        long long int *temp = (long long int *)values;
	        for (; index < NUMBER_OF_VALUES/2; index++)
		    temp[index] = 0;
	    }
	    end = clock();
    
	    printf("long-long-int-wise for-loop array indices time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    start = clock();
	    {
	       int index = 0;
		__m128 zero = _mm_setzero_ps();
		for (; index < NUMBER_OF_VALUES; index += 4)
		    _mm_store_ps((float *)(&values[index]), zero); // zero is represented the same in either float or int
	    }
	    end = clock();
	    printf("SSE-wise for-loop array indices time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    start = clock();
	    {
		char *temp = (char *)values, *max = (char *)(values + NUMBER_OF_VALUES);
		while (temp < max)
		    *temp++ = 0;	    
	    }
	    end = clock();
	    printf("char-wise while-loop pointer arithmetic time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    start = clock();
	    {
		int *temp = values, *max = values + NUMBER_OF_VALUES;
		while (temp < max)
		    *temp++ = 0;
	    }
	    end = clock();
	    printf("int-wise while-loop pointer arithmetic time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    start = clock();
	    {
		long long int *temp = (long long int *)values, *max = (long long int *)(values + NUMBER_OF_VALUES);
		while (temp < max)
		    *temp++ = 0;
	    }
	    end = clock();
	    printf("long-ling-int-wise while-loop pointer arithmetic time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    free(values);
	    return 0;
	}