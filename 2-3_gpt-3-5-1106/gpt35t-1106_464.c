#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

int main() {
  int fd = open("/dev/ttyUSB1", O_RDWR | O_NOCTTY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  struct termios serial;
  tcgetattr(fd, &serial);

  // Set baud rate
  cfsetospeed(&serial, B9600);
  cfsetispeed(&serial, B9600);

  // Set parity
  serial.c_cflag |= PARENB;
  serial.c_cflag &= ~PARODD;

  tcsetattr(fd, TCSANOW, &serial);

  // Now you can use read() and write() to read and write to the serial port

  close(fd);
  return 0;
}
