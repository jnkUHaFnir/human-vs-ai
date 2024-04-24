#include <mpi.h>
#include <iostream>
#include <vector>

typedef struct {
    int id;
    int num_neighbors;
} Node;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int blocklengths[2] = {1, 1};
    MPI_Datatype types[2] = {MPI_INT, MPI_INT};
    MPI_Aint offsets[2];

    offsets[0] = offsetof(Node, id);
    offsets[1] = offsetof(Node, num_neighbors);

    MPI_Datatype mpi_node_type;
    MPI_Type_create_struct(2, blocklengths, offsets, types, &mpi_node_type);
    MPI_Type_commit(&mpi_node_type);

    // Create a vector
    std::vector<int> neighbors = {1, 2, 3};
    
    int vector_size = neighbors.size();
    MPI_Datatype mpi_vector_type;
    MPI_Type_contiguous(vector_size, MPI_INT, &mpi_vector_type);
    MPI_Type_commit(&mpi_vector_type);

    Node node;
    node.id = 1;
    node.num_neighbors = vector_size;

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        MPI_Send(&node, 1, mpi_node_type, 1, 0, MPI_COMM_WORLD);
        MPI_Send(neighbors.data(), vector_size, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        Node received_node;
        MPI_Recv(&received_node, 1, mpi_node_type, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        std::vector<int> received_neighbors(vector_size);
        MPI_Recv(received_neighbors.data(), vector_size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Process received_node and received_neighbors
    }

    MPI_Type_free(&mpi_node_type);
    MPI_Type_free(&mpi_vector_type);

    MPI_Finalize();

    return 0;
}
