void Expression::add_meaning(char * p2c)
{
    ...
    else 
    {
        ...
        // Allocate new memory to meanings[]
        meanings = new char * [meanings_ctr+1];
        for(int i =0; i<meanings_ctr; i++)
        {
             meanings[i] = new char [strlen(temp_meaning[i]) + 1];
             strcpy(meanings[i], temp_meaning[i]);
             delete [] temp_meaning[i]; // free memory allocated to temp_meaning[i]
        }
        meanings[meanings_ctr] = new char [strlen(p2c) + 1];
        strcpy(meanings[meanings_ctr++], p2c);
        delete [] temp_meaning; // free memory allocated to temp_meaning[]
    }
}
Expression::Expression(int mctr )
{
    meanings_ctr = mctr;    // Setting the counter to 0
    meanings = new char * [meanings_ctr]; // Allocate Space for meanings
    word_with_several_meanings = NULL; // Initialize word_with_several_meanings to NULL
}
``` 

This should solve your problem. In general, take care to avoid double freeing memory. It is better to set pointers to NULL after deleting them, so calling `delete` on them subsequently will have no effect as it is safe to `delete` a NULL pointer in C++.
