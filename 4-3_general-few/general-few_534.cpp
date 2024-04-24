#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

int main() {
    // Initialize MPI
    MPI_Init(NULL, NULL);

    int blocklengths[2] = {1, 0};
    MPI_Datatype types[2] = {MPI_INT, MPI_INT};
    MPI_Aint displacements[2];
    Node node;

    MPI_Address(&node.id, &displacements[0]);
    MPI_Address(&node.neighbors, &displacements[1]);

    // Calculate displacement
    displacements[1] -= displacements[0];

    // Create a struct datatype for the Node struct
    MPI_Datatype MPI_NODE;
    MPI_Type_create_struct(2, blocklengths, displacements, types, &MPI_NODE);
    MPI_Type_commit(&MPI_NODE);

    // Use the MPI derived datatype MPI_NODE to send/receive Node struct instance

    // Clean up MPI
    MPI_Type_free(&MPI_NODE);
    MPI_Finalize();

    return 0;
}
