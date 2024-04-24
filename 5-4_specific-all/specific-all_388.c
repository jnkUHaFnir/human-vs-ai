// Update indices in ri and ci after adding new elements to the end
for (ind = 0; ind < newcount; ind++) {
    ri[count - newcount + ind] = newi[ind];
    ci[count - newcount + ind] = newj[ind];
}
