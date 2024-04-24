int my_strcmp(char s1[], char s2[])
{
    int i = 0;
    // Continue loop as long as neither string has reached its end
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        // If s1[i] is less than s2[i], return -1 indicating s1 comes before s2
        if (s1[i] < s2[i]) { return -1; }
        // If s1[i] is more than s2[i], return 1 indicating s1 comes after s2
        else if (s1[i] > s2[i]) { return 1; }
        // Move to the next character if s1[i] equal to s2[i]
        i++;
    }
    // After exiting the loop, check why we exited:
    // If both strings ended simultaneously, then they are equal.
    if (s1[i] == '\0' && s2[i] == '\0')
    {
        return 0;
    }
    // If we exited the loop because s1 ended, s1 is less than s2
    else if (s1[i] == '\0')
    {
        return -1;
    }
    // If we exited the loop because s2 ended, s1 is greater than s2
    else // (s2[i] == '\0')
    {
        return 1;
    }
}
