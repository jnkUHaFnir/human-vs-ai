for (i = 0; i < num_thrd; i++)
{
    matThread *parm = new matThread(); // Create a new instance for each thread
    parm->slice = i;

    // creates each thread working on its own slice of i
    if (pthread_create (&thread[i], NULL, multiply, (void*)parm) != 0)
    {
        cerr<<"Can't create thread"<<endl;
        free(thread);
        exit(-1);
    }
}
void* multiply(void* param)
{
    matThread* s = (matThread*)param;   // retrieve the slice info
    int slice1 = s->slice;
    int D = s->dim;
    // Rest of your function remains the same
}
