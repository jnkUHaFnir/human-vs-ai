for(ind=count-newcount;ind<count;ind++)
{
    ri[ind]=newi[ind-count+newcount];
    ci[ind]=newj[ind-count+newcount];
}
for(ind=0;ind<newcount;ind++)
{
    ri[count+ind]=newi[ind];
    ci[count+ind]=newj[ind];
}