    #include <stdio.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #define FILE_MAX_BYTES (4000000000)
    unsigned long loadlfile(const char *path, char *buffer)
    {
        int file_descr;
        FILE *fp;
        struct stat buf;
        char *p = buffer;
        
        fstat((file_descr = open(path, O_RDONLY)), &buf);
        // buf.st_size is of off_t, you may need to cast it.
        if(buf.st_size >= FILE_MAX_BYTES-1)
            return (-1);
        
        buffer = malloc(buf.st_size);
        fp = fdopen(file_descr, "rb");
        while((*p++ = fgetc(fp)) != EOF)
            ;
        *p = '\0';
        
        return (unsigned long)buf.st_size;
    }