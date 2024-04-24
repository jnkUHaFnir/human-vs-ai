typedef struct {
    char name[50]; // Adjust size as needed.
} Person;
Person person1;
printf("Enter name: ");
fgets(person1.name, sizeof(person1.name), stdin); // fgets is safer than scanf for strings

// Remove trailing newline character, if any
person1.name[strcspn(person1.name, "\n")] = 0;
if(strcmp(person1.name, "Steve xyz") == 0) {
    printf("Valid name\n");
} else {
    printf("Invalid name\n");
}
