#include <mpi.h>
#include <vector>

typedef struct {
    int id;
    int num_neighbors;
    int* neighbors;
} NodeSerialized;

void serialize(Node* node, NodeSerialized* serialized) {
    serialized->id = node->id;
    serialized->num_neighbors = node->neighbors.size();
    
    if(serialized->num_neighbors > 0) {
        serialized->neighbors = new int[serialized->num_neighbors];
        for(int i = 0; i < serialized->num_neighbors; i++) {
            serialized->neighbors[i] = node->neighbors[i];
        }
    }
}

void deserialize(NodeSerialized* serialized, Node* node) {
    node->id = serialized->id;
    for(int i = 0; i < serialized->num_neighbors; i++) {
        node->neighbors.push_back(serialized->neighbors[i]);
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    Node node;
    node.id = rank;
    
    // Add neighbors to the vector
    for(int i = 0; i < rank; i++) {
        node.neighbors.push_back(i);
    }

    // Serialize Node struct
    NodeSerialized serialized;
    serialize(&node, &serialized);

    // Create MPI datatype
    MPI_Datatype MPI_NodeType;
    MPI_Type_contiguous(2, MPI_INT, &MPI_NodeType);
    MPI_Type_commit(&MPI_NodeType);

    // Send/Receive the serialized struct
    if(rank == 0) {
        // Send serialized struct to rank 1
        MPI_Send(&serialized, 1, MPI_NodeType, 1, 0, MPI_COMM_WORLD);
    } else if(rank == 1) {
        // Receive serialized struct from rank 0
        MPI_Recv(&serialized, 1, MPI_NodeType, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Deserialize the received struct
        Node received_node;
        deserialize(&serialized, &received_node);

        // Print the received node information
        printf("Received Node ID: %d\n", received_node.id);
        printf("Received Node Neighbors: ");
        for(int i = 0; i < received_node.neighbors.size(); i++) {
            printf("%d ", received_node.neighbors[i]);
        }
        printf("\n");
    }

    // Free MPI datatype
    MPI_Type_free(&MPI_NodeType);

    MPI_Finalize();
    return 0;
}
