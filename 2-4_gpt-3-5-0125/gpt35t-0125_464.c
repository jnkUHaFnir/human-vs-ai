int fd = open("/dev/ttyUSB1", O_RDWR | O_NOCTTY);
if (fd < 0) {
    perror("Error opening serial port");
    return -1;
}
struct termios tty;
if (tcgetattr(fd, &tty) != 0) {
    perror("Error from tcgetattr");
    return -1;
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
if (tcsetattr(fd, TCSANOW, &tty) != 0) {
    perror("Error from tcsetattr");
    return -1;
}
char buf[256];
int nbytes = read(fd, buf, sizeof(buf));
if (nbytes < 0) {
    perror("Error reading from serial port");
    return -1;
}
char data[] = "Hello, World!";
if (write(fd, data, sizeof(data)) < 0) {
    perror("Error writing to serial port");
    return -1;
}
close(fd);
