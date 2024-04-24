    unsigned char* bit_encrypt(const char* text)
    {
        int len = 0;
        //validate input:
        if(!text) return NULL;
        if((len = strlen(text)) == 0) return NULL;//capture length using strlen once, leave if 0
        char text_copy[len+1]; //+1 for termination char , uninitialized
        memset(text_copy, 0, sizeof(text_copy));//initialized  
        printf("Strlen: %ld\n", len);
        bool bits[len][8]; //uninitialized
        memset(bits, 0, sizeof(bits));//initialized
        int dec = 0;
        int j = 0;