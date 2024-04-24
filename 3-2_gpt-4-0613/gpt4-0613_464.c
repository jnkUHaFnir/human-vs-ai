#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    // Open the Port. We want read/write, no "controlling tty" status, and open it no matter what state DCD is in
    int serial_port = open("/dev/ttyUSB1", O_RDWR | O_NOCTTY);

    // Create new termios struc, we call it 'tty' for convention
    struct termios tty;
    
    // Read in existing settings, and handle any error
    if(tcgetattr(serial_port, &tty) != 0) {
        printf("Error from tcgetattr: %i\n", errno);
        return 1;
    }
    tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
    tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
    tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size
    tty.c_cflag |= CS8; // 8 bits per byte (most common)
    tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore control lines (CLOCAL = 1)
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow control
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); 
    tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 0;
    cfsetspeed(&tty, B9600); // Set in/out baud rate to be 9600

    // Save tty settings, also checking for error
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Error from tcsetattr: %i\n", errno);
        return 1;
    }

    // Write to serial port
    write(serial_port, "Hello, Serial Port", 18);

    // Allocate memory for read buffer, set size according to your needs
    char read_buf [256];

    // Now read from serial port. Note that this call will block until bytes arrive
    int num_bytes = read(serial_port, &read_buf, sizeof(read_buf));

    // Close the serial port
    close(serial_port);
}

