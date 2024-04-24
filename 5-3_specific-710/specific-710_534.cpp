#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

int main(int argc, char **argv) {
    int blocklengths[2] = {1, 1}; // id and neighbor count
    MPI_Datatype types[2] = {MPI_INT, MPI_INT}; // id and neighbor count types
    MPI_Aint offsets[2];
    MPI_Datatype nodeType;

    Node node;

    MPI_Init(&argc, &argv);

    MPI_Address(&node.id, &offsets[0]);
    MPI_Address(&node.neighbors, &offsets[1]);

    offsets[1] -= offsets[0]; // Adjust offset for relative position

    MPI_Type_create_struct(2, blocklengths, offsets, types, &nodeType);
    MPI_Type_commit(&nodeType);

    // Now you can use nodeType to send/receive Node structs

    MPI_Type_free(&nodeType);
    MPI_Finalize();

    return 0;
}
