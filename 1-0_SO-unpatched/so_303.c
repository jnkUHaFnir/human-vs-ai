    #include <stdio.h>
    
    int main(void)
    {
        int hours, minutes, time;
    
        // Get the user's time
        printf("Enter a 24 hour time (hh:mm): \n");
        if (scanf("%d:%d", &hours, &minutes) == 2)
        {
            time = hours * 60 + minutes;
            find_and_print_nearest_time(time);
        }
        return(0);
    }