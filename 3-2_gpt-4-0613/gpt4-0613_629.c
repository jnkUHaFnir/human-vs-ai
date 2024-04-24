if(strlen(name) > 0)
    name[0] = toupper(name[0]);

x=1;
while(name[x] != '\0'){
   // if the letter before is a whitespace it should place the first letter of a name as uppercase
   if(name[x-1] == ' ' && name[x] != '\0')
      name[x] = toupper(name[x]);
   x++;
}
