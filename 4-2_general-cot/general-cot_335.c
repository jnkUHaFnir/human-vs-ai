#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

int main() {
    int blocklengths[2] = {1, 0}; // 1 integer for id
    MPI_Datatype types[2] = {MPI_INT, MPI_INT}; // ID is int, neighbors will be resized as needed
    MPI_Datatype mpi_node_type;
    MPI_Aint offsets[2];

    Node node;

    MPI_Get_address(&node.id, &offsets[0]);
    MPI_Get_address(&node.neighbors, &offsets[1]);

    offsets[1] -= offsets[0];
    offsets[0] = 0;

    MPI_Type_create_struct(2, blocklengths, offsets, types, &mpi_node_type);
    MPI_Type_commit(&mpi_node_type);

    // Use mpi_node_type in MPI_Send and MPI_Recv

    MPI_Type_free(&mpi_node_type);

    return 0;
}
