double teamscore[32][2];
fscanf(filein_ptr, "%[^,],%lf\n", teamname, &teamscore[n][0]);
fprintf(fileout_ptr, "%s    %f\n", teamname, teamscore[n][0]);
for (n = 0; n < 32; n++)
