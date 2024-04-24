int recvcounts[numprocs]; // store the length of each process's result
int displs[numprocs]; // store the displacement of each process's result

// fill in recvcounts and displs arrays
for (int i = 0; i < numprocs; i++) {
    recvcounts[i] = i + 1; // process 0 has 1 element, process 1 has 2 elements, and so on
    displs[i] = i; // displacement is the starting index of each process's result in the receive buffer
}

// allocate receive buffer for the root process
int* recvbuf = NULL;
if (rank == root) {
    recvbuf = (int*) malloc(recvcount * sizeof(int));
}

// gather the results from each process
MPI_Gatherv(sendbuf, sendcounts[rank], sendtype, recvbuf, recvcounts, displs, MPI_INT, root, comm);

// process the results in the root process
if (rank == root) {
    for (int i = 0; i < recvcount; i++) {
        printf("%d ", recvbuf[i]);
    }
    printf("\n");

    free(recvbuf);
}
