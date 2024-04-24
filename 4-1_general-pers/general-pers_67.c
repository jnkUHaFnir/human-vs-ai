#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int root = 0;
    int sendcounts[size];
    int displs[size];
    int recvcounts[size];

    // Initialize send data according to the scenario
    int sendbuf[] = {1, 2, 3, 4, 5, 6, 7, 8}; // This is just an example data

    // Calculate sendcounts and displs
    int totalElements = sizeof(sendbuf) / sizeof(sendbuf[0]);
    int elementsPerProcess = totalElements / size;
    for (int i = 0; i < size; i++) {
        sendcounts[i] = i < size - 1 ? elementsPerProcess : totalElements - i * elementsPerProcess;
        displs[i] = i * elementsPerProcess;
        recvcounts[i] = sendcounts[i]; // Each process receives the same amount it sends
    }

    // Scatter sendcounts to let each process know how many elements it should read
    int recvcount;
    MPI_Scatter(sendcounts, 1, MPI_INT, &recvcount, 1, MPI_INT, root, MPI_COMM_WORLD);
    
    // Allocate receive buffer based on recvcount
    int *recvbuf = (int *)malloc(recvcount * sizeof(int));

    // Scatter data to each process
    MPI_Scatterv(sendbuf, sendcounts, displs, MPI_INT, recvbuf, recvcount, MPI_INT, root, MPI_COMM_WORLD);

    // Process data in recvbuf
    printf("Process %d received %d elements from its recvbuf[]:\n", rank, recvcount);
    for (int i = 0; i < recvcount; i++) {
        printf("%d ", recvbuf[i]);
    }
    printf("\n");

    free(recvbuf);

    MPI_Finalize();

    return 0;
}
