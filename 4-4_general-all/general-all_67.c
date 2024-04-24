#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int sendbuf[] = {1, 2, 3, 4, 5}; // Example send buffer data
    int sendcounts[] = {1, 3}; // Number of elements to send to each process
    int displs[] = {0, 1}; // Start index in sendbuf for each process

    int recvbuf[4]; // All processes will have the same size for recvbuf

    int recvcount = (rank == 0) ? 1 : 3; // Define how many elements to read from recvbuf based on rank

    MPI_Scatterv(sendbuf, sendcounts, displs, MPI_INT, recvbuf, recvcount, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d received: ", rank);
    for (int i = 0; i < recvcount; i++) {
        printf("%d ", recvbuf[i]);
    }
    printf("\n");

    MPI_Finalize();
    return 0;
}
