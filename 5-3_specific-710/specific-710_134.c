#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for system("cls")

int validate(int low, int high);

int main ()
{
    // Declare Variables
    float strength, speed, defense, intelligence;
    float strengthRatio, speedRatio, defenseRatio, intelligenceRatio;
    int strength_F, speed_F, defense_F, intelligence_F;
    float sum;
    int luck;
    float PStrength=10;
    float PDefense=20;
    float PIntelligence=40;
    int PHP=10;
    float EStrength=30;
    float EDefense=40;
    float EIntelligence=25;
    int EHP=10;
    int sel;
    float attackp;
    float magicp;
    
    // Clear Screen
    system("cls");

    printf("+----------------------+\n");
    printf("|                      |\n");
    printf("|     CODE QUEST       |\n");
    printf("|                      |\n");
    printf("+----------------------+\n\n");

    printf("--Main Menu--\n");
    printf("\n");
    printf("1 - New Game\n");
    printf("2 - Load Game\n");
    printf("3 - Exit\n");
    printf("\n");
    printf("Selection: ");

    // Validate user input using a function
    sel = validate(1, 3);

    printf("Character Creation \n");
    printf("Please enter your desired stats for your character:\n\n");

    printf("Enter strength: ");
    scanf("%f", &strength);
    printf("Enter speed: ");
    scanf("%f", &speed);
    printf("Enter defense: ");
    scanf("%f", &defense);
    printf("Enter intelligence: ");
    scanf("%f", &intelligence);

    // Calculate the sum of all attributes and ratios
    sum = strength + speed + defense + intelligence;
    strengthRatio = strength / sum;
    speedRatio = speed / sum;
    defenseRatio = defense / sum;
    intelligenceRatio = intelligence / sum;

    // Calculate the final stats as whole numbers
    strength_F = strengthRatio * 100;
    speed_F = speedRatio * 100;
    defense_F = defenseRatio * 100;
    intelligence_F = intelligenceRatio * 100;

    // Calculate the player's luck
    luck = (int)sum % 30;

    printf("\nYour player's final stats are:\n");
    printf("Strength: %d\n", strength_F);
    printf("Speed: %d\n", speed_F);
    printf("Defense: %d\n", defense_F);
    printf("Intelligence: %d\n", intelligence_F);
    printf("Luck: %d\n\n");

    // Rest of your code for the battle logic

    return 0;
}

int validate(int low, int high)
{
    int s;

    do {
        printf("Selection: ");
        scanf("%d", &s);

        if (s < low || s > high) {
            printf("Invalid Input, try again\n");
        }
    } while (s < low || s > high);

    return s;
}
