    int main ()
    {
        struct student info[3];   //declare 3 students [3]
        int i;
        int r;
        for(i=1;i<=3;i++) {
            printf("Enter name for student %d : ",i);
            scanf("%s",info[i].name);   // called struct using "." (dot)
            printf("Enter age for sudent %d : ",i);
            scanf("%d",&info[i].age);
            printf("Enter grade for student %d : ",i);
            do {
                r = scanf("%d", &info[i].grade);
                if (r < 1) {
                    printf("input error, retry\n");
            } while (r < 1)
        }
        return 0;
    }