int main()
{
    std::ifstream file("numbers.txt",std::ios::binary);
    
    char numbers[4][15];
    
    for (unsigned lines = 0; lines < 4; ++lines)
    {
        if(!(file.getline(numbers[lines], 15, '\n'))) 
        {
            break; // Exit the loop if the read operation fails
        }
    }
}
