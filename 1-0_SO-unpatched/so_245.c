    if (scount == 0)
    {
        s = (students*)malloc(sizeof(students));
    }
    else
    {
        students *temp = realloc(s, sizeof(students) * scount);
        if(temp == NULL){
            free(s);
        }
        else{
            s = temp;
        }
    }