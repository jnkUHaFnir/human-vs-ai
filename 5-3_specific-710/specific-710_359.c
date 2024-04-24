int main(int argc, char* argv[])
{
    pthread_t* thread;
    int i;
    if (argc != 2)
    {
        cout << "Usage:" << argv[0] << " number_of_threads" << endl;
        exit(-1);
    }
    num_thrd = atoi(argv[1]);
    init_matrix(A);
    init_matrix(B);
    thread = (pthread_t*)malloc(num_thrd * sizeof(pthread_t));

    for (i = 0; i < num_thrd; i++)
    {
        matThread* parm = new matThread(); // Create a new struct for each thread
        parm->slice = i;

        // creates each thread working on its own slice of i
        if (pthread_create(&thread[i], NULL, multiply, (void*)parm) != 0)
        {
            cerr << "Can't create thread" << endl;
            free(thread);
            exit(-1);
        }
    }

    for (i = 0; i < num_thrd; i++) // Corrected the loop index to start from 0
    {
        pthread_join(thread[i], NULL);
    }

    // Printing matrices after multiplication
    cout << "\n\n";
    print_matrix(A);
    cout << "\n\n\t * " << endl;
    print_matrix(B);
    cout << "\n\n\t = " << endl;
    print_matrix(C);
    cout << "\n\n";

    free(thread);

    return 0;
}
void* multiply(void* param)
{
    matThread* s = (matThread*)param;
    int slice1 = s->slice;
    int D = s->dim;
    int from = (slice1 * D) / num_thrd;
    int to = ((slice1 + 1) * D) / num_thrd;
    int i, j, k;
    cout << "computing slice  " << slice1 << " from row " << from << " to " << to - 1 << endl;
    
    for (i = from; i < to; i++)
    {
        for (j = 0; j < D; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < D; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "finished slice " << slice1 << endl;

    delete s; // Free the memory allocated for the struct

    return NULL;
}
