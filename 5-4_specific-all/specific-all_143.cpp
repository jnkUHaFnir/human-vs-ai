#include <iostream>
#include <vector>
#include <cstdio>
#include <unistd.h>

int main() {
    std::vector<int> B(1920*1080*3);
    FILE *fd;

    // Create a named pipe
    mkfifo("myfifo", 0666);

    // Open ffmpeg process for writing video
    FILE *ffmpeg_pipe = popen("ffmpeg -y -f rawvideo -pixel_format rgb24 -video_size 1920x1080 -framerate 30 -i pipe:0 -c:v libx264 -preset slow -crf 20 output.mp4", "w");

    for (int i = 0; i < 100000; i++) {
        fd = fopen("myfifo", "wb");
        // Generate frame here
        // generateframe(B, i+1);

        // Write frame to pipe
        fwrite(B.data(), sizeof(int), B.size(), fd);
        fclose(fd);

        // Read frame from pipe and pass it to ffmpeg
        fd = fopen("myfifo", "rb");
        fseek(fd, 0L, SEEK_END);
        long size = ftell(fd);
        rewind(fd);
        fread(B.data(), sizeof(int), size / sizeof(int), fd);
        fwrite(B.data(), sizeof(int), size / sizeof(int), ffmpeg_pipe);
        fclose(fd);
    }

    // Close ffmpeg pipe
    pclose(ffmpeg_pipe);

    // Remove the named pipe
    unlink("myfifo");

    return 0;
}
