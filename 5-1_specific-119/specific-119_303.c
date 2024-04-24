#include <stdio.h>

int main() {
    int departure_times[] = {480, 585, 679, 767, 840, 945, 1140, 1185};
    int arrival_times[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    int hours, minutes;
    int input_time, closest_departure_time, closest_arrival_time;
    int min_difference = 1440; // 24 hours in minutes

    // Get the user's time
    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hours, &minutes);

    input_time = hours * 60 + minutes;

    // Find the closest departure time
    for (int i = 0; i < sizeof(departure_times) / sizeof(departure_times[0]); i++) {
        int difference = input_time - departure_times[i];
        if (difference < 0) {
            difference *= -1;
        }
        if (difference < min_difference) {
            min_difference = difference;
            closest_departure_time = departure_times[i];
            closest_arrival_time = arrival_times[i];
        }
    }

    // Display the closest departure and arrival times
    printf("Closest departure time is %02d:%02d, arriving at %02d:%02d\n", closest_departure_time / 60, closest_departure_time % 60, closest_arrival_time / 60, closest_arrival_time % 60);

    return 0;
}
