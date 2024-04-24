// First, create a datatype for the vector
MPI_Datatype mpi_vec_type;
MPI_Type_contiguous(sizeof(int), MPI_BYTE, &mpi_vec_type);
MPI_Type_commit(&mpi_vec_type);

// Then, create the datatype for the struct
MPI_Datatype node_type;
int block_lengths[2] = {1, 1};
MPI_Datatype block_types[2] = {MPI_INT, mpi_vec_type};
MPI_Aint start, displ[2];
MPI_Get_address(&((Node*)0)->id, &start);
MPI_Get_address(&((Node*)0)->neighbors, &displ[1]);
displ[1] -= start;
displ[0] = 0;
MPI_Type_create_struct(2, block_lengths, displ, block_types, &node_type);
MPI_Type_commit(&node_type);