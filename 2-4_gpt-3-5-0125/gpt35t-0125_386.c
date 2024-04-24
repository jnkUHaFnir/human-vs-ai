int success = 1;
size_t size = sizeof(stringcard)/sizeof(stringcard[0]); 
size_t size2 = sizeof(reds)/sizeof(reds[0]);

if(size == size2)
{
    for(int i = 0; i<size;i++)
    {
        if(strcmp(stringcard[i], reds[i]) != 0){ 
            success = 0; 
            break; 
        }
    }

    if(success == 1){
        printf("All elements of stringcard are present in reds array.\n");
    } else {
        printf("Not all elements of stringcard are present in reds array.\n");
    }
} else {
    printf("Arrays have different sizes.\n");
}
