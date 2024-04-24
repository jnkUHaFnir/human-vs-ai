    if ((n = read(newsocketfd, buffer, sizeof(buffer))) > 0) {
    	buffer[n] = '\0'; /* read() doesn't add a trailing 0 */
    	printf("(Mlength %d) message from Client:  %s\n",n,buffer);
    } else {
    	...
----------
    if (strcmp("q", &buffer[n]) == 0) /* you are reading NUL ('\0') */