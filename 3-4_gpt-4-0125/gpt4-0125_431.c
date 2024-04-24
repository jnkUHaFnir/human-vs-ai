scanf("%d %[^\n]%*c %d %d %d", &s[i].r, s[i].a, &s[i].c1, &s[i].c2, &s[i].c3);
while ((getchar()) != '\n');
for (i = 0; i < n; i++) {
    printf("Enter details of student\nRollNo Name c1 c2 c3 marks\n");
    scanf("%d %[^\n]%*c %d %d %d", &s[i].r, s[i].a, &s[i].c1, &s[i].c2, &s[i].c3);
}
