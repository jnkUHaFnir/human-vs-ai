#include <iostream>
#include <vector>
#include <mpi.h>

using namespace std;

typedef struct {
    int id;
    vector<int> neighbors;
} Node;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int block_lengths[2] = {1, 0}; // 1 element for id, 0 elements for neighbors initially
    MPI_Aint displacements[2];
    MPI_Datatype types[2] = {MPI_INT, MPI_INT}; // Use MPI_INT for the vector type for simplicity
    Node n;
    MPI_Aint curr_disp, base;

    MPI_Get_address(&n.id, &base);
    MPI_Get_address(&n.neighbors, &curr_disp);
    displacements[0] = 0;
    displacements[1] = curr_disp - base;

    MPI_Datatype node_type;
    MPI_Type_create_struct(2, block_lengths, displacements, types, &node_type);
    MPI_Type_commit(&node_type);

    // Use the node_type for sending/receiving Node objects

    MPI_Type_free(&node_type);

    MPI_Finalize();

    return 0;
}
