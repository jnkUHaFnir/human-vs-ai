    int size = -1;
    int MAX_TRIES = 10;
    while (MAX_TRIES--)
    {
      printf("Size of tower (0 <= x < 23): ");
      if (scanf("%i", &size) != 1)
      {
        printf("Read error!!\n");
        break;
      }
      if (size >= 0 && size < 23)
      {
        break;
      }
      
      printf("Error: You entered '%d' which is not in the range 0 <= x < 23\n", size);
    }