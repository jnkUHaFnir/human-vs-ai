#include <iostream>
#include <vector>
#include <mpi.h>

typedef struct {
    int id;
    int neighbors_count; // the size of the 'neighbors' array
    int* neighbors;      // array to store neighbor values
} MPI_Node;

int main() {
    MPI_Init(NULL, NULL);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    MPI_Datatype MPI_NODE;
    MPI_Datatype types[2] = {MPI_INT, MPI_INT};
    int block_lens[2] = {1, 1};
    MPI_Aint displ[2];
    MPI_Node temp_node;

    // Get the displacement of id and neighbors_count
    MPI_Get_address(&temp_node.id, &displ[0]);
    MPI_Get_address(&temp_node.neighbors_count, &displ[1]);
    displ[1] -= displ[0]; // Calculate relative offset for neighbors_count

    // Create the structure
    MPI_Type_create_struct(2, block_lens, displ, types, &MPI_NODE);
    MPI_Type_commit(&MPI_NODE);

    // Create a Node struct
    Node node;
    node.id = 1;
    node.neighbors = {2, 3, 4}; // example neighbors

    // Create MPI_Node struct and populate it
    MPI_Node mpi_node;
    mpi_node.id = node.id;
    mpi_node.neighbors_count = node.neighbors.size();
    mpi_node.neighbors = node.neighbors.data();

    // Send and receive MPI_Node
    if (world_rank == 0) {
        MPI_Send(&mpi_node, 1, MPI_NODE, 1, 0, MPI_COMM_WORLD);
    } else if (world_rank == 1) {
        MPI_Recv(&mpi_node, 1, MPI_NODE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    // Cleanup
    MPI_Type_free(&MPI_NODE);
    MPI_Finalize();

    return 0;
}
