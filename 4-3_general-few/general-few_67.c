#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int sendbuf[] = {1, 4, 7, 12}; // Example sendbuf
    int sendcounts[] = {1, 3}; // Number of elements to send to each process
    int displs[] = {0, 1}; // Displacements into sendbuf

    int recvbuf;

    if(rank < 2) {
        int recvcount = sendcounts[rank]; // Number of elements to receive
        MPI_Scatterv(sendbuf, sendcounts, displs, MPI_INT, &recvbuf, recvcount, MPI_INT, 0, MPI_COMM_WORLD);

        printf("Process %d received %d elements: %d\n", rank, recvcount, recvbuf);
    }

    MPI_Finalize();
    return 0;
}
