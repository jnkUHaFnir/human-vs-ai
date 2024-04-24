#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

// Create a new MPI datatype for the Node struct
void createNodeMPIType(MPI_Datatype *NodeMPIType) {
    int blockLens[2] = { 1, 0 }; // Number of elements for id and neighbors
    MPI_Aint displ[2];
    MPI_Datatype types[2] = { MPI_INT, MPI_INT };

    Node sampleNode;
    displ[0] = 0;
    MPI_Get_address(&(sampleNode.id), &displ[1]);

    MPI_Type_create_struct(2, blockLens, displ, types, NodeMPIType);
    MPI_Type_commit(NodeMPIType);
}

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    MPI_Datatype NodeMPIType;
    createNodeMPIType(&NodeMPIType);

    Node myNode;
    myNode.id = 1;
    myNode.neighbors = {2, 3, 4};

    // Send the Node struct
    if (world_rank == 0) {
        MPI_Send(&myNode, 1, NodeMPIType, 1, 0, MPI_COMM_WORLD);
    } else if (world_rank == 1) {
        MPI_Recv(&myNode, 1, NodeMPIType, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    MPI_Type_free(&NodeMPIType);

    MPI_Finalize();
    return 0;
}
