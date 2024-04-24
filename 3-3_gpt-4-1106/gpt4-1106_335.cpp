#include <mpi.h>
#include <vector>
#include <iostream>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

void sendNode(int dest, const Node& node, int tag, MPI_Comm comm) {
    // First, send the node ID.
    MPI_Send(&node.id, 1, MPI_INT, dest, tag, comm);
    
    // Then send the size of the neighbors vector.
    int size = static_cast<int>(node.neighbors.size());
    MPI_Send(&size, 1, MPI_INT, dest, tag, comm);
    
    // Finally, send the actual neighbors data.
    MPI_Send(node.neighbors.data(), size, MPI_INT, dest, tag, comm);
}

void recvNode(int src, Node& node, int tag, MPI_Comm comm) {
    MPI_Status status;

    // First, receive the node ID.
    MPI_Recv(&node.id, 1, MPI_INT, src, tag, comm, &status);
    
    // Then receive the size of the neighbors vector.
    int size;
    MPI_Recv(&size, 1, MPI_INT, src, tag, comm, &status);
    node.neighbors.resize(size);

    // Finally, receive the actual neighbors data.
    MPI_Recv(node.neighbors.data(), size, MPI_INT, src, tag, comm, &status);
}

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        Node nodeToSend{1, {2, 3, 4, 5}};
        sendNode(1, nodeToSend, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        Node nodeToRecv;
        recvNode(0, nodeToRecv, 0, MPI_COMM_WORLD);
        std::cout << "Received Node ID: " << nodeToRecv.id << std::endl;
        std::cout << "Neighbors:";
        for (int n : nodeToRecv.neighbors) {
            std::cout << " " << n;
        }
        std::cout << std::endl;
    }

    MPI_Finalize();
    return 0;
}
