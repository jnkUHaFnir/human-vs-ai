for (i = 0; i < num_thrd; i++)
{
    matThread *parm = new matThread(); // create a new struct for each thread
    parm->slice = i;

    if (pthread_create (&thread[i], NULL, multiply, (void*)parm) != 0)
    {
        cerr<<"Can't create thread"<<endl;
        free(thread);
        exit(-1);
    }
}
