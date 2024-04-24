#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

void generateframe(std::vector<int> &B, int i) {
    // Code to generate frame
    // This function will populate the vector B with image data
}

void WriteToPipe(const std::vector<int> &B, FILE *fd) {
    // Write the contents of vector B to the pipe
    fwrite(B.data(), sizeof(int), B.size(), fd);
}

int main() {
    const int width = 1920;
    const int height = 1080;
    const int N = 100000;
    std::vector<int> B(width * height * 3);

    // Create a named pipe
    mkfifo("myfifo", 0666);

    FILE *ffmpeg_pipe = popen("ffmpeg -y -f rawvideo -pix_fmt rgb24 -s 1920x1080 -i pipe:0 -c:v libx264 -preset slow -crf 20 Video.mp4", "w");
    
    for (int i = 0; i < N; i++) {
        generateframe(B, i+1);

        // Write frame data to the pipe
        WriteToPipe(B, ffmpeg_pipe);
    }

    // Close the pipe
    pclose(ffmpeg_pipe);

    // Remove the named pipe
    unlink("myfifo");

    return 0;
}
