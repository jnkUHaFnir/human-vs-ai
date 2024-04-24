int sendcounts[NUM_PROCS]; // Array specifying how many elements to send to each process
int numElements;
// Assume sendcounts and the communicator are properly initialized.
MPI_Scatter(sendcounts, 1, MPI_INT, &numElements, 1, MPI_INT, root, comm);
int myRank, numOfElements[NUM_PROCS], myNumOfElements;
MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

// Assuming sendcounts has been filled appropriately,
// Use MPI_Scatter to distribute sending counts to every process.
// Only root needs the complete 'numOfElements', others just get their part
if (myRank == root) {
    MPI_Scatter(sendcounts, 1, MPI_INT, &myNumOfElements, 1, MPI_INT, root, MPI_COMM_WORLD);
} else {
    MPI_Scatter(NULL, 0, MPI_DATATYPE_NULL, &myNumOfElements, 1, MPI_INT, root, MPI_COMM_WORLD);
}

// Now myNumOfElements in each process contains the number of elements it should expect and process.

