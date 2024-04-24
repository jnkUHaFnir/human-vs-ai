#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <vector>

void generateframe(std::vector<int> &B, int i) {
    // Implementation of generateframe function
}

void WriteToPipe(std::vector<int> &B, FILE *fd) {
    fwrite(B.data(), sizeof(int), B.size(), fd);
}

int main() {
    const int width = 1920;
    const int height = 1080;
    const int N = 100000;
    
    std::vector<int> B(width * height * 3);

    // Create the named pipe
    mkfifo("myfifo", 0666);

    // Open ffmpeg process for writing to the named pipe
    FILE *ffmpegProcess = popen("ffmpeg -y -f rawvideo -pixel_format rgb24 -video_size 1920x1080 -framerate 30 -i pipe:0 -c:v libx264 -preset slow -crf 20 output.mp4", "w");

    for (int i = 0; i < N; i++) {
        generateframe(B, i + 1);
        WriteToPipe(B, ffmpegProcess);
    }

    // Close the ffmpeg process
    pclose(ffmpegProcess);

    // Remove the named pipe
    unlink("myfifo");

    return 0;
}
