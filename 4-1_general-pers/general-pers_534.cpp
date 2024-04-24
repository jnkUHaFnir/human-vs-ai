#include <iostream>
#include <vector>
#include <mpi.h>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_rank == 0) {
        Node nodeToSend;
        nodeToSend.id = 1;
        nodeToSend.neighbors = {2, 3, 4};

        // Send id first
        MPI_Send(&nodeToSend.id, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

        // Send vector size first
        int vecSize = nodeToSend.neighbors.size();
        MPI_Send(&vecSize, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

        // Send vector data
        MPI_Send(nodeToSend.neighbors.data(), vecSize, MPI_INT, 1, 0, MPI_COMM_WORLD);
        
    } else if (world_rank == 1) {
        Node receivedNode;

        // Receive id first
        MPI_Recv(&receivedNode.id, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Receive vector size first
        int vecSize;
        MPI_Recv(&vecSize, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Resize the vector
        receivedNode.neighbors.resize(vecSize);

        // Receive vector data
        MPI_Recv(receivedNode.neighbors.data(), vecSize, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Print received data
        std::cout << "Received Node:\n";
        std::cout << "ID: " << receivedNode.id << std::endl;
        std::cout << "Neighbors: ";
        for (int neighbor : receivedNode.neighbors) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }

    MPI_Finalize();
    return 0;
}
