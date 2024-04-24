    unsigned char* bit_encrypt(const char* text)
    {
        //validate input:
        if(!text) return NULL;
        if(strlen(text) == 0) return NULL;
        char text_copy[strlen(text)] = {0}; //initialized