// all to lower except the first letter
for(i = 1; i < strlen(name); i++){
   name[i] = tolower(name[i]);
}
// first letter to upper
name[0] = toupper(name[0]);
int x = 1;
while(name[x] != '\0'){
   // if the letter before is a white space, even the first letter, it should make the first letter of a name uppercase
   if(name[x-1] == ' ')
      name[x] = toupper(name[x]);
   x++;
}
