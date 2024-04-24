    char line[150];
    printf("Please enter a string terminated by ENTER key:\n");
    gets(line);
    for(i=0; line[i]!='\0'; i++)
    {
        if (line[i]=='a' || line[i]=='A')
            counter[0]++;
        else if (line[i]=='e' || line[i]=='E')
            counter[1]++;
        else if (line[i]=='i' || line[i]=='I')
            counter[2]++;
        else if (line[i]=='o' || line[i]=='O')
            counter[3]++;
        else if (line[i]=='u' || line[i]=='U')
            counter[4]++;
    }
    for(i = 0; i < 5; i++)
        printf("counter[%d] = %d\n", i, counter[i]);