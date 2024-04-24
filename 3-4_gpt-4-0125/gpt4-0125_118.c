#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 19 // Assuming player numbers 0 through 18

// Improved structure definition
struct profile {
    char firstName[30];
    char lastName[30];
    int atBats;
    int hits;
    int walks;
    int rbis;
    float batAvg; // To be calculated after reading the file
};

int main(void) {
    FILE *file;
    struct profile players[MAX_PLAYERS] = {0}; // Initialize all to 0
    int playerNum, atBats, hits, walks, rbis;
    char firstName[30], lastName[30];
    int totalAtBats = 0, totalHits = 0, totalWalks = 0, totalRbis = 0; // For team stats
    
    file = fopen("team.txt", "r");
    if(file == NULL) {
        fprintf(stderr, "Can't open file!\n");
        return 1;
    }
    
    // Read file data into temporary variables
    while(fscanf(file, "%d %s %s %d %d %d %d", &playerNum, firstName, lastName, &atBats, &hits, &walks, &rbis) == 7) {
        if(playerNum >= 0 && playerNum < MAX_PLAYERS) {
            // Update player stats
            strcpy(players[playerNum].firstName, firstName);
            strcpy(players[playerNum].lastName, lastName);
            players[playerNum].atBats += atBats;
            players[playerNum].hits += hits;
            players[playerNum].walks += walks;
            players[playerNum].rbis += rbis;
            
            // Update team stats
            totalAtBats += atBats;
            totalHits += hits;
            totalWalks += walks;
            totalRbis += rbis;
        }
    }
    fclose(file);
    
    // Calculate batting averages and display player stats
    for(int i = 0; i < MAX_PLAYERS; i++) {
        if(players[i].atBats > 0) {
            players[i].batAvg = (float)players[i].hits / players[i].atBats;
            printf("Player #%d: %s %s, BA: %.3f\n", i, players[i].firstName, players[i].lastName, players[i].batAvg);
        }
    }
    
    // Calculate and display team stats
    float teamBatAvg = (totalAtBats > 0) ? (float)totalHits / totalAtBats : 0.0;
    printf("\nTeam Stats: Total At-Bats: %d, Total Hits: %d, Total Walks: %d, Total RBIs: %d, Team BA: %.3f\n", totalAtBats, totalHits, totalWalks, totalRbis, teamBatAvg);
    
    return 0;
}
