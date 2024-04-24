void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Consume all chars until newline or EOF
}

// Usage example:
printf("Put equipo: ");
clear_input_buffer(); 
fgets(equipo, 50, stdin);
strtok(equipo, "\n");

if (Exists(equipo)) {
    printf("Put Piloto ");
    clear_input_buffer();
    fgets(piloto, 50, stdin);
    strtok(piloto, "\n");
    printf("You said %s and %s", equipo, piloto);
}
