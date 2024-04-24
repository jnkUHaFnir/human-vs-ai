    #include <stdio.h>
    int main(void)
    {
        int hot=0, pleasant=0, cold=0;
        int sum=0, i=0, temp;
        double average;
        while(1)
        {
            printf("Enter temperature %d> (-99 to stop)",i);
            scanf("%d",&temp);
            if(temp == -99)
              break;
            sum +=temp;
            ++i;
    
            if(temp >= 85)
            {
                ++hot;
                continue;
            }
            if(temp >= 60)
            {
                ++pleasant;
                continue;
            }
    
            ++cold;
        }
        if (i == 0)
        {
          printf("No temperatures entered\n");
          return -1;
        }
        average = (double)sum / i;
    
        printf("The Collection of hot days is %d\n",hot);
        printf("The Collection of pleasant days is %d\n",pleasant);
        printf("The Collection of cold days is %d\n",cold);
        printf("The Average temperature is %.2f\n",average);
        return 0;
    }