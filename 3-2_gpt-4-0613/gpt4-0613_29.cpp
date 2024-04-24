FILE* fp = fopen("test.txt", "r");
if (fp == NULL) {
    perror("Cannot open test.txt");
    return EXIT_FAILURE;
} 

if (other_condition) {
    fclose(fp); // Close the file under all circumstances
    perror("other error occurred!");
    return EXIT_FAILURE;
} 

// Do something with the file...
// ...

fclose(fp);  // Don't forget to close the file when we're done with it.
class File {
public:
    explicit File(const char* filename, const char* mode) {
        fp = fopen(filename, mode);
        if (fp == NULL) {
            throw std::runtime_error("Could not open file.");
        }
    }

    ~File() {
        if (fp != NULL) {
            fclose(fp);
        }
    }

    FILE* get() {
        return fp;
    }

private:
    FILE* fp;
};
try {
    File file("test.txt", "r");
    // Do something with file.get()...
} 
catch (std::runtime_error& e) {
    std::cout << e.what() << std::endl;
    return EXIT_FAILURE;
}
