#include <sys/socket.h>
#include <linux/netlink.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NETLINK_USER 31
#define MAX_PAYLOAD 1024 /* maximum payload size*/

struct sockaddr_nl src_addr, dest_addr;
struct nlmsghdr *nlh = NULL;
struct iovec iov;
int sock_fd;
struct msghdr msg;

int main()
{
    sock_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_USER);
    if (sock_fd < 0) {
        perror("socket");
        return -1;
    }

    memset(&src_addr, 0, sizeof(src_addr));
    src_addr.nl_family = AF_NETLINK;
    src_addr.nl_pid = getpid(); /* self pid */

    bind(sock_fd, (struct sockaddr *)&src_addr, sizeof(src_addr));

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.nl_family = AF_NETLINK;
    dest_addr.nl_pid = 0; /* For Linux Kernel */
    dest_addr.nl_groups = 0; /* unicast */

    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
    memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD));
    nlh->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
    nlh->nlmsg_pid = getpid();
    nlh->nlmsg_flags = 0;

    strcpy(NLMSG_DATA(nlh), "Hello");

    iov.iov_base = (void *)nlh;
    iov.iov_len = nlh->nlmsg_len;
    msg.msg_name = (void *)&dest_addr;
    msg.msg_namelen = sizeof(dest_addr);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    printf("Sending message to kernel\n");
    sendmsg(sock_fd, &msg, 0);

    printf("Waiting for message from kernel\n");

    memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD)); /* Clearing the buffer */

    recvmsg(sock_fd, &msg, 0);
    printf("Received message payload: %s\n", (char *)NLMSG_DATA(nlh));

    free(nlh); /* Free allocated memory */
    
    close(sock_fd);

    return 0;
}
#include <linux/module.h>
#include <linux/kernel.h>
#include <net/sock.h>
#include <linux/netlink.h>
#include <linux/skbuff.h>

#define NETLINK_USER 31

struct sock *nl_sock = NULL;

static void hello_nl_recv_msg(struct sk_buff *skb)
{
    struct nlmsghdr *nlh;
    nlh = nlmsg_hdr(skb);

    printk(KERN_INFO "Netlink received message payload: %s\n", (char *)NLMSG_DATA(nlh));

    // Message back to the user space
    nlh->nlmsg_type = 0;
    nlh->nlmsg_flags = 0;
    nlh->nlmsg_pid = 0; // To kernel
    nlh->nlmsg_seq = 0;

    NETLINK_CB(skb).dst_group = 0; // Not in mcast group

    netlink_unicast(nl_sock, skb, nlh->nlmsg_pid, MSG_DONTWAIT);
}

static int __init hello_init(void)
{
    printk("Initializing the netlink kernel module\n");

    nl_sock = netlink_kernel_create(&init_net, NETLINK_USER, 0, hello_nl_recv_msg, NULL, THIS_MODULE);

    if (!nl_sock)
    {
        printk(KERN_ALERT "Error creating socket.\n");
        return -ENOMEM;
    }

    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Exiting the netlink kernel module\n");

    if (nl_sock != NULL)
    {
        netlink_kernel_release(nl_sock);
    }
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
