    int size = -1;
    while (1)
    {
      printf("Size of tower (0 <= x < 23): ");
      scanf_ret =  scanf("%i", &size);
      if (scanf_ret != 1)
      {
        printf("Read error!!\n");
        break;
      }
      if (size >= 0 && size < 23)
      {
        break;
      }
      printf("Error!!\n");
    }