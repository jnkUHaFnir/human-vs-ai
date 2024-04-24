#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

int main() {
    const char* portname = "/dev/ttyUSB1";
    int fd = open(portname, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        perror("Error opening serial port");
        return 1;
    }

    struct termios tty;
    memset(&tty, 0, sizeof(tty));
    if (tcgetattr(fd, &tty) != 0) {
        perror("Error from tcgetattr");
        close(fd);
        return 1;
    }

    cfsetospeed(&tty, B9600); // Set baud rate
    cfsetispeed(&tty, B9600);

    tty.c_cflag |= (CLOCAL | CREAD); // Enable receiver
    tty.c_cflag &= ~PARENB; // No parity
    tty.c_cflag &= ~CSTOPB; // One stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8; // 8 data bits

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        perror("Error from tcsetattr");
        close(fd);
        return 1;
    }

    // Write data
    char data[] = "Hello, Serial!";
    write(fd, data, sizeof(data));

    // Read data
    char buffer[256];
    int n = read(fd, buffer, sizeof(buffer));
    if (n > 0) {
        printf("Received: %.*s", n, buffer);
    }

    close(fd);
    return 0;
}
