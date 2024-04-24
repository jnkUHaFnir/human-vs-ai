// Code initialization and previous loops remain unchanged

int position = 0; // Initialize position to store new 't' points

while(count>0){
    int num=0;
    i=ri[0];
    j=ci[0];
    c[i][j]='n';
    int newcount=0;
    
    // Store new 't' points in temporary arrays
    int temp_newi[4];
    int temp_newj[4];

    if(c[i-1][j]=='f'){
        c[i-1][j]='t';
        newcount++;
        temp_newi[newcount-1]=i-1;
        temp_newj[newcount-1]=j;
    }
    if(c[i+1][j]=='f'){
        c[i+1][j]='t';
        newcount++;
        temp_newi[newcount-1]=i+1;
        temp_newj[newcount-1]=j;
    }
    if(c[i][j-1]=='f'){
        c[i][j-1]='t';
        newcount++;
        temp_newi[newcount-1]=i;
        temp_newj[newcount-1]=j-1;
    }
    if(c[i][j+1]=='f'){
        c[i][j+1]='t';
        newcount++;
        temp_newi[newcount-1]=i;
        temp_newj[newcount-1]=j+1;
    }

    // Add new 't' points to the end of index arrays
    for(int ind = 0; ind < newcount; ind++)
    {
        ri[position] = temp_newi[ind];
        ci[position] = temp_newj[ind];
        position++;
    } 

    count--;  // Update 'count' now that the first 't' point has been processed
}
