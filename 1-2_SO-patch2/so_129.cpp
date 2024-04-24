    #include <cstring>
    
    int main()
    {
        //no need to use std::ios_base::binary since it's ASCII data
        std::ifstream file("numbers.txt");
    
        //allocate one more position in array for the NULL terminator
        char numbers[4][16];
    
        //you only have 4 lines, so don't use EOF since that will cause an extra read
        for (unsigned lines = 0; lines < 4; ++lines)
        {
            //copy into your buffer that also includes space for a terminating null
            file.getline(numbers[i], 16,'\n');
        }
    
    }