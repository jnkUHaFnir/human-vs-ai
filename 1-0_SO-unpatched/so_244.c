    #include <stdlib.h>
    #include <stdio.h>
    char *get_line()
    {
        int c;
        /* what is the buffer current size? */
        size_t size = 5;
        /* How much is the buffer filled? */
        size_t read_size = 0;
        /* firs allocation, its result should be tested... */
        char *line = malloc(size);
        line[0] = '\0';
        
        c = fgetc(stdin);
        while (c != EOF && c!= '\n')
        {            
            line[read_size] = c;            
            ++read_size;
            if (read_size == size)
            {
                size += 5;
                line = realloc(line, size);
                if (NULL == line)
                {
                    perror("realloc");
                    exit(1);
                }
            }
            c = fgetc(stdin);
        }
        line[read_size] = '\0';
        return line;
    }