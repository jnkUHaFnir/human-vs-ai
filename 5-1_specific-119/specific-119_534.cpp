#include <mpi.h>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int id;
    vector<int> neighbors;
} Node;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    // Create MPI data type for struct Node
    MPI_Datatype nodeType;
    MPI_Type_contiguous(1, MPI_INT, &nodeType);
    MPI_Type_commit(&nodeType);

    // Create MPI data type for vector<int>
    MPI_Datatype vectorType;
    MPI_Type_contiguous(1, MPI_INT, &vectorType);
    MPI_Type_commit(&vectorType);

    // Define displacement and block count for struct Node
    int blockLengths[2] = {1, 0};
    MPI_Aint displacements[2];
    MPI_Datatype types[2] = {MPI_INT, vectorType};
    MPI_Aint start, end, intex;

    Node myNode;
    MPI_Get_address(&myNode, &start);  // Get address of struct Node

    Node* tempNode = &myNode;
    MPI_Get_address(&(tempNode->neighbors), &intex);  // Get address of vector<int> within struct Node
    MPI_Get_address(&(tempNode->id), &end);  // Get end address of struct Node

    displacements[0] = start;
    displacements[1] = intex - start;

    // Create struct Node MPI data type
    MPI_Type_create_struct(2, blockLengths, displacements, types, &nodeType);
    MPI_Type_commit(&nodeType);

    // Example of how to use the custom MPI data type
    // Send and receive a Node object
    Node sendNode, recvNode;
    sendNode.id = 1;
    sendNode.neighbors = {2, 3, 4};

    MPI_Send(&sendNode, 1, nodeType, dest, 0, MPI_COMM_WORLD);
    MPI_Recv(&recvNode, 1, nodeType, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // Clean up MPI data types
    MPI_Type_free(&nodeType);
    MPI_Type_free(&vectorType);

    MPI_Finalize();

    return 0;
}
