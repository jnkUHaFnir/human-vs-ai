char s1[2], s2[2];
int i1, i2, expon;
int f1, f2;
int count = fscanf(file, "%c%d.%dE%c%d;%c%d.%dE%c%d", &s1[0], &i1, &f1, &s2[0], &expon, &s1[1], &i2, &f2, &s2[1], &expon);
s1[1] = s2[1] = '\0';
