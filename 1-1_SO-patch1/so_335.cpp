    int *ns = seriealizeNode(node.second);
    int buffer_size = (int) (node.second.neighbors.size() + 1);
    
    MPI_Isend(ns, buffer_size, MPI_INT, proc_rank, TAG_DATA, MPI_COMM_WORLD, &request);
    MPI_Wait(&request, &status);
    free(ns);