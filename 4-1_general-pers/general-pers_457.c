for(ind=count-newcount;ind<count;ind++)
{
    ri[ind]=newi[ind-count+newcount];
    ci[ind]=newj[ind-count+newcount];
}
int currentIndex = count - newcount; // Start index for adding new 't' points

for (int ind = 0; ind < newcount; ind++)
{
    ri[currentIndex + ind] = newi[ind];
    ci[currentIndex + ind] = newj[ind];
}
count += newcount; // Update the count to include the new 't' points
