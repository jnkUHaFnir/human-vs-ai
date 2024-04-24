    #include <stdio.h>
    #include <stdlib.h>
    #include <mpi.h>
    #define DISPLACEMENT_SIZE 4
    
    int main(int argc, char **argv)
    {
        int rank, size;
    
        MPI_Init(&argc,&argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
    
        int *intab, *sendcounts, *displs;
        sendcounts = malloc(size * sizeof(int)); 
        displs = malloc(size * sizeof(int)); 
        int sendcounts_particular = 0;
    
        // every rank will get its own chunk of data, but all will get SAME copy
        for(int i=0; i < size; i++)
        {
            if(sendcounts_particular < DISPLACEMENT_SIZE)
            {
                sendcounts_particular++; 
            }
            else
            {
                sendcounts_particular = 1; 
            }
            *(sendcounts + i) = sendcounts_particular;
        }
    
            int *rcvbuf = malloc(*(sendcounts + rank) * sizeof(int));
    
        // root node will initialize input array of data and displacements when only root needs them for Scatter
        if(!rank)
        {
            int displacement = 0;
            int f = 0, mainindex = 0;
            intab = malloc(size * DISPLACEMENT_SIZE * sizeof(int));
    
            // generating input data array
            for(int i=0; i < size; i++)
            {
                for(int j=0; j < DISPLACEMENT_SIZE; j++)
                {
                    *(intab+mainindex) = 1*f;
                    mainindex++;
                }
                f += 10;
            }
    
            // initializing displacements array, every DISPLACEMENT_SIZE fields for each rank
            for(int i=0; i < size; i++)
            {
                *(displs + i) = displacement;
                displacement += DISPLACEMENT_SIZE;
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
    
        MPI_Scatterv(intab, sendcounts, displs, MPI_INT,rcvbuf, *(sendcounts + rank), MPI_INT, 0, MPI_COMM_WORLD);
    
        printf("this is proces %i, got: sendcounts %i, &sendcounts %p\n", rank, *(sendcounts + rank), sendcounts);
    
        for(int i=0; i < *(sendcounts + rank); i++)
        {
            printf("Process %i my %i buffer value is %i\n ", rank, i, *(rcvbuf + i));
        }
        MPI_Finalize();
    
        return 0;
    
    }