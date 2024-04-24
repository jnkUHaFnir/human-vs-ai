for(ind=count-newcount;ind<count;ind++) {
    ri[ind]=newi[ind-count+newcount];
    ci[ind]=newj[ind-count+newcount];
}
for(ind = 0; ind < newcount; ind++) {
    ri[count - newcount + ind] = newi[ind];
    ci[count - newcount + ind] = newj[ind];
}
