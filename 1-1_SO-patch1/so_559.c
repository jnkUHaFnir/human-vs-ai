    #include <stdio.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    unsigned long loadlfile(const char *path, char *buffer)
    {
        int file_descr;
        FILE *fp;
        struct stat buf;
        char *p = buffer;
        
        fstat((file_descr = open(path, O_RDONLY)), &buf);
    // This check is done at preprocessing and requires no check at runtime.
    // It basically means "If this machine is not of a popular 64bit architecture,
    // it's probably not 128bit and possibly has limits in maximum memory size.
    // This check is done for the sake of omission of malloc(3)'s unnecessary
    // invocation at runtime.
    //    Amd 64               Arm64                      Intel 64       Intel 64 for Microsofts compiler.
    #if !defined(__IA_64) || !defined(__aarch64__) || !defined(__ia64__) || !defined(_M_IA64)
    #define FILE_MAX_BYTES (4000000000)
        // buf.st_size is of off_t, you may need to cast it.
        if(buf.st_size >= FILE_MAX_BYTES-1)
            return (-1);
    #endif
        
        buffer = malloc(buf.st_size);
        fp = fdopen(file_descr, "rb");
        while((*p++ = fgetc(fp)) != EOF)
            ;
        *p = '\0';
        
        return (unsigned long)buf.st_size;
    }