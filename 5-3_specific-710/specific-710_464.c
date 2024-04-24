#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int main() {
    int fd;
    struct termios tty;

    fd = open("/dev/ttyUSB1", O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("Error opening serial port");
        return 1;
    }

    // Get current serial port settings
    if (tcgetattr(fd, &tty) != 0) {
        perror("Error getting serial port settings");
        return 1;
    }

    // Set baud rate (e.g., 9600)
    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    // Set other serial port settings (e.g., 8N1)
    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8; // 8-bit characters
    tty.c_cflag &= ~PARENB; // no parity
    tty.c_cflag &= ~CSTOPB; // 1 stop bit
    tty.c_cflag &= ~CRTSCTS; // no hardware flow control

    // Apply settings
    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        perror("Error setting serial port settings");
        return 1;
    }

    // Write data to serial port
    char data[] = "Hello, Serial Port!";
    write(fd, data, strlen(data));

    // Read data from serial port
    char buffer[256];
    int bytes_read = read(fd, buffer, sizeof(buffer)-1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        printf("Received data: %s\n", buffer);
    }

    close(fd);
    return 0;
}
