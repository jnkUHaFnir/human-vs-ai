fgets(name, sizeof(name), stdin);
do{
    fgets(name, sizeof(name), stdin);
    for(i = 0; i < strlen(name); i++){
        if(!isalpha(name[i]) && name[i] != ' ' && name[i] != '\n'){
            printf("Invalid character. Please enter a valid name.\n");
            break;
        }
    }
    if(i == strlen(name) - 1){ // If no invalid characters found
        break;
    }
}while(1);
int capitalize = 1; // Start with capitalizing the first letter
for(i = 0; i < strlen(name); i++){
    if(isalpha(name[i])){
        if(capitalize){
            name[i] = toupper(name[i]);
            capitalize = 0; // Next characters should be lowercase
        } else {
            name[i] = tolower(name[i]);
        }
    }
    else if(name[i] == ' ') {
        capitalize = 1; // Next character should be capitalized
    }
}
