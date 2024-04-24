#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 19
#define MAX_NAME_LENGTH 30

struct player {
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    int at_bats;
    int hits;
    int walks;
    int rbis;
    float batting_avg;
};

int main(void) {
    FILE *file;
    struct player players[MAX_PLAYERS] = {0};

    if ((file = fopen("team.txt", "r")) == NULL) {
        fprintf(stderr, "Can't read file team.txt!\n");
        exit(1);
    }

    int player_number, at_bats, hits, walks, rbis;
    while (fscanf(file, "%d %s %s %d %d %d %d", &player_number, players[player_number].first_name, players[player_number].last_name, &at_bats, &hits, &walks, &rbis) == 7) {
        players[player_number].at_bats += at_bats;
        players[player_number].hits += hits;
        players[player_number].walks += walks;
        players[player_number].rbis += rbis;
    }

    // Calculate batting average for each player
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].at_bats > 0) {
            players[i].batting_avg = (float) players[i].hits / players[i].at_bats;
        }
    }

    // Display cumulative data for each player
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].at_bats > 0) {
            printf("Player %d - %s %s\n", i, players[i].first_name, players[i].last_name);
            printf("At bats: %d\n", players[i].at_bats);
            printf("Hits: %d\n", players[i].hits);
            printf("Walks: %d\n", players[i].walks);
            printf("RBIs: %d\n", players[i].rbis);
            printf("Batting average: %.3f\n\n", players[i].batting_avg);
        }
    }

    // Display combined statistics for the entire team
    int total_at_bats = 0, total_hits = 0, total_walks = 0, total_run_batted_ins = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        total_at_bats += players[i].at_bats;
        total_hits += players[i].hits;
        total_walks += players[i].walks;
        total_run_batted_ins += players[i].rbis;
    }

    printf("Team Totals:\n");
    printf("Total At bats: %d\n", total_at_bats);
    printf("Total Hits: %d\n", total_hits);
    printf("Total Walks: %d\n", total_walks);
    printf("Total RBIs: %d\n", total_run_batted_ins);

    fclose(file);
    return 0;
}
