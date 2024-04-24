#include <stdio.h>

int main() {
    // Flight departure times since midnight
    int departures[] = {480, 585, 679, 767, 840, 945, 1140, 1185};
    // Flight arrival times for respective departure times
    int arrivals[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    int hours, minutes, time;
    int closest_departure = 0;
    int closest_arrival = 0;
    int min_difference = 1440; // 24 hours in minutes

    // Get the user's time
    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hours, &minutes);

    time = hours * 60 + minutes;

    printf("Closest departure time is ");

    // Find closest departure time
    for (int i = 0; i < sizeof(departures) / sizeof(departures[0]); i++) {
        int difference = time - departures[i];
        if (difference < 0) {
            difference = -difference;
        }

        if (difference < min_difference) {
            min_difference = difference;
            closest_departure = departures[i];
            closest_arrival = arrivals[i];
        }
    }

    // Print the closest departure time
    printf("%.2d:%.2d ", closest_departure / 60, closest_departure % 60);
    if (closest_departure / 60 < 12) {
        printf("am");
    } else {
        printf("pm");
    }

    printf(", arriving at %.2d:%.2d ", closest_arrival / 60, closest_arrival % 60);
    if (closest_arrival / 60 < 12) {
        printf("am");
    } else {
        printf("pm");
    }

    return 0;
}
