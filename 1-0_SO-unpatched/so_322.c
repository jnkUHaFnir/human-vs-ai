    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    struct          info
    {
      int           age;
      char          name[30];
    };
    
    int             main()
    {
      struct info * infos = 0;
      int           num = 0;
      char          input_name[30];
      int           input_age;
    
      while (1)
        {
          printf("Enter name and age:\n");
          int r = scanf("%29s", input_name);
          if (strcmp(input_name, "stop") == 0 || r == EOF)
            break;
          scanf(" %d", &input_age);
    
          infos = realloc(infos, sizeof(struct info) * (num + 1));
          infos[num].age = input_age;
          memcpy(infos[num].name, input_name, sizeof(char) * 30);
          num++;
        }
    
      for(int i = 0; i < num ; ++i)
        printf("Name = %s, Age = %d\n", infos[i].name, infos[i].age);
    
      return 0;
    }