#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Create a named pipe before calling this function
void WriteToPipe(std::vector<int> &frameData, FILE *fd) {
    fwrite(frameData.data(), sizeof(int), frameData.size(), fd);
}

int main() {
    std::vector<int> B(width * height * 3);
    FILE *fd = fopen("myfifo", "wb");

    if (fd == NULL) {
        perror("Error opening named pipe");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < N; i++) {
        generateframe(B, i + 1);
        WriteToPipe(B, fd);
        fflush(fd);
    }

    fclose(fd);

    // Cleanup the named pipe after use
    unlink("myfifo");

    return 0;
}

This command tells ffmpeg to read raw RGB data from the named pipe `myfifo` and encode it using the x264 codec into an output video file. Adjust the video size, framerate, and other options as needed for your use case.
