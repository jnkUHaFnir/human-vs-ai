Just like that, you should also change in client code.

Your client code should be:

```C
do{
    printf("Please, type your message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    n = write(socketfd,buffer,strlen(buffer));
    if(n < 0 )
        error("Error writing to socket \n");
    else
        printf("...Message sent \n");

    n = read(socketfd,buffer,sizeof(buffer));
    if(n < 0 )
            error("Error writing to socket \n");
        else
            printf("\n Message from server: %s \n",buffer);

}while(strcmp("q\n",buffer)!=0);   // Change here too, fget append \n at the end.
