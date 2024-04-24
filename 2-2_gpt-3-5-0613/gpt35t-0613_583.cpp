char c1;
char c2;
char c3;
int o_len = strlen(output);
for(int i = 2; i < o_len - 2; i = i + 3){
  if(i == 2){
    c1 = output[i];
    c2 = output[i+1];
    c3 = output[i+2];
    output[i] = ' ';
    output[i+1] = c1;
    output[i+2] = c2;
  }
  else{
    c1 = output[i];
    c2 = output[i+1];
    c3 = output[i+2];
    output[i] = ' ';
    output[i+1] = c1;
    output[i+2] = c2;
  }
}
