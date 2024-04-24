int main()
{
    std::ifstream file("numbers.txt",std::ios::binary);
    char numbers[4][15];

    unsigned lines = 0;
    while(file.getline(numbers[lines],15,'\n'))
    {
        ++lines;
    }
}
