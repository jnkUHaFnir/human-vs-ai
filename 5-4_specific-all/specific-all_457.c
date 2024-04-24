for(ind=count-newcount;ind<count;ind++)
{
    ri[ind]=newi[ind-count+newcount];
    ci[ind]=newj[ind-count+newcount];
}
// Maximum possible size for ri and ci arrays based on grid dimensions
int maxPoints = (n + 1) * (n + 1);
int ri[maxPoints];
int ci[maxPoints];
int k = 0;

// Rest of your code remains the same
