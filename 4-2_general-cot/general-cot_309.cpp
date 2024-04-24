#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

void WriteToPipe(std::vector<int> &B, FILE *fd) {
    fwrite(B.data(), sizeof(int), B.size(), fd);
}

void generateframe(std::vector<int> &B, int frame_number) {
    // Implementation of generateframe function
    // This is a dummy implementation, replace it with your actual logic
    for (size_t i = 0; i < B.size(); i++) {
      B[i] = frame_number; // Dummy data, replace with actual frame data generation
    }
}

int main() {
    const int width = 1920;
    const int height = 1080;
    const int N = 5; // For testing purposes, set it to a small number

    std::vector<int> B(width * height * 3);
    
    FILE *fd = popen("ffmpeg -y -f rawvideo -pixel_format rgb24 -video_size 1920x1080 -framerate 30 -i pipe: -c:v libx264 -preset slow -crf 20 Video.mp4", "w");

    for (int i = 0; i < N; i++) {
        generateframe(B, i + 1);
        WriteToPipe(B, fd);
    }

    pclose(fd);

    return 0;
}
