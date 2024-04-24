#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    std::vector<int> neighbors;
} Node;

// Function to serialize a vector into a char buffer
void serializeVector(const std::vector<int> &data, char *&buffer, int &size) {
    size = data.size() * sizeof(int);
    buffer = new char[size];
    memcpy(buffer, data.data(), size);
}

// Function to deserialize a char buffer into a vector
void deserializeVector(const char *buffer, int size, std::vector<int> &data) {
    int elements = size / sizeof(int);
    data.resize(elements);
    memcpy(data.data(), buffer, size);
}

// Function to create MPI datatype for Node struct
void createNodeMPIType(MPI_Datatype *nodeType) {
    int blockcounts[2] = {1, 1};
    MPI_Datatype types[2] = {MPI_INT, MPI_CHAR}; // Assuming int is similar to char in size
    MPI_Aint displacements[2];
    
    // Get displacement of neighbors field
    MPI_Aint base, offset;
    MPI_Type_get_extent(MPI_INT, &base, &offset);
    MPI_Type_get_extent(MPI_CHAR, &base, &displacements[1]);
    
    // Add displacements of id and neighbors fields
    displacements[0] = 0;
    
    // Create struct type
    MPI_Type_create_struct(2, blockcounts, displacements, types, nodeType);
    MPI_Type_commit(nodeType);
}

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Create MPI datatype for Node struct
    MPI_Datatype nodeType;
    createNodeMPIType(&nodeType);

    Node localNode;
    if (rank == 0) {
        // Fill localNode with data

        // Serialize neighbors vector
        char *buffer;
        int size;
        serializeVector(localNode.neighbors, buffer, size);

        // Sending data
        MPI_Send(&localNode, 1, nodeType, 1, 0, MPI_COMM_WORLD);
        MPI_Send(buffer, size, MPI_CHAR, 1, 1, MPI_COMM_WORLD);

        delete[] buffer;
    } else if (rank == 1) {
        Node receivedNode;
        MPI_Recv(&receivedNode, 1, nodeType, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Deserialize neighbors vector
        char *buffer;
        int size;
        MPI_Status status;
        MPI_Probe(0, 1, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_CHAR, &size);
        buffer = new char[size];
        MPI_Recv(buffer, size, MPI_CHAR, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        deserializeVector(buffer, size, receivedNode.neighbors);

        delete[] buffer;
    }

    MPI_Type_free(&nodeType);
    MPI_Finalize();

    return 0;
}
