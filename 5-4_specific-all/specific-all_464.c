#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

int main() {
    int serial_port = open("/dev/ttyUSB1", O_RDWR);
    if (serial_port < 0) {
        perror("Error opening serial port");
        return 1;
    }

    struct termios tty;
    struct termios tty_old;
    memset(&tty, 0, sizeof(tty));

    if (tcgetattr(serial_port, &tty) != 0) {
        perror("Error from tcgetattr");
        return 1;
    }

    tty.c_cflag |= CREAD | CLOCAL;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 5;

    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        perror("Error from tcsetattr");
        return 1;
    }

    unsigned char buf[256];
    memset(&buf, '\0', sizeof(buf));
    strcpy(buf, "Hello, Serial Port!");

    write(serial_port, buf, sizeof(buf));

    int n = read(serial_port, &buf, sizeof(buf));
    if (n < 0) {
        perror("Error reading from serial port");
        return 1;
    }

    printf("Received: %s\n", buf);

    close(serial_port);
    return 0;
}
