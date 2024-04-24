    #include <cstring>
    
    int main()
    {
        //no need to use std::ios_base::binary since it's ASCII data
        std::ifstream file("numbers.txt");
    
        char numbers[4][16];
    
        //you only have 4 lines, so don't use EOF since that will cause an extra read
        for (unsigned lines = 0; lines < 4; ++lines)
        {
            //copy into a temp buffer that also includes space for a terminating null
            char temp[16];
            file.getline(temp, 16,'\n');
            //make sure there is a terminating null at the end of the string
            temp[16] = '\0'; 
    
            //copy the string into your original array
            strcpy(numbers[lines], temp);
        }
    
    }