#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 19
#define MAX_NAME_LENGTH 20
#define MAX_GAMES 100

struct profile {
    int pl_num;
    char name[MAX_NAME_LENGTH];
    char lname[MAX_NAME_LENGTH];
    int atbat[MAX_GAMES];
    int hits[MAX_GAMES];
    int walks[MAX_GAMES];
    int runs[MAX_GAMES];
    float batavg;
};

int main(void)
{
    FILE *flx;
    struct profile stat[MAX_PLAYERS] = {{0}};
    int pl_num, atbat, hits, walks, runs, game_count = 0;

    if ((flx = fopen("team.txt", "r")) == NULL) {
        fprintf(stderr, "Can't read file team.txt!\n");
        exit(1);
    }

    while (fscanf(flx, "%d %s %s %d %d %d %d", &pl_num, stat[pl_num].name, stat[pl_num].lname, &atbat, &hits, &walks, &runs) == 7) {
        // Assign current game stats to corresponding player
        stat[pl_num].pl_num = pl_num;
        stat[pl_num].atbat[game_count] = atbat;
        stat[pl_num].hits[game_count] = hits;
        stat[pl_num].walks[game_count] = walks;
        stat[pl_num].runs[game_count] = runs;

        // Increment game count for the player
        game_count++;
        
        // Calculate batting average for the current game and update cumulative stats
        for (int i = 0; i < game_count; i++) {
            float bat_avg;
            if (stat[pl_num].atbat[i] != 0) {
                bat_avg = (float)stat[pl_num].hits[i] / stat[pl_num].atbat[i];
            } else {
                bat_avg = 0.0;
            }
            stat[pl_num].batavg = (stat[pl_num].batavg * i + bat_avg) / (i + 1);
        }
    }

    // Display the cumulative data for each player
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (stat[i].pl_num != 0) {
            printf("Player: %d %s %s\n", stat[i].pl_num, stat[i].name, stat[i].lname);
            printf("Cumulative Batting Average: %.3f\n", stat[i].batavg);
            // You can add more details here such as total hits, walks, etc.
            printf("\n");
        }
    }

    // Display the combined statistics for the entire team
    // Here you can calculate totals for the entire team if needed

    fclose(flx);
    return 0;
}
