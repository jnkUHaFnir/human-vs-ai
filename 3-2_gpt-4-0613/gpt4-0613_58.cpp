void* multiply(void* param)
{
  // ... same as before ...
  cout<<" finished slice "<<slice1<<endl;
  delete s;
  return NULL;
}
int main(int argc, char* argv[])
{
  // ... same as before ...
  for (i = 0; i < num_thrd; i++)
  {
    matThread *parm = new matThread();
    parm->slice=i;
    // creates each thread working on its own slice of i
    if (pthread_create (&thread[i], NULL, multiply, (void*)parm) != 0)
    {
      cerr<<"Can't create thread"<<endl;
      free(thread);
      exit(-1);
    }
  }
  for (i = 0; i < num_thrd; i++)
    pthread_join (thread[i], NULL);
  // ... same as before ...
}
