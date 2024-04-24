FILE* file = fopen("files.txt", "r");

char buffer[256];  // buffer to read the line
char *p;
int num;
int* arr;

// read only the first line
fgets(buffer, sizeof(buffer), file);
sscanf(buffer, "%d", &num);

arr = (int *) malloc(num * sizeof(int));

// read the integers in the second line
fgets(buffer, sizeof(buffer), file);
p = buffer;
for(int i = 0; i < num; i++)
{
   // sscanf returns the number of items successfully parsed
   // p points to the beginning of the integer parsed
   while(sscanf(p, "%d", &arr[i]) != 1)
   {
      // keep moving the pointer if the item parsed is not an integer
      p++;
   }
   // move the pointer past the integer parsed
   while(*p != ' ' && *p != '\0')
   {
      p++;
   }
}
