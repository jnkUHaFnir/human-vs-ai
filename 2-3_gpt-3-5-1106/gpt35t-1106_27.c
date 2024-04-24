// inside the while loop
char* temp = realloc(string, strlen(string) + 1);
if(temp == NULL){
    return false;
}
string = temp;
