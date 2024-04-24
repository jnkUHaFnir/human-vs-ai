This version of the program correctly counts the frequency of each letter, regardless of its case.

Finally, remember to free memory allocated for every word in your array at the end of your program, to avoid memory leaks.
```C
for(i = 0; i < N; i++) 
{
   free(words[i]);
}
