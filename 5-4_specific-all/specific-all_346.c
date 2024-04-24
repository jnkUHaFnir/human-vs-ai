void createdataset(int Datasetsize, char *filename)
{
  FILE *f;
  float *v = (float *)malloc(Datasetsize * sizeof(float)); // allocate memory for float array

  srand((unsigned int)time(NULL));

  for(size_t i = 0; i < Datasetsize; i++) 
    v[i] = ((float)rand() / (float)(RAND_MAX)) * 100;

  f = fopen(filename, "wb");
  if(f == NULL) {
    printf("File can't be opened\n");
    return;
  }

  fwrite(v, sizeof(float), Datasetsize, f);
  fclose(f);

  free(v); // free dynamically allocated memory
}
void loadDataset(int DataSetSize, char *filename, float *v) 
{
  FILE *fp;
  
  fp = fopen(filename, "rb");
  if(fp == NULL) {
    printf("File can't be opened\n");
    return;
  }

  fseek(fp, 0, SEEK_END); // move the file cursor to the end
  long fileSize = ftell(fp); // calculate the file size
  fseek(fp, 0, SEEK_SET); // move the file cursor back to the beginning

  int totalElements = fileSize / sizeof(float); // calculate total float elements in the file

  int s = fread(v, sizeof(float), totalElements, fp);
  printf("%d\n", s);
  
  for(int i = 0; i < totalElements; i++) {
    printf("\t%f", v[i]);
  }

  fclose(fp);
}
