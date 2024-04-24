#include <termios.h>

int serial_fd; // File descriptor of the opened serial port

struct termios tty;
tcgetattr(serial_fd, &tty);
cfsetispeed(&tty, B9600); // Set baud rate to 9600
cfsetospeed(&tty, B9600);
tty.c_cflag &= ~PARENB; // Disable parity
tty.c_cflag &= ~CSTOPB; // Set 1 stop bit
tty.c_cflag &= ~CSIZE; // Clear data size
tty.c_cflag |= CS8; // Set 8 data bits
tcsetattr(serial_fd, TCSANOW, &tty);
char buffer[255];
int num_bytes = read(serial_fd, buffer, sizeof(buffer));
// Process the received data in the 'buffer' variable
char data[] = "Hello, world!";
int num_bytes = write(serial_fd, data, sizeof(data));
// Ensure all bytes are written before proceeding if necessary
