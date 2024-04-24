#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void WriteToPipe(std::vector<int> &data, int fd) {
    write(fd, &data[0], data.size() * sizeof(int));
}

int main() {
    std::vector<int> B(1920 * 1080 * 3); // Assuming each frame has RGB values

    // Create the named pipe
    std::string pipeName = "myfifo";
    mkfifo(pipeName.c_str(), 0666);

    // Open the pipe for writing
    int fd = open(pipeName.c_str(), O_WRONLY);

    // Check if pipe opened successfully
    if (fd < 0) {
        std::cerr << "Error opening pipe" << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        // Generate frame
        generateframe(B, i+1);
        
        // Write frame data to pipe
        WriteToPipe(B, fd);
    }

    // Close the pipe
    close(fd);

    // Remove the named pipe
    unlink(pipeName.c_str());

    return 0;
}
