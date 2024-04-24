    int size = -1;
    while (1)
    {
      printf("Size of tower (0 <= x < 23): ");
      scanf("%i", &size);
      if (size <= 23 && size >= 0)
      {
        break;
      }
      printf("Error!!");
    }