ri[ind] = newi[ind - count + newcount];
ci[ind] = newj[ind - count + newcount];
newcount = 0; // Initialize newcount before adding new trial points

for (ind = count - newcount; ind < count; ind++) {
    ri[ind] = newi[ind - (count - newcount)]; // Adjust the index correctly
    ci[ind] = newj[ind - (count - newcount)]; // Adjust the index correctly
}
