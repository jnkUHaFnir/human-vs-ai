#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int sendbuf[] = {0, 1, 2, 3, 4, 5, 6, 7}; // sample send buffer
    int recvbuf[4]; // fixed length receive buffer for each process
    int sendcounts[] = {1, 3}; // number of elements to be sent to each process
    int displs[] = {0, 1}; // start index of data in sendbuf for each process
    int recvcounts[] = {1, 3}; // number of elements to be read by each process from recvbuf

    MPI_Scatterv(sendbuf, sendcounts, displs, MPI_INT, recvbuf, 4, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d received: ", rank);
    for (int i = 0; i < recvcounts[rank]; i++) {
        printf("%d ", recvbuf[i]);
    }
    printf("\n");

    MPI_Finalize();

    return 0;
}
