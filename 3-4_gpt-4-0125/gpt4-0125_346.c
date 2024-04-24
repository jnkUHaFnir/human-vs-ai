fp = fopen( filename , "rb" ); // Change from "r" to "rb"
void loadDataset(int DataSetSize, char *filename, float *v) 
{
  FILE *fp;
  int s;

  fp = fopen(filename, "rb"); // Change here
  if (fp == NULL) 
  {
    printf("File can't be opened\n");
    return;  // Add a return here
  }

  s = fread(v, sizeof(float), DataSetSize, fp);
  printf("%d\n", s);
  for (int i = 0; i < DataSetSize; i++) // Ensure proper indexing here
  {
    printf("\t%f", v[i]);
  }

  fclose(fp);
}
