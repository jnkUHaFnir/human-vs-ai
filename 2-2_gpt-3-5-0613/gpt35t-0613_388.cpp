if (count > 0) {
    for (ind = count - newcount; ind < count; ind++) {
        ri[ind] = newi[ind - count + newcount];
        ci[ind] = newj[ind - count + newcount];
    }
}
int newi[n];
int newj[n];
