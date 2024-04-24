    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    
    #define FILEIN "data.csv"
    #define FILEOUT "matrix.csv"
    #define MAXS 32
    
    int main (int argc, char **argv)
    {
        /* double nfl[MAXS][MAXS] = {{0}}; */
        double teamscore[MAXS] = {0};
        char teamname[30] = {0};
        int n = 0;
        FILE *filein_ptr = argc > 1 ? fopen (argv[1], "r") : fopen (FILEIN, "r");
        FILE *fileout_ptr = argc > 2 ? fopen (argv[2], "w") : fopen (FILEOUT, "w");
    
        if (!filein_ptr || ! fileout_ptr) {
            fprintf (stderr, "error: filein of fileout open failed.\n");
            return 1;
        }
    
        while (fscanf (filein_ptr, " %29[^,],%lf", teamname, &teamscore[n]) == 2) {
            fprintf (fileout_ptr, "%s    %f\n", teamname, teamscore[n++]);
            if (n == MAXS) {  /* check data doesn't exceed MAXS */
                fprintf (stderr, "warning: data exceeds MAXS.\n");
                break;
            }
        }
    
        fclose (filein_ptr);
        fclose (fileout_ptr);
    
        return 0;
    }