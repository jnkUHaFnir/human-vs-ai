        scanf("%d", &age); //scans only once
        do //enters loop
        {
            if (age == 32767)
            {
                printf("Error, retry: \n");
            }
            else
            {
                printf("Cool.");
            }
        } while(age!=32767);