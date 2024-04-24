// convert to lowercase
for(i = 0; name[i] != '\0'; i++){
   name[i] = tolower(name[i]);
}

// capitalize first letter
name[0] = toupper(name[0]);

// capitalize first letter of each word
for(i = 1; name[i] != '\0'; i++){
   if(name[i-1] == ' '){
      name[i] = toupper(name[i]);
   }
}
