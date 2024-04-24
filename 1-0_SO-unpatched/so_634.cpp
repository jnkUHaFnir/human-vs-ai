    int A[1];
    #pragma omp target
    A[0] = omp_is_initial_device();
    int device = A[0] ? omp_get_initial_device() : 0;