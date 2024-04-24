int newcount = 0;
int newIdx = count; // Start new index from the end of the current 'ri' and 'ci' arrays

for (int ind = 0; ind < newcount; ind++) {
    ri[ind + newIdx] = newi[ind];
    ci[ind + newIdx] = newj[ind];
}

count += newcount; // Update the total count of elements in 'ri' and 'ci'
