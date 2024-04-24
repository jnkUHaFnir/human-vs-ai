    #define MAX_STRING_LENGTH 1000
    char *strcat_const(const char *str1,const char *str2){
        char buffer[MAX_STRING_LENGTH];
        strcpy(buffer,str1);
        int i;
        for(i = 0; i < strlen(str2) + 1 || i < MAX_STRING_LENGTH; i++){
            buffer[strlen(str1) + i] = str2[i];
        }
        buffer[MAX_STRING_LENGTH] = '\0';
        char tempString[1];
        strncpy(tempString,buffer,1);
        return buffer;
    }
    
    int main(int argc,char *argv[]){
        printf("%s",strcat_const("Hello ","world"));    //Prints "Hello world"
        return 0;
    }