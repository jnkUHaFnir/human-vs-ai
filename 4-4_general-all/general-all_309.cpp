#include <iostream>
#include <vector>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void generateframe(std::vector<int> &B, int frame_num) {
    // Your image generation logic here
}

void WriteToPipe(std::vector<int> &B, FILE *fd) {
    fwrite(B.data(), sizeof(int), B.size(), fd);
}

int main() {
    const char *fifo_name = "myfifo";
    std::vector<int> B(1920 * 1080 * 3);
    FILE *fd;

    // Create named pipe
    mkfifo(fifo_name, 0666);

    for (int i = 0; i < 100000; i++) {
        generateframe(B, i);

        // Open the named pipe for writing
        fd = fopen(fifo_name, "wb");
        if (fd == nullptr) {
            std::cerr << "Error opening pipe" << std::endl;
            return 1;
        }

        // Write frame to the pipe
        WriteToPipe(B, fd);

        // Close the file descriptor
        fclose(fd);
    }

    // Remove named pipe
    unlink(fifo_name);

    return 0;
}
ffmpeg -f rawvideo -pixel_format rgb24 -video_size 1920x1080 -i myfifo -c:v libx264 -preset slow -crf 20 output.mp4
