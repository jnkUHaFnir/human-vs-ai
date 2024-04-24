#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

int main(int argc, char *argv[]) {
    int blocklengths[2] = {1, 0}; // Number of elements in Node struct: id and a count of elements in vector (initially set to 0)
    MPI_Aint displacements[2]; // Displacements of the id and neighbors
    MPI_Datatype types[2] = {MPI_INT, MPI_INT}; // Types of id and neighbors

    // Compute displacements of id and neighbors
    Node myNode;
    MPI_Aint baseAddr;
    MPI_Get_address(&myNode, &baseAddr);
    MPI_Get_address(&myNode.id, &displacements[0]);
    displacements[0] -= baseAddr;
    MPI_Get_address(&myNode.neighbors, &displacements[1]);
    displacements[1] -= baseAddr;

    // Create struct datatype for Node
    MPI_Datatype MPI_Node;
    MPI_Type_create_struct(2, blocklengths, displacements, types, &MPI_Node);
    MPI_Type_commit(&MPI_Node);

    // Now you can use MPI_Node datatype to send/receive Node structs

    MPI_Finalize();
    return 0;
}
