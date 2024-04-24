#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    int* neighbors;
    int num_neighbors;
} Node_mpi;

void create_MPI_Node_type(MPI_Datatype* mpi_node_type) {
    const int nitems = 2;
    int blocklengths[2] = {1, 1};
    MPI_Datatype types[2] = {MPI_INT, MPI_INT};

    MPI_Aint offsets[2];
    offsets[0] = offsetof(Node_mpi, id);
    offsets[1] = offsetof(Node_mpi, neighbors);

    MPI_Type_create_struct(nitems, blocklengths, offsets, types, mpi_node_type);
    MPI_Type_commit(mpi_node_type);
}

void free_MPI_Node_type(MPI_Datatype* mpi_node_type) {
    MPI_Type_free(mpi_node_type);
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    MPI_Datatype mpi_node_type;
    create_MPI_Node_type(&mpi_node_type);

    // Now you can use mpi_node_type in MPI_Send and MPI_Recv

    free_MPI_Node_type(&mpi_node_type);

    MPI_Finalize();
    
    return 0;
}
