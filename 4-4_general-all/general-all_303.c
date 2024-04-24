#include <stdio.h>

int main() {
    int hours, minutes, time, closest_departure_time, closest_arrival_time;

    // Flight departure times in minutes since midnight
    int departure_times[] = {480, 585, 679, 767, 840, 945, 1140, 1185};
    // Corresponding arrival times in minutes since midnight
    int arrival_times[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    printf("Enter a 24 hour time (hh:mm): ");
    scanf("%d:%d", &hours, &minutes);

    time = hours * 60 + minutes;

    printf("Closest departure time is ");

    // Find the closest departure time
    int min_difference = abs(time - departure_times[0]);
    int index_of_closest = 0;
    for (int i = 1; i < sizeof(departure_times) / sizeof(departure_times[0]); i++) {
        int difference = abs(time - departure_times[i]);
        if (difference < min_difference) {
            min_difference = difference;
            index_of_closest = i;
        }
    }

    closest_departure_time = departure_times[index_of_closest];
    closest_arrival_time = arrival_times[index_of_closest];

    // Display the closest departure and arrival times
    printf("%.2d:%.2d ", closest_departure_time / 60, closest_departure_time % 60);
    printf((closest_departure_time < 720) ? "am" : "pm");
    printf(", arriving at %.2d:%.2d ", closest_arrival_time / 60, closest_arrival_time % 60);
    printf((closest_arrival_time < 720) ? "am\n" : "pm\n");

    return 0;
}
