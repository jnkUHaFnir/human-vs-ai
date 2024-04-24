void sort(struct books *pointer,int n)
{
    int i,j,sorted=0;
    struct books temp;
    for(i=0;(i<n-1)&&(sorted==0);i++)       //bubble sort on the book name
    {
        sorted=1;
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp((pointer+j)->name,(pointer+j+1)->name)>0)
            {
                //copy to temp val
                strcpy(temp.name,(pointer+j)->name);
                strcpy(temp.author,(pointer+j)->author);
                temp.year=(pointer+j)->year;
                temp.copies=(pointer+j)->copies;

                //copy next val
                strcpy((pointer+j)->name,(pointer+j+1)->name);
                strcpy((pointer+j)->author,(pointer+j+1)->author);
                (pointer+j)->year=(pointer+j+1)->year;
                (pointer+j)->copies=(pointer+j+1)->copies;

                //copy back temp val
                strcpy((pointer+j+1)->name,temp.name);
                strcpy((pointer+j+1)->author,temp.author);
                (pointer+j+1)->year=temp.year;
                (pointer+j+1)->copies=temp.copies;

                sorted=0;
            }
        }
    }
}
for(i=0;i<SIZE;i++)             //scanning values
{
    fgets(book1[i].name, 100, stdin);
    fgets(book1[i].author, 100, stdin);
    scanf("%d%d",&book1[i].year,&book1[i].copies);
    while((c = getchar()) != '\n' && c != EOF);
}
