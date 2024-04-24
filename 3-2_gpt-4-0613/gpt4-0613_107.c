
You should also consider freeing these matThread objects after the associated thread has been finished (cleaned up by pthread_join) to avoid memory leaks. To do that, you need to make use of the thread return value:

```c++
for (i = 1; i < num_thrd; i++) {
  matThread* ret;
  pthread_join(thread[i], (void**)&ret);
  delete ret;
}
``` 

This, along with proper synchronization if necessary, should prevent any potential segmentation faults due to concurrent access and modification of memory.
