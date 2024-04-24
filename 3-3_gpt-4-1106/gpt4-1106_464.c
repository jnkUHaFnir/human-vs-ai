#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int serial_port = open("/dev/ttyUSB1", O_RDWR);
if(serial_port < 0) {
    perror("open");
    return -1;
}
#include <termios.h>

struct termios tty;

if(tcgetattr(serial_port, &tty) != 0) {
    perror("tcgetattr");
    return -1;
}

cfsetispeed(&tty, B9600); // Input and Output Speed
cfsetospeed(&tty, B9600);

tty.c_cflag &= ~PARENB; // Disable parity
tty.c_cflag &= ~CSTOPB; // One stop bit
tty.c_cflag &= ~CSIZE;  // Clear the current data size setting
tty.c_cflag |= CS8;     // 8 bits per byte
tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control
tty.c_cflag |= CREAD | CLOCAL; // Enable receiver, ignore modem control lines

tty.c_lflag &= ~ICANON;
tty.c_lflag &= ~ECHO; // Disable echo
tty.c_lflag &= ~ECHOE;
tty.c_lflag &= ~ECHONL;
tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT, etc.

tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off software-based flow control
tty.c_iflag &= ~(IGNBRK | BRKINT | INPCK | ISTRIP | INLCR | ICRNL);

tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes
tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

cfsetspeed(&tty, B9600); // You could also use this convenience function

// Set the read timeout parameters
tty.c_cc[VTIME] = 10; // Time to wait for every character (tenths of seconds)
tty.c_cc[VMIN] = 0; // Minimum number of characters to read

// Apply the settings
if(tcsetattr(serial_port, TCSANOW, &tty) != 0) {
    perror("tcsetattr");
    return -1;
}
char buffer[256];
int num_bytes = read(serial_port, &buffer, sizeof(buffer));
if(num_bytes < 0) {
    perror("read");
    return -1;
}
const char* msg = "Hello, Serial Port!";
size_t msg_len = strlen(msg);
int bytes_written = write(serial_port, msg, msg_len);
if(bytes_written < 0) {
    perror("write");
    return -1;
}
close(serial_port);
