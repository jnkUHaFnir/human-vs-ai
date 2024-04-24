#include <stdio.h>

int main() {
    int departure_times[] = {480, 585, 679, 767, 840, 945, 1140, 1185};
    int arrival_times[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    int hours, minutes, user_time, closest_departure_time, closest_arrival_time, min_diff = 1440; // 1440 min = 24 hours

    printf("Enter a 24 hour time (hh:mm): \n");
    scanf("%d:%d", &hours, &minutes);

    user_time = hours * 60 + minutes;

    for (int i = 0; i < 8; i++) {
        int time_diff = user_time - departure_times[i];
        if (time_diff < 0) {
            time_diff = -time_diff; // make it positive
        }
        if (time_diff < min_diff) {
            min_diff = time_diff;
            closest_departure_time = departure_times[i];
            closest_arrival_time = arrival_times[i];
        }
    }

    printf("Closest departure time is %d:%.2d ", closest_departure_time / 60, closest_departure_time % 60);
    if (closest_departure_time / 60 < 12) {
        printf("am");
    } else {
        printf("pm");
    }
    printf(", arriving at %d:%.2d", closest_arrival_time / 60, closest_arrival_time % 60);
    if (closest_arrival_time / 60 < 12) {
        printf("am");
    } else {
        printf("pm");
    }

    return 0;
}
