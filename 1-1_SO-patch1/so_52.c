    #include <stdio.h>
    #include <stdlib.h>
    
    // Additional headers
    #include <stdint.h> // for uint32_t
    #include <sys/mman.h> // for mprotect
    #include <errno.h> // for errno
    
    void mocked_dummy(void)
    {
        printf("__%s__()\n",__func__);
    }
    
    /*---- do not modify ----*/
    void dummy(void)
    {
        printf("__%s__()\n",__func__);
    }
    
    int factorial(int num) 
    {
        int                      fact = 1;
        printf("__%s__()\n",__func__);
        while (num > 1)
        {
            fact *= num;
            num--;
        }
        dummy();
        return fact;
    }
    /*---- do not modify ----*/
    
    typedef void (*dummy_fun)(void);
    
    void set_run_mock()
    {
        dummy_fun run_ptr, mock_ptr;
        uint32_t off;
        unsigned char * ptr, * pg;
    
        run_ptr = dummy;
        mock_ptr = mocked_dummy;
    
        if (run_ptr > mock_ptr) {
            off = run_ptr - mock_ptr;
            off = -off - 5;
        }
        else {
            off = mock_ptr - run_ptr - 5;
        }
    
        ptr = (unsigned char *)run_ptr;
    
        pg = (unsigned char *)(ptr - ((size_t)ptr % 4096));
        if (mprotect(pg, 5, PROT_READ | PROT_WRITE | PROT_EXEC)) {
            perror("Couldn't mprotect");
            exit(errno);
        }
    
        ptr[0] = 0xE9; //x86 JMP rel32
        ptr[1] = off & 0x000000FF;
        ptr[2] = (off & 0x0000FF00) >> 8;
        ptr[3] = (off & 0x00FF0000) >> 16;
        ptr[4] = (off & 0xFF000000) >> 24;
    }
    
    int main(int argc, char * argv[])
    {
        // Run for realz
        factorial(5);
    
        // Set jmp
        set_run_mock();
    
        // Run the mock dummy
        factorial(5);
    
        return 0;
    }