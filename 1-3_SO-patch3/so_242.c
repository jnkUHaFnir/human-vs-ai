    #include <errno.h>
    #include <limits.h>
    // Returns the number of bytes read.
    // EOF was reached if the number of bytes read is less than requested.
    // On error, returns -1 and sets errno.
    ssize_t recv_fixed_amount(int sockfd, char *buf, size_t size) {
       if (size > SSIZE_MAX) {
          errno = EINVAL;
          return -1;
       }
    
       ssize_t bytes_read = 0;
       while (size > 0) {
          ssize_t rv = recv(sockfd, buf, size, 0); 
          if (rv <= 0)
             return rv;
    
          size -= rv;
          bytes_read += rv;
          buf += rv;
       }
    
       return bytes_read;
    }