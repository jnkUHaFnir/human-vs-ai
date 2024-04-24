    #include <stdio.h>
    #include <string.h>
    
    struct employee {
            int cardNo;
            char name[20];
            long salary;
            int age;
    } emp[20] = {
            {},
            {1, "Steve xyz", 7000, 30},
    };
    
    int main(void)
    {
            char empName[30];
            printf("Enter your name\n");
    
            char *ret = fgets(empName, 30, stdin);
            if (ret == NULL) {
                    printf("Error while reading name\n");
                    return 1;
            }
    
            // remove new line if present
            size_t len = strlen(empName);
            if (len > 0 && empName[len - 1] == '\n') {
                    empName[len - 1] = '\0';
                    // decrease len by one (if you want to use later)
                    // since now the string as one less character
                    len -= 1;
            }
    
            if (!(strcmp(empName,emp[1].name))) {      // 1
                    // I don't know why you do this...
                    strcpy(empName, "Steve xyz");
            } else {
                    printf("Invalid name\n");          // 2
            }
    }