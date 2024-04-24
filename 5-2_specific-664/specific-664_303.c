#include <stdio.h>

int main() {
    // Flight departure times since midnight
    int departures[] = {480, 585, 679, 767, 840, 945, 1140, 1185};
    int arrivals[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    int hours, minutes, time, closest_dep_index, i;
    
    // Get the user's time
    printf("Enter a 24 hour time (hh:mm): \n");
    scanf("%d:%d", &hours, &minutes);
    
    time = hours * 60 + minutes;
    
    // Find the closest departure time
    int min_diff = __INT_MAX__;
    for (i = 0; i < sizeof(departures) / sizeof(departures[0]); i++) {
        if (abs(time - departures[i]) < min_diff) {
            min_diff = abs(time - departures[i]);
            closest_dep_index = i;
        }
    }
    
    // Print the closest departure and arrival times
    printf("Closest departure time is %d:%.2d ", departures[closest_dep_index] / 60, departures[closest_dep_index] % 60);
    print_time(departures[closest_dep_index]);
    printf(", arriving at %d:%.2d ", arrivals[closest_dep_index] / 60, arrivals[closest_dep_index] % 60);
    print_time(arrivals[closest_dep_index]);

    return 0;
}

void print_time(int minutes_since_midnight) {
    if (minutes_since_midnight / 60 < 12)
        printf("am");
    else
        printf("pm");
}
