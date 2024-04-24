#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 19
#define MAX_NAME_LENGTH 30

struct profile {
    int pl_num;
    char name[MAX_NAME_LENGTH];
    char lname[MAX_NAME_LENGTH];
    int atbat_total;
    int hits_total;
    int walks_total;
    int runs_total;
    float batavg;
};

int main(void) {
    FILE *file;
    struct profile players[MAX_PLAYERS] = {0};

    file = fopen("team.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Can't read file team.txt!\n");
        exit(1);
    }

    int player_num, atbat, hits, walks, runs;
    while (fscanf(file, "%d %s %s %d %d %d %d", &player_num, players[player_num].name, players[player_num].lname, &atbat, &hits, &walks, &runs) == 7) {
        players[player_num].pl_num = player_num;
        players[player_num].atbat_total += atbat;
        players[player_num].hits_total += hits;
        players[player_num].walks_total += walks;
        players[player_num].runs_total += runs;
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].pl_num != 0 && players[i].atbat_total != 0) {
            players[i].batavg = (float)players[i].hits_total / players[i].atbat_total;
        }

        if (players[i].pl_num != 0) {
            printf("Player %d: %s %s\n", players[i].pl_num, players[i].name, players[i].lname);
            printf("Total at bats: %d\n", players[i].atbat_total);
            printf("Total hits: %d\n", players[i].hits_total);
            printf("Total walks: %d\n", players[i].walks_total);
            printf("Total runs: %d\n", players[i].runs_total);
            printf("Batting average: %.3f\n\n", players[i].batavg);
        }
    }

    // Team statistics
    int total_atbats = 0, total_hits = 0, total_walks = 0, total_runs = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        total_atbats += players[i].atbat_total;
        total_hits += players[i].hits_total;
        total_walks += players[i].walks_total;
        total_runs += players[i].runs_total;
    }

    printf("Team Total:\n");
    printf("Total at bats: %d\n", total_atbats);
    printf("Total hits: %d\n", total_hits);
    printf("Total walks: %d\n", total_walks);
    printf("Total runs: %d\n", total_runs);

    fclose(file);

    return 0;
}
