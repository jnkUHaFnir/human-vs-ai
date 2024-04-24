if(strcmp("q", buffer) == 0)
    printf("El cliente intenta cerrar la conexión %s\n", buffer);
else
    printf("Se recibieron datos desde el cliente %s\n", buffer);
