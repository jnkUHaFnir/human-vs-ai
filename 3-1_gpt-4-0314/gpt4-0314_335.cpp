#include <iostream>
#include <vector>
#include <mpi.h>

using namespace std;

typedef struct {
    int id;
    vector<int> neighbors;
} Node;

int main(int argc, char** argv) {
    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Create a simple Node structure
    Node node = {0, {1, 2, 3}};

    // The amount of elements in the structure (2): int id + int vector_neighbors
    int arr_blocklengths[] = {1, static_cast<int>(node.neighbors.size())};

    // MPI types
    MPI_Datatype arr_types[] = {MPI_INT, MPI_INT};

    // Displacements in the structure
    MPI_Aint arr_displacements[] = {offsetof(Node, id), offsetof(Node, neighbors.front())};

    // Building the structure (Node) type
    MPI_Datatype mpi_node_type;
    MPI_Type_create_struct(2, arr_blocklengths, arr_displacements, arr_types, &mpi_node_type);
    MPI_Type_commit(&mpi_node_type);

    // ... Sending/receiving data using the created mpi_node_type

    // Free the created datatype
    MPI_Type_free(&mpi_node_type);

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
int size;
MPI_Type_size(mpi_node_type, &size);
char send_buffer[size];

memcpy(send_buffer, &node.id, sizeof(int));
memcpy(send_buffer+sizeof(int), &node.neighbors[0], node.neighbors.size() * sizeof(int));

MPI_Send(&send_buffer, 1, mpi_node_type, dest_rank, tag, MPI_COMM_WORLD);
char recv_buffer[size];
MPI_Recv(&recv_buffer, 1, mpi_node_type, source_rank, tag, MPI_COMM_WORLD, &status);

Node received_node;
memcpy(&received_node.id, recv_buffer, sizeof(int));
vector<int> received_neighbors(arr_blocklengths[1]);
memcpy(&received_neighbors[0], recv_buffer+sizeof(int), received_neighbors.size() * sizeof(int));
received_node.neighbors = received_neighbors;
