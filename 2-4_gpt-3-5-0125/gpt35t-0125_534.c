
In this code, we define a `createNodeMPIType` function that creates an MPI datatype for the `Node` struct. We calculate the displacements for the `id` and `neighbors` fields in the struct and create a custom datatype using `MPI_Type_create_struct`. Finally, we use this custom datatype to send and receive the `Node` struct with the vector property. Don't forget to free the datatype using `MPI_Type_free`.

This code should help you in sending and receiving a struct with a vector property using MPI.
