#include <iostream>
#include <vector>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void generateframe(std::vector<int> &B, int i) {
    // Your implementation to generate frames
}

void WriteToPipe(std::vector<int> &B, int fd) {
    write(fd, B.data(), B.size() * sizeof(int));
}

int main() {
    std::vector<int> B(width*height*3);
    int fd = open("myfifo", O_WRONLY);

    for (int i = 0; i < N; i++) {
        generateframe(B, i+1);
        WriteToPipe(B, fd);
    }

    close(fd);
    return 0;
}
mkfifo myfifo
./your_program &
ffmpeg -f rawvideo -pixel_format rgb24 -video_size 1920x1080 -i myfifo -c:v libx264 -preset slow -crf 20 Video.mp4
