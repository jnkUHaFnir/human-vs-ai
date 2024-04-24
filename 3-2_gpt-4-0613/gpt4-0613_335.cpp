MPI_Datatype MPI_NODE_TYPE;

const int nitems = 1;
int blocklengths[1] = {1};
MPI_Aint offsets[1];
MPI_Datatype types[1] = {MPI_INT};

offsets[0] = offsetof(Node, id);

MPI_Type_create_struct(nitems, blocklengths, offsets, types, &MPI_NODE_TYPE);
MPI_Type_commit(&MPI_NODE_TYPE);
Node my_node;
// Populate your struct and vector here

MPI_Send(&my_node, 1, MPI_NODE_TYPE, dest, tag, MPI_COMM_WORLD);
MPI_Send(&my_node.neighbors[0], my_node.neighbors.size(), 
    MPI_INT, dest, tag, MPI_COMM_WORLD);
Node my_node;
MPI_Recv(&my_node, 1, MPI_NODE_TYPE, source, tag, MPI_COMM_WORLD, &status);
int number_amount;
MPI_Get_count(&status, MPI_INT, &number_amount);
my_node.neighbors.resize(number_amount);
MPI_Recv(&my_node.neighbors[0], number_amount, 
    MPI_INT, source, tag, MPI_COMM_WORLD, &status);
MPI_Type_free(&MPI_NODE_TYPE);
MPI_Type_free(&MPI_NODE_TYPE);
