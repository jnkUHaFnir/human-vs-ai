#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

int main() {
    int serial_port = open("/dev/ttyUSB1", O_RDWR);
    
    struct termios tty;
    struct termios tty_old;
    memset(&tty, 0, sizeof(tty));

    if(tcgetattr(serial_port, &tty) != 0) {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }

    tty.c_cflag &= ~(PARENB | CSTOPB | CSIZE | CRTSCTS);
    tty.c_cflag |= CS8;
    tty.c_lflag = 0;
    tty.c_oflag = 0;
    tty.c_cc[VMIN] = 0;
    tty.c_cc[VTIME] = 0;

    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    if(tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }

    unsigned char buf[80];
    memset(&buf, '\0', sizeof(buf));

    // Read data
    ssize_t num_bytes = read(serial_port, &buf, sizeof(buf));
    printf("Read %d bytes.\n", num_bytes);

    // Write data
    char msg[] = "Hello from the serial port!\n";
    write(serial_port, msg, sizeof(msg));

    close(serial_port);
    return 0;
}
