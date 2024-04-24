#include <iostream>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void generateframe(std::vector<int> &B, int frame_number) {
    // Implementation of generateframe function
}

void WriteToPipe(std::vector<int> &B, int fd) {
    write(fd, B.data(), B.size() * sizeof(int));
}

int main() {
    std::vector<int> B(1920 * 1080 * 3); // Assuming 1920x1080 resolution and 3 channels (RGB)
    const int N = 100000;
    int fd;
    mkfifo("myfifo", 0666);

    std::string ffmpeg_command = "ffmpeg -y -f rawvideo -pixel_format rgb24 -video_size 1920x1080 -framerate 30 -i pipe:myfifo -c:v libx264 -preset slow -crf 20 Generated_Video.mp4";

    FILE *pipe = popen(ffmpeg_command.c_str(), "w");
    if (!pipe) {
        std::cerr << "Error opening pipe to ffmpeg." << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        generateframe(B, i+1);

        fd = open("myfifo", O_WRONLY);
        if (fd < 1) {
            std::cerr << "Error opening FIFO for writing." << std::endl;
            return 1;
        }

        WriteToPipe(B, fd);
        close(fd);
    }

    pclose(pipe);
    unlink("myfifo");

    return 0;
}
