#include <cstdio>

int main() {
    std::vector<int> B(width*height*3);
    FILE *fd = fopen("myfifo", "wb");
    
    if (!fd) {
        perror("Error opening named pipe");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        generateframe(B, i+1);
        WriteToPipe(B, fd); // Write frame data to the named pipe
        fflush(fd);
    }

    fclose(fd);
    
    return 0;
}
./myprogram | ffmpeg -f rawvideo -pix_fmt rgb24 -s 1920x1080 -i myfifo -c:v libx264 -preset slow -crf 20 output.mp4
