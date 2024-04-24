#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *fd;
    mkfifo("myfifo", 0666);

    fd = fopen("myfifo", "wb");

    for (int i = 0; i < N; i++) {
        generateframe(B, i + 1);
        WriteToPipe(B, fd);
    }

    fclose(fd);
    unlink("myfifo");

    return 0;
}
