void loadDataset (int DataSetSize, char *filename, float **v)
float* temp_v = malloc(sizeof(float) * DataSetSize);
*v = temp_v;
free(v);
