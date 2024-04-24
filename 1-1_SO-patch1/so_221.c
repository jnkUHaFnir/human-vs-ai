c
#include <stdio.h>
#include <stdlib.h>
void getString(char ** string);
int main(void){
	char * str = NULL;
	printf("Write something:\n");
	getString(&str);
	printf("You wrote:\n");
	printf("%s\n", str);
	free(str);
	return 0;
}
void getString(char ** string){
	char ch, *newstr;
	int length = 0;
	if (string == NULL) {
		printf("ERROR: invalid parameter!!\n");
		return;
	}
	*string = NULL;
	do{
		scanf("%c", &ch);
		newstr = (char *) realloc(*string, (length + 1) * sizeof(char));
		if (newstr == NULL){
			printf("ERROR: memory could not be allocated!!\n");
			free(*string);
			*string = NULL;
			return;
		}
		*string = newstr;
		newstr[length] = ch;
		length++;
	}
	while (ch != '\n');
	(*string)[length] = '\0';
}