#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int data[4]; // Assuming receive buffer has 4 elements for all processes
    int recv_count;

    if (world_rank == 0) {
        recv_count = 1; // Process 0 will read 1 element from its receive buffer
    } else if (world_rank == 1) {
        recv_count = 3; // Process 1 will read 3 elements from its receive buffer
    } else {
        recv_count = 0; // Other processes will not read any elements
    }

    int sendcounts[4] = {1, 3, 0, 0}; // Number of elements to send to each process
    int displs[4] = {0, 1, 4, 7}; // Start index of sendbuf for each process

    MPI_Scatterv(data, sendcounts, displs, MPI_INT, data, recv_count, MPI_INT, 0, MPI_COMM_WORLD);

    // Process the received data here

    MPI_Finalize();

    return 0;
}
