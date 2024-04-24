    #include <stdio.h>
    #include <ctype.h>
    int main(void)
    {
      int input_valid = 0; /* Be pessimistic. */
      do
      {
        char repeat[3] = {0};
        printf("Do you want to try again? (Y/N):\n");
        do /* On-time loop, to break out on parsing error. */
        {
          if (NULL == fgets(repeat, sizeof repeat, stdin))
          {
            break; /* Either fgets() failed or EOF was read. Start over ... */
          }
          if (repeat[1] != '\0' && repeat[1] != '\n') 
          {
            break; /* There was more then one character read. Start over ... */
          }
          repeat[0] = toupper(repeat[0]);
          if (repeat[0] != 'Y' && repeat[0] != 'N') 
          {      
            break; /* Something else but Y or N was read. Start over ... */
          }
          input_valid = 1;
        }
        if (input_valid == 0)
        {
          printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
        }
      } while (input_valid == 0)
      puts("Bye!");
      return 0;
    }