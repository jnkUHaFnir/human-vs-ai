    printf("Enter numbers to average. Type Q to quit.\n");
    char buf[256];
    double sum=0, temp;
    int ii = 0;
    while(1)
    {
        printf("Input: \t");
        fgets(buf, 255, stdin);
        if (tolower(buf[0])=='q') break;
        ii++;
        sscanf(buf, "%ld", &temp);
        sum += temp;
        printf("At this point the average is %lf\n", sum / (double)ii);
    }
    
    printf("Done. The final average of the %d numbers is %lf\n", ii, sum / ii);