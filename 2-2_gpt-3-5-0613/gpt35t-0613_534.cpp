#include <iostream>
#include <vector>
#include <mpi.h>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

int main() {
    MPI_Init(NULL, NULL);

    // Create MPI datatype for Node struct
    MPI_Datatype MPI_NODE;
    int blocklengths[2] = {1, 1};
    MPI_Aint displacements[2];
    MPI_Datatype types[2] = {MPI_INT, MPI_INT};

    // Get the displacement of the neighbors vector
    MPI_Aint neighbors_disp;
    Node dummy_node;
    displacements[0] = 0;
    MPI_Get_address(&(dummy_node.id), &displacements[1]);
    MPI_Get_address(&(dummy_node.neighbors), &neighbors_disp);
    displacements[1] = neighbors_disp - displacements[1];

    MPI_Type_create_struct(2, blocklengths, displacements, types, &MPI_NODE);
    MPI_Type_commit(&MPI_NODE);

    // Create and send/receive a Node struct
    Node node;
    node.id = 1;
    node.neighbors = {2, 3};

    if (MPI_COMM_WORLD.Get_rank() == 0) {
        // Send the Node struct to rank 1
        MPI_Send(&node, 1, MPI_NODE, 1, 0, MPI_COMM_WORLD);
    } else if (MPI_COMM_WORLD.Get_rank() == 1) {
        // Receive the Node struct from rank 0
        Node received_node;
        MPI_Recv(&received_node, 1, MPI_NODE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Print received data
        std::cout << "Received Node: " << received_node.id << std::endl;
        std::cout << "Received Node neighbors: ";
        for (int neighbor : received_node.neighbors) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }

    MPI_Type_free(&MPI_NODE);
    MPI_Finalize();

    return 0;
}
