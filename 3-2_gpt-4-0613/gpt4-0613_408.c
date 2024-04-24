Remember to replace `"en_US.UTF-8"` with the appropriate locale for your region.

Also, keep in mind that manipulating strings this way can potentially be dangerous because if you're not careful, you could end up writing beyond the limit of the buffer containing the string. In this case, it seems to work because you're passing command-line arguments which likely have enough extra space, but it's generally a better idea to allocate new buffers to store the results.
