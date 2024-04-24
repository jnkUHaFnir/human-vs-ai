#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

int open_serial_port(const char *port_name, int baud_rate, int parity) {
    int fd = open(port_name, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) {
        perror("Error opening serial port");
        return -1;
    }

    struct termios tty;
    if (tcgetattr(fd, &tty) != 0) {
        perror("Error getting serial port attributes");
        close(fd);
        return -1;
    }

    cfsetospeed(&tty, baud_rate);
    cfsetispeed(&tty, baud_rate);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;      // 8-bit characters
    tty.c_iflag &= ~IGNBRK;                          // ignore break signal
    tty.c_lflag = 0;                                 // no signaling chars, no echo, 
                                                      // no canonical processing
    tty.c_oflag = 0;                                 // no remapping, no delays
    tty.c_cc[VMIN]  = 0;                             // read doesn't block
    tty.c_cc[VTIME] = 5;                             // 0.5 seconds read timeout

    tty.c_iflag &= ~(IXON | IXOFF | IXANY);          // shut off xon/xoff ctrl
    tty.c_cflag |= (CLOCAL | CREAD);                 // ignore modem controls,
                                                      // enable reading
    tty.c_cflag &= ~(PARENB | PARODD);               // shut off parity
    tty.c_cflag |= parity;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        perror("Error setting serial port attributes");
        close(fd);
        return -1;
    }

    return fd;
}

int main() {
    const char *port_name = "/dev/ttyUSB1";
    int baud_rate = B115200;
    int parity = 0;

    int fd = open_serial_port(port_name, baud_rate, parity);
    if (fd < 0) {
        printf("Error opening serial port\n");
        return 1;
    }

    // Write to the serial port
    const char *write_buffer = "Hello, Serial Port!";
    int n_written = write(fd, write_buffer, strlen(write_buffer));

    // Read from the serial port
    char read_buffer[256];
    int n_read = read(fd, read_buffer, sizeof(read_buffer) - 1);
    read_buffer[n_read] = '\0';

    printf("Received %d bytes: %s\n", n_read, read_buffer);

    close(fd);
    return 0;
}
gcc -o serial_example serial_example.c -ltermios
