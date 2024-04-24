#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int block_lengths[2] = {1, 1};
    MPI_Aint displacements[2];
    MPI_Datatype types[2] = {MPI_INT, MPI_INT};

    Node sample_node;
    MPI_Datatype NodeMPIType;

    MPI_Address(&sample_node.id, &displacements[0]);
    MPI_Address(&sample_node.neighbors, &displacements[1]);

    displacements[1] -= displacements[0];
    displacements[0] = 0;

    MPI_Type_create_struct(2, block_lengths, displacements, types, &NodeMPIType);
    MPI_Type_commit(&NodeMPIType);

    // Now the NodeMPIType can be used with MPI functions like MPI_Send and MPI_Recv

    MPI_Type_free(&NodeMPIType);
    
    MPI_Finalize();
    return 0;
}
