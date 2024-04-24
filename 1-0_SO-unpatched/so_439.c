c
char *c = malloc(42);
scanf("%s", &c);
As you can see, we are giving `scanf` a `char **` not a `char *`.
As others have noted, the `email` variable should probably be an array as well, and the call to `scanf` should not take the address of email at that point either.
Additionally, it is best to explicitly initialize your variables and bound your input. For the former, if you are compiling without optimizations then the compiler is probably zeroing out your memory already, but when you get into production code uninitialized variables are dangerous. Similarly, since the input is being placed into statically allocated arrays scanf should be told to limit the number of characters it copies.
c
#include <stdio.h>
#include <string.h>
int main()
{
	char email[64] = { 0 };
	char temppass[64] = { 0 };
	char pass[] = "password";
	printf("Enter your email: \n");
	if (scanf("%63s", email) == EOF) {
		printf("Error parsing input!\n");
		perror("scanf");
	}
	printf("Enter your password: \n");
	if (scanf("%63s" , temppass) == EOF) {
		printf("Error parsing input!\n");
		perror("scanf");
	}
	if(strcmp(temppass, pass) == 0) {
		printf("This is the password");
	}
	else {
		printf("You Failed!");
	}
	return 0;
}