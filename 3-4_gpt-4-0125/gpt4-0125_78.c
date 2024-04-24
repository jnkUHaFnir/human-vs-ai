bool next_combination(int* combo, int k, int n) {
    // Iterate from the last to the first index in the combination array
    for (int i = k - 1; i >= 0; --i) {
        // Check if the current index can be incremented or needs to roll over
        if (++combo[i] < n - (k - 1 - i)) {
            // Properly adjust following indices
            for (int j = i + 1; j < k; ++j) {
                combo[j] = combo[j - 1] + 1;
            }
            return true; // Next combination was found
        }
    }
    return false; // All combinations have been generated
}
