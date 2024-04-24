#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

FILE *fd;
mkfifo("myfifo", 0666);

for (i=0; i<N; i++)
{
  fd=fopen("myfifo", "wb");
  if(fd == NULL){
    printf("Error opening named pipe\n");
    return 1;
  }
  generateframe(B, i+1);
  WriteToPipe(B, fd); // void WriteToPipe(std::vector<int>, FILE *&fd)
  fflush(fd);
  fclose(fd);
}
unlink("myfifo");
