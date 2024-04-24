    char *strcat_const(const char *str1,const char *str2){
        char *buffer = malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
        strcpy(buffer,str1);
        int i;
        for(i = 0; i < strlen(str2) + 1; i++){
            buffer[strlen(str1) + i] = str2[i];
        }
        return buffer;
        free(buffer);
    }
    
    int main(int argc,char *argv[]){
        printf("%s",strcat_const("Hello ","world"));    //Prints "Hello world"
        return 0;
    }