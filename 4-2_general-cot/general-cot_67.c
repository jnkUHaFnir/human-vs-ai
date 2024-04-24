#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int sendcounts[size] = {1, 3}; // Number of elements to send to each process
    int displs[size] = {0, 1}; // Start index of sendbuf from which sendcounts is counted

    int recvbuf[4]; // Receive buffer with fixed length for each process

    MPI_Scatterv(NULL, sendcounts, displs, MPI_INT, recvbuf, 4, MPI_INT, 0, MPI_COMM_WORLD);

    int recvcount; // Number of elements each process should read
    if (rank == 0) {
        recvcount = 1;
    } else if (rank == 1) {
        recvcount = 3;
    }

    int recvdata[recvcount]; // Buffer to store received elements based on rank
    MPI_Scatter(recvbuf, recvcount, MPI_INT, recvdata, recvcount, MPI_INT, 0, MPI_COMM_WORLD);

    // Process data
    for (int i = 0; i < recvcount; i++) {
        // Process recvdata elements here
    }

    MPI_Finalize();
    return 0;
}
