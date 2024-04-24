#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int blocklengths[2] = { 1, 1 };
    MPI_Datatype types[2] = { MPI_INT, MPI_INT };
    MPI_Aint offsets[2];

    Node node;
    offsets[0] = offsetof(Node, id);
    offsets[1] = offsetof(Node, neighbors);

    MPI_Datatype mpi_node_type;
    MPI_Type_create_struct(2, blocklengths, offsets, types, &mpi_node_type);
    MPI_Type_commit(&mpi_node_type);

    // Now you can use mpi_node_type to send/recv Node objects

    MPI_Type_free(&mpi_node_type);

    MPI_Finalize();

    return 0;
}
