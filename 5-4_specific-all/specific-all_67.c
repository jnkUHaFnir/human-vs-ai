#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int sendbuf[] = {1, 2, 3, 4}; // Data to be scattered
    int recvbuf[4]; // Receive buffer to hold scattered data

    int sendcounts[size]; // Number of elements to send to each process
    int displs[size]; // Displacements for sendbuf

    // Define sendcounts and displs based on your scenario
    // For example: Process 0 gets 1 element, Process 1 gets 3 elements
    sendcounts[0] = 1;
    sendcounts[1] = 2;
    sendcounts[2] = 1;
    sendcounts[3] = 0;

    displs[0] = 0;
    displs[1] = 1;
    displs[2] = 3;
    displs[3] = 4;

    int recvcounts[size]; // Number of elements to receive from each process
    int recvdispls[size]; // Displacements for recvbuf

    // Define recvcounts and recvdispls based on your scenario
    // For example: Process 0 reads 1 element, Process 1 reads 3 elements
    recvcounts[0] = 1;
    recvcounts[1] = 3;
    recvcounts[2] = 0;
    recvcounts[3] = 0;

    recvdispls[0] = 0;
    recvdispls[1] = 0;
    recvdispls[2] = 0;
    recvdispls[3] = 0;

    // Scatter data using MPI_Scatterv
    MPI_Scatterv(sendbuf, sendcounts, displs, MPI_INT, recvbuf, 4, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process processes its portion of data
    for (int i = 0; i < recvcounts[rank]; i++) {
        printf("Process %d received: %d\n", rank, recvbuf[i]);
    }

    MPI_Finalize();
    return 0;
}
