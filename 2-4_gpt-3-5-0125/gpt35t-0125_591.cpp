char* SequenceTokenAnalizer::NextToken(char delim)
{
    if (token != NULL) {
        delete[] token;
    }

    // your existing code here

    // make sure to delete the token at the end of the function before returning
    if (token != NULL) {
        delete[] token;
    }

    return token;
}
