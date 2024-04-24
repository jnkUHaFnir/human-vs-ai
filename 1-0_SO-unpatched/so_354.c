    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>
    
    int main(int argc, char* argv[])
    {
      int fd1;
      int fd2;
      size_t len;
      size_t nbytes;
      ssize_t bytes_read;
      FILE *fp;
      fp = fopen("./file1.txt","r");
      if(fp != NULL) {
        fseek(fp, 0L, SEEK_END);
        len = ftell(fp);
        rewind(fp);
        fclose(fp);
      }else {
        printf("can\'t open fp\n");
        exit(-1);
      }
      fd1 = open("./file1.txt", O_RDWR);
      fd2 = open("./file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644 );
      char buf[len];
      memset(buf,'\0',len);
      nbytes = sizeof(buf);
      if((fd1 != -1) && (fd2 != -1)){
        bytes_read = read(fd1, buf, nbytes);
        write(fd2, buf, nbytes);
        close(fd1);
        close(fd2);
      }else {
        printf("error \n");
        exit(-1);
      }
    
      return 0;
    
    }