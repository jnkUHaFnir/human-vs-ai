int main() {
    std::ifstream file("numbers.txt", std::ios::binary);

    if (!file) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    char numbers[4][16]; // note char[16] for null terminator

    unsigned lines = 0;
    while (lines < 4 && file.getline(numbers[lines], 16)) {
        ++lines;
    }

    // Optional: Output read numbers to check what was read
    for(unsigned i = 0; i < lines; ++i) {
        std::cout << numbers[i] << std::endl;
    }

    file.close(); // Closing the file (optional, since it will close automatically at the end of main)

    return 0;
}
