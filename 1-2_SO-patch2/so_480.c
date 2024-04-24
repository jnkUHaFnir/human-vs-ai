    #include <stdio.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <string.h>
    
    struct info
    {
        int age;
        char name[30];
    };
    
    int main()
    {
        struct info *ptr = 0;
        size_t num = 0;
        
        for (;;) {
            printf("Enter name and age. If you want to stop, type only 'stop'.\n");
            char line[256];
            if (fgets(line, sizeof(line), stdin) < 0) { 
                 fprintf(stderr, "fgets error");
                 exit(-1);
            }
            if (!strcmp("stop\n", line)) {
                 break;
            }
            struct info tmp;
            if (sscanf(line, "%29s %d\n", tmp.name, &tmp.age) != 2) {
                 fprintf(stderr, "error parsing line\n");
                 exit(-1);
            }
            ptr = realloc(ptr, (num + 1) * sizeof(*ptr));
            if (ptr == NULL) { 
                 fprintf(stderr, "error allocating memory!\n");
                 exit(-1);
            }
            ptr[num] = tmp;
            ++num;
        }
    
    
        for (size_t i = 0; i < num ; ++i) {
            printf("Name = %s, Age = %d\n", ptr[i].name, ptr[i].age);
        }
    
        free(ptr);
        
        return 0;
    }