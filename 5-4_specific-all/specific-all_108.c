int main(int argc, char* argv[])
{
    pthread_t* thread;  // pointer to a group of threads
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
    
    // Create an array of matThread instances, one for each thread
    matThread *parms[num_thrd];
    for (i = 0; i < num_thrd; i++)
    {
        parms[i] = new matThread();
        parms[i]->slice = i;

        // creates each thread working on its own slice of i
        if (pthread_create(&thread[i], NULL, multiply, (void*)parms[i]) != 0)
        {
            cerr << "Can't create thread" << endl;
            free(thread);
            exit(-1);
        }
    }
    
    for (i = 0; i < num_thrd; i++) { // Corrected loop end condition
        pthread_join(thread[i], NULL);
    }
    
    cout << "\n\n";
    print_matrix(A);
    cout << "\n\n\t *"<< endl;
    print_matrix(B);
    cout << "\n\n\t="<< endl;
    print_matrix(C);
    cout << "\n\n";
    
    free(thread);
    for (i = 0; i < num_thrd; i++) {
        delete parms[i]; // Free the allocated matThread instances
    }

    return 0;
}
