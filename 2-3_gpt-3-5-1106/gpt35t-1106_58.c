int main(int argc, char* argv[])
{
  pthread_t* thread;  // pointer to a group of threads
  int i;
   if (argc!=2)
  {
   cout<<"Usage:"<< argv[0]<<" number_of_threads"<<endl;
   exit(-1);
  }
  num_thrd = atoi(argv[1]);
  init_matrix(A);
  init_matrix(B);
  thread = (pthread_t*) malloc(num_thrd*sizeof(pthread_t));

  for (i = 0; i < num_thrd; i++)
  {
    matThread *parm = new matThread();
    parm->slice=i;
    parm->dim=SIZE;  // initialize the dimension
    // creates each thread working on its own slice of i
    if (pthread_create (&thread[i], NULL, multiply, (void*)parm) != 0)
    {
      cerr<<"Can't create thread"<<endl;
      free(thread);
      exit(-1);
    }
  }

 for (i = 1; i < num_thrd; i++)
  pthread_join (thread[i], NULL);
   cout<<"\n\n";
   print_matrix(A);
   cout<<"\n\n\t *"<<endl;
   print_matrix(B);
   cout<<"\n\n\t="<<endl;
   print_matrix(C);
   cout<<"\n\n";
   free(thread);

  return 0;

}
