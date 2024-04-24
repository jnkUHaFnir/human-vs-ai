#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

void sendNode(int target, const Node& node, int tag, MPI_Comm comm) {
    // First send the fixed-size part (id)
    MPI_Send(&node.id, 1, MPI_INT, target, tag, comm);
    
    // Then send the size of the vector
    int size = node.neighbors.size();
    MPI_Send(&size, 1, MPI_INT, target, tag, comm);
    
    // Finally, send the vector's contents if it's not empty
    if (size > 0) {
        MPI_Send(node.neighbors.data(), size, MPI_INT, target, tag, comm);
    }
}
void receiveNode(int source, Node& node, int tag, MPI_Comm comm) {
    MPI_Status status;
    
    // Receive the fixed-size part first
    MPI_Recv(&node.id, 1, MPI_INT, source, tag, comm, &status);
    
    // Then receive the size of the vector
    int size;
    MPI_Recv(&size, 1, MPI_INT, source, tag, comm, &status);
    
    // Resize the vector accordingly
    node.neighbors.resize(size);
    
    // Finally, if there's any, receive the vector's contents
    if (size > 0) {
        MPI_Recv(node.neighbors.data(), size, MPI_INT, source, tag, comm, &status);
    }
}
