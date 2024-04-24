for(ind=count-newcount;ind<count;ind++) {
    ri[ind]=newi[ind-count+newcount];
    ci[ind]=newj[ind-count+newcount];
}
int newInd = count - newcount;
for(int ind = 0; ind < newcount; ind++) {
    ri[newInd] = newi[ind];
    ci[newInd] = newj[ind];
    newInd++;
}
