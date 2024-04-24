// Before updating 'ri' and 'ci', keep track of the current count
int prevCount = count;

// Update 'ri' and 'ci' with new points
for (ind = 0; ind < newcount; ind++) {
    ri[prevCount + ind] = newi[ind];
    ci[prevCount + ind] = newj[ind];
}
