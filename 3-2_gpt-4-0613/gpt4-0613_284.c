if (strlen(argv[1]) == counter)
{
    string s = get_string("plaintext: ");
    if(s)
    {
        printf("ciphertext: ");
        int key = atoi(argv[1]); // Converts argv[1] to integer
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                printf("%c", 'A' + (s[i] - 'A' + key) % 26 );
            } else {
                printf("%c", s[i]);
            }
        }
        printf("\n");
        free(s);
    }
}
