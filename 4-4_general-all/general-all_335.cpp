#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    std::vector<int>::size_type size;
    int* neighbors; // pointer to integer array
} NodeMPI;

Node createNode() {
    Node n;
    n.id = 1;
    n.neighbors = {2, 3, 4}; // Sample neighbors
    return n;
}

NodeMPI createNodeMPI(const Node& node) {
    NodeMPI n_mpi;
    n_mpi.id = node.id;
    n_mpi.size = node.neighbors.size();
    n_mpi.neighbors = new int[n_mpi.size];
    std::copy(node.neighbors.begin(), node.neighbors.end(), n_mpi.neighbors);
    return n_mpi;
}

void freeNodeMPI(NodeMPI& n_mpi) {
    delete[] n_mpi.neighbors;
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    Node node = createNode();
    NodeMPI node_mpi = createNodeMPI(node);

    MPI_Datatype NodeMPIDatatype;
    MPI_Type_contiguous(2, MPI_INT, &NodeMPIDatatype);
    MPI_Type_commit(&NodeMPIDatatype);

    // Send the struct data
    MPI_Send(&node_mpi, 1, NodeMPIDatatype, 1, 0, MPI_COMM_WORLD);

    freeNodeMPI(node_mpi);
    MPI_Type_free(&NodeMPIDatatype);
    MPI_Finalize();
    
    return 0;
}
