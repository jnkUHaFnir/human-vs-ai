if(strcmp("q\n", buffer) == 0)
    printf("El cliente intenta cerrar la conexión %s\n", buffer);
else
    printf("Se recibieron datos desde el cliente %s\n", buffer);
do{
    printf("Please, type your message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    n = write(socketfd,buffer,strlen(buffer)); // sizeof(buffer) can be replaced with strlen(buffer)
    if(n < 0 )
        error("Error writing to socket \n");
    else
        printf("...Message sent \n");

    n = read(socketfd,buffer,sizeof(buffer));
    if(n < 0 )
            error("Error writing to socket \n");
    else
        printf("\n Message from server: %s \n",buffer);

}while(strcmp("q\n",buffer)!=0);
