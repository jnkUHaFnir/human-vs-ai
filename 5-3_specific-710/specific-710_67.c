#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int sendcounts[size];
    int displs[size];

    int sendbuf[] = {1, 2, 3, 4};
    int recvcount = 4; // Total elements in recvbuf for each process

    if (rank == 0) {
        // Process 0 will read 1 element
        sendcounts[0] = 1;
        displs[0] = 0;
        
        // Pad the remaining elements for process 0
        for (int i = 1; i < size; i++) {
            sendcounts[i] = 0; // Padding
            displs[i] = 0; // Padding
        }
    } else {
        // Other processes will read 3 elements
        sendcounts[0] = 0; // Zero elements for process 0
        for (int i = 1; i < size; i++) {
            if (i == rank) {
                sendcounts[i] = 3;
                displs[i] = 1; // Start reading from the 2nd element
            } else {
                sendcounts[i] = 0; // Padding
                displs[i] = 0; // Padding
            }
        }
    }

    int recvbuf[recvcount];

    MPI_Scatterv(sendbuf, sendcounts, displs, MPI_INT, recvbuf, recvcount, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d received data: ", rank);
    for (int i = 0; i < recvcount; i++) {
        printf("%d ", recvbuf[i]);
    }
    printf("\n");

    MPI_Finalize();

    return 0;
}
