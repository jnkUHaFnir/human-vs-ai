    #include "stdafx.h"
    #include <stdio.h>
    int _tmain(int argc, _TCHAR* Argo[]){
    FILE *student;
    char brst[255];
    if ((student = fopen("student.txt", "r")) == NULL)
    {
      printf("Failed to load file\n");
      return 1;
    }
    
    for ( fgets( brst, sizeof(brst), student); 
          !feof(student); 
          fgets( brst, sizeof(brst), student) )
    {
      printf("%s\n", brst);
    }
    return 0;
    }