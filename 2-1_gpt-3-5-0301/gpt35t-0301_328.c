printf("searching \n\n\"%s\"\n for %.*s\n", s1, length, s2);
printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
printf("found: %s\n", strnstr(in, searchingFor, 8) ? "yes" : "no");
printf("found: %s\n", strnstr(in, searchingFor, 10) ? "yes" : "no");
