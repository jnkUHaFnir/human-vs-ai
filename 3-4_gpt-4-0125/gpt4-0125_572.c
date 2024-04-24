// Assume file length is received and stored in file_length
ssize_t remain_data = file_length;

while ((remain_data > 0) && ((b = recv(sockfd, buffer, min(BUFFER_SIZE, remain_data), 0)) > 0)) {
    fwrite(buffer, sizeof(char), b, fp);
    remain_data -= b;
}
// Note: You will need a function or macro for min().
// After sending filename
long int file_size = get_file_size(fname);

// Send file size - as example, convert to string and ensure protocol compatibility
sprintf(buffer, "%ld", file_size);
send_all(sockfd, buffer, strlen(buffer) + 1); // Include null-terminator

// Then send the file as before
send_txt_file(sockfd, BUFFER_SIZE, fname); // Ensure send_txt_file handles sizes properly
