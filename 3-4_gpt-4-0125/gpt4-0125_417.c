struct MessageHeader {
    uint32_t length; // or uint64_t if you expect very large messages
};

struct Message {
    struct MessageHeader header;
    char contents[1024 - sizeof(struct MessageHeader)];
};
ssize_t recv_all(int sockfd, void* buf, size_t len, int flags) {
    size_t total = 0; // how many bytes we've received
    ssize_t n;

    while (total < len) {
        n = recv(sockfd, (char*)buf + total, len - total, flags);
        
        if (n <= 0) break; // connection closed or an error occurred

        total += n;
    }

    return (n <= 0) ? n : total;
}
struct MessageHeader header;
if (recv_all(ioSock, &header, sizeof(header), 0) <= 0) {
    // Handle error or closed connection
}

// Now you know how much content to read
