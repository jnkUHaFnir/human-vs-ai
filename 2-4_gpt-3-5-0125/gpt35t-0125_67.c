#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int sendcounts[size];
    int displs[size];
    int recvcounts[size];
    int recvdispls[size];

    // Define the send buffer for each process
    int sendbuf[] = {1, 2, 3, 4};
    
    // Calculate sendcounts and displs arrays
    for (int i = 0; i < size; i++) {
        sendcounts[i] = i + 1;
        displs[i] = sendcounts[i] == 1 ? 0 : displs[i-1] + sendcounts[i-1];
    }

    // Scatter the data to all processes
    MPI_Scatterv(sendbuf, sendcounts, displs, MPI_INT, recvbuf, 4, MPI_INT, 0, MPI_COMM_WORLD);

    // Gather the variable length data at root
    MPI_Gatherv(recvbuf, size, recvcounts, recvdispls, MPI_INT, resultbuf, 4, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        for (int i = 0; i < size; i++) {
            printf("Process %d received %d elements:", i, recvcounts[i]);
            for (int j = recvdispls[i]; j < recvdispls[i] + recvcounts[i]; j++) {
                printf(" %d", resultbuf[j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();

    return 0;
}
