#include <cstdio>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <sys/stat.h>


// Assuming generateframe and WriteToPipe are defined somewhere
// void generateframe(std::vector<int>& buffer, int frameIndex);
// void WriteToPipe(const std::vector<int>& buffer, FILE* fd);

int main() {
    const char* fifoPath = "myfifo";
    const int N = 100000; // Number of frames
    const int width = 1920, height = 1080;
    std::vector<int> B(width * height * 3);

    // Creating named pipe
    unlink(fifoPath); // Ensure the fifo does not already exist
    if (mkfifo(fifoPath, 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }

    // Async call to FFmpeg
    // Note: Adjust the path to FFmpeg binary if necessary and add your preferred FFmpeg options
    std::string ffmpegCommand = "ffmpeg -y -f rawvideo -vcodec rawvideo -pixel_format rgb24 -video_size 1920x1080 -framerate 25 -i " + std::string(fifoPath) + " -c:v libx264 -preset slow -crf 20 Video.mp4 &";
    system(ffmpegCommand.c_str());

    // Open the FIFO for writing
    FILE* fd = fopen(fifoPath, "wb");
    if (!fd) {
        perror("fopen failed");
        unlink(fifoPath);
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        generateframe(B, i+1); // Remember to fill buffer with actual pixel data
        WriteToPipe(B, fd);
        fflush(fd);
    }

    // Cleanup
    fclose(fd);
    unlink(fifoPath);

    return 0;
}
