int my_strcmp(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] == '\0' && s2[i] != '\0') { 
            return -1; // s1 is shorter than s2
        }
        else if (s1[i] != '\0' && s2[i] == '\0') { 
            return 1; // s2 is shorter than s1
        }
        else if (s1[i] < s2[i]) { 
            return -1; // s1 is less than s2
        }
        else if (s1[i] > s2[i]) { 
            return 1; // s1 is greater than s2
        }
        i++;
    }   
    return 0; // both strings are equal
}
