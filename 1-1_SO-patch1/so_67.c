    #include <stdio.h>
    #include <stdlib.h>
    #include <mpi.h>
    #define BUF_SIZE 4
    
    int main(int argc, char **argv)
    {
    	int rank, size;
    
    	MPI_Init(&argc,&argv);
    	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    	MPI_Comm_size(MPI_COMM_WORLD, &size);
    	
    	int *intab, *sendcounts, *displs;
    	sendcounts = malloc(size * sizeof(int)); 
    	displs = malloc(size * sizeof(int)); 
    	int displacement = 0;
    	int sendcounts_particular = 0;
    
    	// every rank will get its own chunk of data, but all will get SAME copy
    	for(int i=0; i < size; i++)
    	{
    		if(sendcounts_particular < BUF_SIZE)
    		{
    			sendcounts_particular++; 
    		}
    		else
    		{
    			sendcounts_particular = 1; 
    		}
    		*(sendcounts + i) = sendcounts_particular;
    	}
    
    	// fixed size buffer for each rank
    	int *rcvbuf = malloc(BUF_SIZE * sizeof(int)); 
    
    	// root node will initialize input array of data and displacements when only root needs them for Scatter
    	if(!rank)
    	{
    		int f = 0, mainindex = 0;
    		intab = malloc(size * BUF_SIZE * sizeof(int)); 
    
    		// generating input data array
    		for(int i=0; i < size; i++)
    		{
    			for(int j=0; j < BUF_SIZE; j++)
    			{
    				*(intab+mainindex) = 1*f;
    				mainindex++;
    			}
    			f += 10;
    		}
    	
    		// initializing displacements array, every BUF_SIZE fields for each rank
    		for(int i=0; i < size; i++)
    		{
    			*(displs + i) = displacement;
    			displacement += BUF_SIZE;
    		}
    		
    		// debug block to see values
    		for(int i=0; i < size; i++)
    		{
    			printf("displs[%i] = %i, sendcounts[%i] = %i\n", i, *(displs+i), i, *(sendcounts+i));
    		}
    		putchar('\n');
    
    		for(int i=0; i < mainindex; i++)
    		{
    			printf("%i ", *(intab + i));
    		}
    		putchar('\n');
    	}
    
    	MPI_Scatterv(intab, sendcounts, displs, MPI_INT,rcvbuf, BUF_SIZE, MPI_INT, 0, MPI_COMM_WORLD);
    
       	printf("this is proces %i, got: sendcounts %i, &sendcounts %p\n", rank, *(sendcounts + rank), sendcounts);
    
    	for(int i=0; i < BUF_SIZE; i++)
    	{
    		printf("Process %i my %i buffer value is %i\n ", rank, i, *(rcvbuf + i));
    	}
    	MPI_Finalize();
    
    	return 0;
    			
    }