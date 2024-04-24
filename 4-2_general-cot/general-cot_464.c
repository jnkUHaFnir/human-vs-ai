#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

int main() {
    int serial_port = open("/dev/ttyUSB1", O_RDWR);

    if (serial_port < 0) {
        perror("Error opening serial port");
        return 1;
    }

    struct termios tty;
    memset(&tty, 0, sizeof(tty));

    if(tcgetattr(serial_port, &tty) != 0) {
        perror("Error from tcgetattr");
        return 1;
    }

    // Set baud rate
    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    // Set other serial port parameters
    tty.c_cflag &= ~PARENB; // No parity
    tty.c_cflag &= ~CSTOPB; // 1 stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8; // 8 bits per byte
    tty.c_cflag |= CREAD | CLOCAL; // Enable reading and ignore control lines

    tty.c_cc[VMIN] = 1; // Read at least 1 character
    tty.c_cc[VTIME] = 5; // 0.5 seconds read timeout

    if(tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        perror("Error from tcsetattr");
        return 1;
    }

    // Example writing data
    const char* msg = "Hello, serial port!";
    write(serial_port, msg, strlen(msg));

    // Example reading data
    char buf[256];
    int n = read(serial_port, &buf, sizeof(buf));
    if (n > 0) {
        buf[n] = '\0';
        printf("Received message: %s\n", buf);
    }

    close(serial_port);
    return 0;
}
