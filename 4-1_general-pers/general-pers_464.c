#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main() {
    int serial_port = open("/dev/ttyUSB1", O_RDWR);
    if(serial_port == -1) {
        perror("Error opening serial port");
        return 1;
    }

    struct termios tty;
    memset(&tty, 0, sizeof(tty));

    if(tcgetattr(serial_port, &tty) != 0) {
        perror("Error getting serial port attributes");
        return 1;
    }

    // Set baud rate
    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    // Set parity
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;

    // Apply settings
    if(tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        perror("Error setting serial port attributes");
        return 1;
    }

    // Read from serial port
    char buf[256];
    ssize_t n = read(serial_port, buf, sizeof(buf));
    if(n > 0) {
        buf[n] = '\0';
        printf("Received data: %s\n", buf);
    } else if(n == -1) {
        perror("Error reading from serial port");
        return 1;
    }

    // Write to serial port
    const char *data = "Hello, serial port!";
    if(write(serial_port, data, strlen(data)) == -1) {
        perror("Error writing to serial port");
        return 1;
    }

    close(serial_port);

    return 0;
}
