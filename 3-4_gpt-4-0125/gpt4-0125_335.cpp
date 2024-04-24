#include <mpi.h>
#include <vector>
#include <iostream>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

void sendNode(int destination, int tag, MPI_Comm comm, const Node& node) {
    // First send the ID
    MPI_Send(&node.id, 1, MPI_INT, destination, tag, comm);
    
    // Then send the size of the vector
    int size = node.neighbors.size();
    MPI_Send(&size, 1, MPI_INT, destination, tag, comm);
    
    // Finally, send the vector contents if it's not empty
    if(size > 0) {
        MPI_Send(node.neighbors.data(), size, MPI_INT, destination, tag, comm);
    }
}
Node receiveNode(int source, int tag, MPI_Comm comm) {
    MPI_Status status;
    Node node;
    
    // First receive the ID
    MPI_Recv(&node.id, 1, MPI_INT, source, tag, comm, &status);
    
    // Then receive the size of the vector
    int size;
    MPI_Recv(&size, 1, MPI_INT, source, tag, comm, &status);
    
    // If there's data, receive the vector contents
    if(size > 0) {
        node.neighbors.resize(size);
        MPI_Recv(node.neighbors.data(), size, MPI_INT, source, tag, comm, &status);
    }
    
    return node;
}
int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if(world_rank == 0) {
        // Example: creating and sending a node from process 0 to 1
        Node myNode;
        myNode.id = 1;
        myNode.neighbors = {2, 3, 4};
        sendNode(1, 0, MPI_COMM_WORLD, myNode);
    } else if(world_rank == 1) {
        // Receiving the node at process 1
        Node receivedNode = receiveNode(0, 0, MPI_COMM_WORLD);
        // Process the received node
        std::cout << "Received node ID: " << receivedNode.id << std::endl;
    }
    
    MPI_Finalize();
    return 0;
}
