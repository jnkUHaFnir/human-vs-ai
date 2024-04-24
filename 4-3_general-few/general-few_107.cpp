for (i = 0; i < num_thrd; i++)
{
    matThread* parm = new matThread(); // Create a new instance for each thread
    parm->slice = i;
    if (pthread_create(&thread[i], NULL, multiply, (void*)parm) != 0)
    {
        cerr << "Can't create thread" << endl;
        free(thread); // Free other resources if needed
        exit(-1);
    }
}
void* multiply(void* param)
{
    matThread* s = (matThread*)param; // retrive the slice info
    int slice1 = s->slice;
    int D = s->dim;
    
    // Your existing code goes here...

    delete s; // Free the memory allocated for the matThread parameter
    return NULL;
}
