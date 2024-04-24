#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    // Assuming you want to input string parts of an IP address
    string name = get_string("Part 1 of the IP: ");
    string test = get_string("Part 2 of the IP: ");
    string er = get_string("Part 3 of the IP: ");
    string tr = get_string("Part 4 of the IP: ");

    // Display the constructed IP just for verification
    printf("%s.%s.%s.%s\n", name, test, er, tr);

    char command[256];
    sprintf(command, "ping %s.%s.%s.%s", name, test, er, tr);
    system(command);

    return 0; 
}
