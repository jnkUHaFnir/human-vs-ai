#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void generateframe(std::vector<int> &B, int frame_number) {
    // Your frame generation logic here
}

void WriteToPipe(std::vector<int> &B, int fd) {
    write(fd, B.data(), B.size() * sizeof(int));
}

int main() {
    const int width = 1920;
    const int height = 1080;
    const int N = 100000;
    const char* fifo_path = "myfifo";

    mkfifo(fifo_path, 0666); // Create the named pipe

    std::vector<int> B(width * height * 3);

    // Open ffmpeg with the named pipe as input
    std::string ffmpeg_command = "ffmpeg -y -f rawvideo -pixel_format rgb24 -video_size 1920x1080 -framerate 30 -i ";
    ffmpeg_command += fifo_path;
    ffmpeg_command += " -c:v libx264 -preset slow -crf 20 Video.mp4";

    FILE* ffmpeg_process = popen(ffmpeg_command.c_str(), "w");

    for (int i = 0; i < N; i++) {
        generateframe(B, i+1);
        
        // Write frame to the named pipe
        int fd = open(fifo_path, O_WRONLY);
        WriteToPipe(B, fd);
        close(fd);
    }

    pclose(ffmpeg_process);

    unlink(fifo_path); // Remove the named pipe

    return 0;
}
