#include <cstdio>
#include <vector>
#include <iostream>

void generateframe(std::vector<int> &B, int i) {
  // Implement your generateframe function
}

void WriteToPipe(const std::vector<int> &B, FILE *fd) {
  // Implement writing to the pipe here
  fwrite(B.data(), sizeof(int), B.size(), fd);
}

int main() {
  FILE *fd;
  mkfifo("myfifo", 0666);
  
  std::vector<int> B(width*height*3);
  for (int i = 0; i < N; i++) {
    fd = fopen("myfifo", "wb");
    generateframe(B, i+1);
    WriteToPipe(B, fd);
    fclose(fd);
  }
  
  unlink("myfifo");
  
  return 0;
}
ffmpeg -i /dev/pipe:myfifo -c:v libx264 -preset slow -crf 20 Video.mp4
