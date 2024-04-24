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
	    	int index = 0, total = NUMBER_OF_VALUES * sizeof(int);
		char *temp = (char *)values;
		for(; index < total; index++)
		    temp[index] = 0;
	    }
	    end = clock();
	    printf("char-wise for-loop array indices time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    start = clock();
	    {
		int index = 0, *temp = values, total = NUMBER_OF_VALUES;
		for (; index < total; index++)
		    temp[index] = 0;
	    }
	    end = clock();
    
	    printf("int-wise for-loop array indices time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    start = clock();
	    {
	        int index = 0, total = NUMBER_OF_VALUES/2;
	        long long int *temp = (long long int *)values;
	        for (; index < total; index++)
		    temp[index] = 0;
	    }
	    end = clock();
    
	    printf("long-long-int-wise for-loop array indices time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    start = clock();
	    {
	       int index = 0, total = NUMBER_OF_VALUES/4;
		__m128i zero = _mm_setzero_si128();
		__m128i *temp = (__m128i *)values;
		for (; index < total; index++)
		    temp[index] =  zero; 
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
	    start = clock();
	    {
		 __m128i zero = _mm_setzero_si128();
	        __m128i *temp = (__m128i *)values, *max = (__m128i *)(values + NUMBER_OF_VALUES);
		while (temp < max)
		    *temp++ = zero;
	    }
	    end = clock();
	    printf("SSE-wise while-loop pointer arithmetic time %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	    free(values);
	    return 0;
	}