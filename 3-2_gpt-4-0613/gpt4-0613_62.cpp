else 
{
    // Create new bigger array
    char** bigger_array = new char* [meanings_ctr+1];

    // Copy old meanings to bigger_array
    for(int i = 0; i < meanings_ctr; i++)
    {
        bigger_array[i] = meanings[i];
    }

    // Add new meaning
    bigger_array[meanings_ctr] = new char [strlen(p2c) + 1];
    strcpy(bigger_array[meanings_ctr], p2c);

    // Delete old meanings array (not its content)
    delete [] meanings;

    // Point meanings to bigger_array
    meanings = bigger_array;
    meanings_ctr++;
}
Expression::~Expression() 
{
    delete [] meanings;  // Deleting the array of pointers, not their content 
    delete [] word_with_several_meanings;
}
Expression::~Expression() 
{
    for(int i = 0; i < meanings_ctr; i++)
    {
        delete [] meanings[i];
    }
    delete [] meanings;  
    delete [] word_with_several_meanings;
}
