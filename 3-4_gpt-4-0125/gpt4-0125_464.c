#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <string.h>
int serial_port = open("/dev/ttyUSB1", O_RDWR);
if (serial_port < 0) {
    perror("Error opening serial port");
    exit(EXIT_FAILURE);
}
struct termios tty;

// Read existing settings
if(tcgetattr(serial_port, &tty) != 0) {
    perror("Error from tcgetattr");
    exit(EXIT_FAILURE);
}

tty.c_cflag &= ~PARENB;         // Clear parity bit, disabling parity
tty.c_cflag &= ~CSTOPB;         // Clear stop field, only one stop bit used
tty.c_cflag &= ~CSIZE;          // Clear all bits that set the data size 
tty.c_cflag |= CS8;             // 8 bits per byte
tty.c_cflag &= ~CRTSCTS;        // Disable RTS/CTS hardware flow control
tty.c_cflag |= CREAD | CLOCAL;  // Turn on READ & ignore ctrl lines (CLOCAL = 1)

tty.c_lflag &= ~ICANON;
tty.c_lflag &= ~ECHO;           // Disable echo
tty.c_lflag &= ~ECHOE;          // Disable erasure
tty.c_lflag &= ~ECHONL;         // Disable new-line echo
tty.c_lflag &= ~ISIG;           // Disable interpretation of INTR, QUIT and SUSP
tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

tty.c_oflag &= ~OPOST;          // Prevent special interpretation of output bytes (e.g., newline chars)
tty.c_oflag &= ~ONLCR;          // Prevent conversion of newline to carriage return/line feed

// Set in/out baud rate to be 9600
cfsetispeed(&tty, B9600);
cfsetospeed(&tty, B9600);

// Save tty settings, also checking for error
if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
    perror("Error from tcsetattr");
    exit(EXIT_FAILURE);
}
// Write to the serial port
const char *msg = "Hello, serial port!";
write(serial_port, msg, strlen(msg));

// Read from the serial port
char read_buf[256];
memset(&read_buf, '\0', sizeof(read_buf));
int num_bytes = read(serial_port, &read_buf, sizeof(read_buf));

if (num_bytes < 0) {
    perror("Error reading");
    exit(EXIT_FAILURE);
}

printf("Read %i bytes: %s", num_bytes, read_buf);
close(serial_port);
