    #include <cstring>
    
    int main()
    {
        //no need to use std::ios_base::binary since it's ASCII data
        std::ifstream file("numbers.txt");
    
        //allocate one more position in array for the NULL terminator
        char numbers[4][16];
    
        //you only have 4 lines, so don't use EOF since that will cause an extra read
        //which will then cause and extra loop, causing undefined behavior
        for (unsigned lines = 0; lines < 4; ++lines)
        {
            //copy into your buffer that also includes space for a terminating null
            //placing in if-statement checks for the failbit of ifstream
            if (file.getline(numbers[lines], 16,'\n'))
            {
                continue;
            {
            else
            {
                //make sure to place a terminating NULL in empty string
                //since the read failed
                numbers[lines][0] = '\0'
            }
        }
    
    }