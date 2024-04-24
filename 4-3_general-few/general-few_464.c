#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

int main() {
    int serial_port = open("/dev/ttyUSB1", O_RDWR);
    if (serial_port < 0) {
        perror("Error opening serial port");
        return -1;
    }
    
    // Set serial port settings
    struct termios tty;
    tcgetattr(serial_port, &tty);
    cfsetospeed(&tty, B9600); // Set baud rate to 9600
    tty.c_cflag &= ~PARENB; // Disable parity
    tcsetattr(serial_port, TCSANOW, &tty);
    
    // Read and write to serial port here
    
    close(serial_port);
    
    return 0;
}
