void createdataset(int Datasetsize, char * filename)
{
  FILE *f;
  int su;
  float *v = malloc(Datasetsize * sizeof(float));    

  srand((unsigned int)time(NULL));

  for(int i = 0; i < Datasetsize; i++) 
    v[i]=((float)rand()/(float)(RAND_MAX)) * 100;

  f = fopen(filename, "wb");
  su = fwrite(v ,sizeof(float) , Datasetsize , f);
  printf("%d\n",su);

  fclose(f);
  free(v);
}
void loadDataset (int DataSetSize, char *filename) 
{
  FILE *fp;
  int s;

  float *v = malloc(DataSetSize * sizeof(float));

  fp = fopen(filename, "rb");
  if(fp == NULL) {
    printf("File cant be opened");
    return;
  }

  s = fread(v , sizeof(float), DataSetSize, fp );
  printf("%d\n", s);

  for(int i = 0; i < DataSetSize; i++)
    printf("\t%f", v[i]);

  fclose(fp);
  free(v);
}
int main()  
{ 
    char filein[50];
    int datasetsize;

    printf("Enter the size of the datasetsize: ");
    scanf("%d",&datasetsize);

    printf("%d\n",datasetsize);
    printf("Enter input file name: ");
    scanf("%s",filein);
    printf("%s\n",filein);
    createdataset(datasetsize, filein);
    loadDataset(datasetsize, filein);

    return 0;
}
