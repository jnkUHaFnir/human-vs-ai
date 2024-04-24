MPI_Datatype MPI_VECTOR;
MPI_Type_contiguous(neighbors.size(), MPI_INT, &MPI_VECTOR);
MPI_Type_commit(&MPI_VECTOR);
int blocklengths[2] = {1, 1};
MPI_Aint displacements[2];
MPI_Aint start_address, address;

MPI_Get_address(&node, &start_address);
MPI_Get_address(&node.id, &address);
displacements[0] = address - start_address;

MPI_Get_address(&node.neighbors.data(), &address);
displacements[1] = address - start_address;
MPI_Datatype types[2] = {MPI_INT, MPI_VECTOR};
MPI_Type_create_struct(2, blocklengths, displacements, types, &MPI_NODE);
MPI_Type_commit(&MPI_NODE);
