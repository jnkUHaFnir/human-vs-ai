#include <mpi.h>
#include <vector>
#include <iostream>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

void sendNode(const Node& node, int destination, int tag, MPI_Comm comm) {
    // Send the ID part of the node.
    MPI_Send(&node.id, 1, MPI_INT, destination, tag, comm);

    // Send the size of the neighbors vector.
    int neighborsSize = node.neighbors.size();
    MPI_Send(&neighborsSize, 1, MPI_INT, destination, tag+1, comm);

    // Send the contents of the neighbors vector if it's not empty.
    if (!node.neighbors.empty()) {
        MPI_Send(node.neighbors.data(), neighborsSize, MPI_INT, destination, tag+2, comm);
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    // Assume this is the sender's code.
    Node nodeToSend;
    nodeToSend.id = 1;
    nodeToSend.neighbors = {2, 3, 4};

    int myrank;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == 0) {
        // Example: send to process 1 with a base tag of 0
        sendNode(nodeToSend, 1, 0, MPI_COMM_WORLD);
    }

    // Other code needed to receive the node, finalize, etc.

    MPI_Finalize();
    return 0;
}
void receiveNode(Node& node, int source, int tag, MPI_Comm comm, MPI_Status* status) {
    // Receive the ID part of the node.
    MPI_Recv(&node.id, 1, MPI_INT, source, tag, comm, status);

    // Receive the size of the neighbors vector.
    int neighborsSize;
    MPI_Recv(&neighborsSize, 1, MPI_INT, source, tag+1, comm, status);

    // Resize the vector and receive the contents if size is not zero.
    if (neighborsSize > 0) {
        node.neighbors.resize(neighborsSize);
        MPI_Recv(node.neighbors.data(), neighborsSize, MPI_INT, source, tag+2, comm, status);
    }
}
