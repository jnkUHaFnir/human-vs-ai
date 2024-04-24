#include <stdio.h>

int main() {
    int input_hours, input_minutes, total_input_minutes;
    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &input_hours, &input_minutes);

    total_input_minutes = input_hours * 60 + input_minutes;

    int flight_times[] = {480, 585, 679, 767, 840, 945, 1140, 1185};
    int flight_arrival_times[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    int closest_departure = 0;
    int min_difference = abs(total_input_minutes - flight_times[0]);

    for (int i = 1; i < 8; i++) {
        int time_diff = abs(total_input_minutes - flight_times[i]);
        if (time_diff < min_difference) {
            min_difference = time_diff;
            closest_departure = i;
        }
    }

    if (flight_times[closest_departure] / 60 < 12) {
        printf("Closest departure time is %d:%.2d am, arriving at %d:%.2d %s\n",
               flight_times[closest_departure] / 60, flight_times[closest_departure] % 60,
               flight_arrival_times[closest_departure] / 60, flight_arrival_times[closest_departure] % 60,
               flight_arrival_times[closest_departure] / 60 < 12 ? "am" : "pm");
    } else {
        printf("Closest departure time is %d:%.2d pm, arriving at %d:%.2d %s\n",
               flight_times[closest_departure] / 60, flight_times[closest_departure] % 60,
               flight_arrival_times[closest_departure] / 60, flight_arrival_times[closest_departure] % 60,
               flight_arrival_times[closest_departure] / 60 < 12 ? "am" : "pm");
    }

    return 0;
}
