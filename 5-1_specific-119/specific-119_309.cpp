#include <iostream>
#include <cstdio>
#include <vector>
#include <unistd.h>

void WriteToPipe(const std::vector<int>& B, FILE* fd) {
    fwrite(B.data(), sizeof(int), B.size(), fd);
}

int main() {
    std::vector<int> B(1920*1080*3);
    FILE* fd = fopen("myfifo", "wb");

    if (!fd) {
        std::cerr << "Error opening named pipe (fifo)!" << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        generateframe(B, i+1);
        WriteToPipe(B, fd);
    }

    fclose(fd);

    return 0;
}
