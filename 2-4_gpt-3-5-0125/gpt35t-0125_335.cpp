#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

int main() {
    MPI_Init(NULL, NULL);

    // Create MPI datatype for Node struct
    Node node;
    MPI_Datatype NodeMPIType;
    int blocklengths[] = {1, 1};  // Number of elements of each type in the struct
    MPI_Datatype types[] = {MPI_INT, MPI_INT};  // Datatype of each element in the struct
    MPI_Aint offsets[2];  // Offset of each element relative to the start of the struct
    MPI_Get_address(&node.id, &offsets[0]);
    MPI_Get_address(&node.neighbors, &offsets[1]);
    offsets[1] -= offsets[0];  // Normalize offset
    offsets[0] = 0;

    MPI_Type_create_struct(2, blocklengths, offsets, types, &NodeMPIType);
    MPI_Type_commit(&NodeMPIType);

    // Use the NodeMPIType to send/receive Node objects

    MPI_Finalize();
    return 0;
}
