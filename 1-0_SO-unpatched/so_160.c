    #include <stdlib.h>
    #include <stdio.h>
    #include <ctype.h>
    int main(void)
    {
      char repeat = '\0';
      {
        int input_valid = 0; /* Be pessimistic. */
        do
        {
          char line[3] = {0};
          puts("Do you want to try again? (Y/N):");
          do /* On-time loop, to break out on parsing error. */
          {
            if (NULL == fgets(line, sizeof line, stdin))
            {
              break; /* Either fgets() failed or EOF was read. Start over ... */
            }
            if (line[1] != '\0' && line[1] != '\n') 
            {
              break; /* There was more then one character read. Start over ... */
            }
            line[0] = toupper(line[0]);
            if (line[0] != 'Y' && line[0] != 'N') 
            {      
              break; /* Something else but Y or N was read. Start over ... */
            }
            input_valid = 1;
          } while (0);
          if (input_valid == 0)
          {
            fprintf(stderr, "Invalid answer. Please enter 'Y' or 'N'.\n\n");
          }
          repeat = line[0];
        } while (input_valid == 0);
      }
      if ('\0' == repeat)
      {
        fprintf(stderr, "Something went wrong\n");
        exit(EXIT_FAILURE);
      }
      printf("The user entered: '%c'\n", repeat); /* Will only print either Y or N. */
      puts("Bye!");
      return EXIT_SUCCESS;
    }