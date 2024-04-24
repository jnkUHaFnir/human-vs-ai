while(1){
    if((n = read(newsocketfd,buffer,sizeof(buffer))) > 0) {
        buffer[n-1] = '\0'; // remove newline character
        printf("(Mlength %d) message from Client: %s\n",n,buffer);
    } else {
        close(socketfd);
        close(newsocketfd);
        error("Error reading message \n");
    }

    if(strcmp("q", buffer) == 0)
        printf("El cliente intenta cerrar la conexión %s\n", buffer);
    else
        printf("Se recibieron datos desde el cliente %s\n", buffer);

    if(write(newsocketfd, response, 255) > 0)
        printf("Writing response to Client socket \n");
    else
        error("Error writing message \n");
}

return EXIT_SUCCESS;
}
