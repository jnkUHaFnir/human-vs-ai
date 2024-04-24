    #define MAX_STRING_LENGTH 1000
    char *strcat_const(const char *str1,const char *str2){
        char buffer[MAX_STRING_LENGTH];
        strncpy(buffer,str1,MAX_STRING_LENGTH);
        strncat(buffer,str2,MAX_STRING_LENGTH - strlen(buffer));
        return buffer;
    }
    
    int main(int argc,char *argv[]){
        printf("%s",strcat_const("Hello ","world"));    //Prints "Hello world"
        return 0;
    }