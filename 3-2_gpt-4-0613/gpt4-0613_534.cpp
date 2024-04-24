#include <mpi.h>

typedef struct {
    int id;
    int neighbors[100];
} Node;

int main(int argc, char **argv) {

    MPI_Init(&argc, &argv);

    const int nitems = 2;
    int blocklengths[2] = {1, 100};
    MPI_Datatype types[2] = {MPI_INT, MPI_INT};
    MPI_Datatype mpi_node_type;
    MPI_Aint offsets[2];

    offsets[0] = offsetof(Node, id);
    offsets[1] = offsetof(Node, neighbors);

    MPI_Type_create_struct(nitems, blocklengths, offsets, types, &mpi_node_type);
    MPI_Type_commit(&mpi_node_type);

    Node node;
    // Fill the struct here
    
    // Just for an example, sending to ourselves
    MPI_Send(&node, 1, mpi_node_type, 0, 0, MPI_COMM_WORLD);

    mpi_node_type node_received;
    MPI_Recv(&node_received, 1, mpi_node_type, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    MPI_Type_free(&mpi_node_type);
    MPI_Finalize();

    return 0;
}
