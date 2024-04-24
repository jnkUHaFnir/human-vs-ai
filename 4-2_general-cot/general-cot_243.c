while(1){
    if((n = read(newsocketfd, buffer, sizeof(buffer))) > 0){
        printf("(Message length %d) Message from Client: %s\n", n, buffer);

        if(strcmp("q", buffer) == 0){
            printf("Client wants to close the connection: %s\n", buffer);
            break; // Exit the loop if the client sends "q"
        }
        else{
            printf("Data received from the client: %s\n", buffer);
        }

        if(write(newsocketfd, response, 255) > 0)
            printf("Writing response to Client socket \n");
        else
            error("Error writing message \n");
    }
    else{
        close(socketfd);
        close(newsocketfd);
        error("Error reading message \n");
    }
}
