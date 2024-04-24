#include <stdio.h>
#include <stdlib.h> // Include stdlib for system function

int validate(int low, int high);

int main() {
    // Declare Variables
    float strength, speed, defense, intelligence;
    float strengthRatio, speedRatio, defenseRatio, intelligenceRatio;
    int strength_F, speed_F, defense_F, intelligence_F;
    float sum;
    int luck;
    float PStrength = 10;
    float PDefense = 20;
    float PIntelligence = 40;
    int PHP = 10;
    float EStrength = 30;
    float EDefense = 40;
    float EIntelligence = 25;
    int EHP = 10;
    int sel;
    float attackp;
    float magicp;
    int Valid_Selection;

    // Clear Screen
    system("cls");

    // Display Logo
    printf("+----------------------+\n");
    printf("|                      |\n");
    printf("|     CODE QUEST       |\n");
    printf("|                      |\n");
    printf("+----------------------+\n\n");

    // Main Menu
    printf("--Main Menu--\n\n");
    printf("1 - New Game\n");
    printf("2 - Load Game\n");
    printf("3 - Exit\n\n");

    // Validate user input using the validate function
    Valid_Selection = validate(1, 3);

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

    // Calculate the sum of all attributes
    sum = strength + speed + defense + intelligence;

    // Calculate ratios for each attribute
    strengthRatio = strength / sum;
    speedRatio = speed / sum;
    defenseRatio = defense / sum;
    intelligenceRatio = intelligence / sum;

    // Calculate the final Stats as whole number
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
    printf("Luck: %d\n\n", luck);

    printf("Battle Start!\n\n");

    while (PHP > 0 && EHP > 0) {
        printf("Your HP: %d, Enemy HP: %d\n", PHP, EHP);
        printf("1 - Attack Power\n");
        printf("2 - Magic Power\n");
        scanf("%d", &sel);

        if (sel == 1) {
            attackp = (PStrength / EDefense) * 5;
            EHP -= attackp;
            printf("You attacked the enemy\n");
        } else {
            magicp = (PIntelligence / EIntelligence) * 5;
            EHP -= magicp;
            printf("You bewitched the enemy!\n");
        }

        if (EHP <= 0)
            printf("You won!\n");
        else {
            attackp = (EStrength / PDefense) * 5;
            PHP -= attackp;
            printf("The enemy attacked you\n");
        }

        if (PHP <= 0)
            printf("You lost!\n");

        printf("\n");
    }

    return 0;
}

int validate(int low, int high) {
    int s;

    do {
        scanf("%d", &s);
        if (s < low || s > high) {
            printf("Invalid Input, try again: ");
        }
    } while (s < low || s > high);

    return s;
}
