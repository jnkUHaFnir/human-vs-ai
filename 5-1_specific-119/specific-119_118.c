#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LGT 30

struct profile {
     int pl_num;
     char name[LGT];
     char lname[LGT];
     int atbat;
     int hits;
     int walks;
     int runs;
     float batavg;
};

int main(void) {
    FILE *flx;
    struct profile stat[19] = {0};

    if ((flx = fopen("team.txt", "r")) == NULL) {
        fprintf(stderr, "Can't read file team!\n");
        exit(1);      
    }

    char line[100];
    while (fgets(line, sizeof(line), flx)) {
        int pl_num, atbat, hits, walks, runs;
        char name[LGT], lname[LGT];

        sscanf(line, "%d %s %s %d %d %d %d", &pl_num, name, lname, &atbat, &hits, &walks, &runs);

        // Update player stats
        stat[pl_num].pl_num = pl_num;
        strcpy(stat[pl_num].name, name);
        strcpy(stat[pl_num].lname, lname);
        stat[pl_num].atbat += atbat;
        stat[pl_num].hits += hits;
        stat[pl_num].walks += walks;
        stat[pl_num].runs += runs;
    }

    // Calculate batting average
    for (int i = 0; i < 19; i++) {
        if (stat[i].atbat > 0) {
            stat[i].batavg = (float)stat[i].hits / stat[i].atbat;
        }
    }

    // Display player stats
    for (int i = 0; i < 19; i++) {
        if (stat[i].atbat > 0) {
            printf("Player %d: %s %s - AVG: %.3f\n", stat[i].pl_num, stat[i].name, stat[i].lname, stat[i].batavg);
        }
    }

    fclose(flx);
    return 0;
}
