int main()
{
    std::ifstream file("numbers.txt");

    char num[15][4];

    for (unsigned lines = 0; lines < 4; ++lines)
    {
        file.getline(num[lines], 16, '\n');
    }

    // Print the array
    for (unsigned i = 0; i < 4; ++i)
    {
        std::cout << num[i] << std::endl;
    }

    return 0;
}