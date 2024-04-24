char x[50];
while(scanf("%49[^:\n]%1[:\n]", x, x)==2)
{
    printf("Read: %s\n", x);
}
