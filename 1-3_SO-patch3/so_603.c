    x=1;
    while(name[x] != '\0'){
       //if the letter before is a white space, even the first letter, it should place the first letter of a name upper
       if(name[x-1] == ' ')
          name[x] = toupper(name[x]);
       x++;
    }