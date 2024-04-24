FILE *fd;
mkfifo("myfifo", 0666);

fd = fopen("myfifo", "wb");

for (i=0; i<N; i++)
{
    generateframe(B, i+1);
    WriteToPipe(B, fd); // void WriteToPipe(std::vector<int>, FILE *&fd)
    fflush(fd);
}

fclose(fd);
unlink("myfifo");
./myprogram > myfifo & ffmpeg -i myfifo -c:v libx264 -preset slow -crf 20 Video.mp4
