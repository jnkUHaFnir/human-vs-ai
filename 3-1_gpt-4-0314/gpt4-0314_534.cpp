#include <mpi.h>
#include <vector>
#include <iostream>

using namespace std;

typedef struct {
    int id;
    vector<int> neighbors;
} Node;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 2) {
        cout << "This example requires exactly 2 MPI processes." << endl;
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Create MPI type for the "id" field of Node
    MPI_Datatype mpi_node_int;
    MPI_Type_contiguous(1, MPI_INT, &mpi_node_int);
    MPI_Type_commit(&mpi_node_int);

    // Prepare send and receive buffers
    Node send_node;
    Node recv_node;
    int recv_count;  // For receiving the length of the received neighbors vector
    
    if (rank == 0) {
        send_node.id = 42;
        send_node.neighbors = {1, 2, 3};
        
        // Send the "id" field from rank 0 to 1
        MPI_Send(&send_node.id, 1, mpi_node_int, 1, 0, MPI_COMM_WORLD);

        // Send the vector length and the actual vector<int> neighbors data
        MPI_Send(&send_node.neighbors[0], send_node.neighbors.size(), MPI_INT, 1, 1, MPI_COMM_WORLD);
    }
    else if (rank == 1) {
        // Receive the "id" field from rank 0 into the recv_node.id field
        MPI_Recv(&recv_node.id, 1, mpi_node_int, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        // Check how many elements were sent as the neighbors vector
        MPI_Probe(0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Get_count(MPI_STATUS_IGNORE, MPI_INT, &recv_count);
        
        // Allocate space for the receiving vector<int> and receive the data
        recv_node.neighbors.resize(recv_count);
        MPI_Recv(&recv_node.neighbors[0], recv_count, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    // Clean up the derived datatype
    MPI_Type_free(&mpi_node_int);

    // Print the received node data on rank 1
    if (rank == 1) {
        cout << "Node id: " << recv_node.id << " Neighbors: [";
        for (int i = 0; i < recv_node.neighbors.size(); ++i) {
            cout << recv_node.neighbors[i] << (i < recv_node.neighbors.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }

    MPI_Finalize();

    return 0;
}
