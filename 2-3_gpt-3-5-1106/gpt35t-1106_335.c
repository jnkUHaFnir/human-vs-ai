MPI_Datatype NodeMPIType;
int blockcounts[2] = {1, 0};
MPI_Datatype types[2] = {MPI_INT, MPI_UB};
MPI_Aint displacements[2] = {0, sizeof(int)};
MPI_Type_create_struct(2, blockcounts, displacements, types, &NodeMPIType);
MPI_Type_commit(&NodeMPIType);
// Send operation
int vectorSize = node.neighbors.size();
MPI_Send(&vectorSize, 1, MPI_INT, destinationRank, 0, MPI_COMM_WORLD); // Send vector size
if (vectorSize > 0) {
    MPI_Send(node.neighbors.data(), vectorSize, MPI_INT, destinationRank, 0, MPI_COMM_WORLD); // Send vector data
}
// Receive operation
MPI_Recv(&vectorSize, 1, MPI_INT, sourceRank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // Receive vector size
if (vectorSize > 0) {
    node.neighbors.resize(vectorSize);
    MPI_Recv(node.neighbors.data(), vectorSize, MPI_INT, sourceRank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // Receive vector data
}
