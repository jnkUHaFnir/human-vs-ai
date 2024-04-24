// Create MPI datatype for struct Node
MPI_Datatype create_mpi_node_datatype() {
    const int nitems = 2;
    int blocklengths[2] = {1, 0};
    MPI_Datatype types[2] = {MPI_INT, MPI_UB};

    MPI_Datatype mpi_node_type;
    MPI_Aint offsets[2];

    offsets[0] = offsetof(Node, id);
    offsets[1] = offsetof(Node, neighbors);

    MPI_Type_create_struct(nitems, blocklengths, offsets, types, &mpi_node_type);
    MPI_Type_commit(&mpi_node_type);

    return mpi_node_type;
}

int main(int argc, char** argv) {
    // ... MPI_Init and other MPI initialization code ...

    // Create the custom MPI datatype for Node
    MPI_Datatype mpi_node_type = create_mpi_node_datatype();

    // ... Sending and receiving code ...

    MPI_Type_free(&mpi_node_type);

    // ... MPI_Finalize and other cleanup code ...

    return 0;
}
