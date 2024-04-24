    printf("Enter numbers to average. Type Q to quit, or C to clear calculation.\n");
    char buf[256];
    double sum=0, temp;
    int ii = 0;
    while(1)
    {
        printf("Input: \t");
        fgets(buf, 255, stdin);
        if (tolower(buf[0])=='q') break;
        // allow user to "clear" input and start again:
        if (tolower(buf[0])=='c') {
          sum = 0;
          ii = 0;
          printf("Calculation cleared; ready for new input\n");
          continue;
        }
        ii++;
        sscanf(buf, "%lf", &temp);
        sum += temp;
        printf("At this point the average is %lf\n", sum / (double)ii);
    }
    
    printf("Done. The final average of the %d numbers is %lf\n", ii, sum / ii);