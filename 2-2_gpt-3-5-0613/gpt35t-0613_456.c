if(buffer[0] == 'q')
    printf("El cliente intenta cerrar la conexión %s\n", buffer);
else
    printf("Se recibieron datos desde el cliente %s\n", buffer);
fgets(buffer, 255, stdin);
buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character
