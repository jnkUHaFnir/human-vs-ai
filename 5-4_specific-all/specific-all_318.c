#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/netlink.h>

#define NETLINK_USER 31
#define MAX_PAYLOAD 1024

int main()
{
    struct sockaddr_nl src_addr, dest_addr;
    struct nlmsghdr *nlh = NULL;
    struct iovec iov;
    struct msghdr msg;
    int sock_fd;

    sock_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_USER);
    if (sock_fd < 0)
    {
        perror("socket");
        return -1;
    }

    memset(&src_addr, 0, sizeof(src_addr));
    src_addr.nl_family = AF_NETLINK;
    src_addr.nl_pid = getpid();

    bind(sock_fd, (struct sockaddr *)&src_addr, sizeof(src_addr));

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.nl_family = AF_NETLINK;
    dest_addr.nl_pid = 0; // For Linux Kernel
    dest_addr.nl_groups = 0; // unicast

    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
    nlh->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
    nlh->nlmsg_pid = getpid();
    nlh->nlmsg_flags = 0;

    strcpy(NLMSG_DATA(nlh), "Hello from user program!");

    iov.iov_base = (void *)nlh;
    iov.iov_len = nlh->nlmsg_len;
    memset(&msg, 0, sizeof(struct msghdr));
    msg.msg_name = (void *)&dest_addr;
    msg.msg_namelen = sizeof(dest_addr);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    printf("Sending message to kernel\n");
    sendmsg(sock_fd, &msg, 0);

    printf("Waiting for message from kernel\n");
    recvmsg(sock_fd, &msg, 0);
    printf("Received message from kernel: %s\n", (char *)NLMSG_DATA(nlh));

    close(sock_fd);
    return 0;
}
#include <linux/module.h>
#include <linux/kernel.h>
#include <net/sock.h>
#include <linux/skbuff.h>
#include <linux/netlink.h>

#define NETLINK_USER 31

struct sock *nl_sk = NULL;

static void hello_nl_recv_msg(struct sk_buff *skb)
{
    struct nlmsghdr *nlh;

    nlh = nlmsg_hdr(skb);
    printk(KERN_INFO "Netlink received msg payload: %s\n", (char *)NLMSG_DATA(nlh));

    // Prepare and send a response back
    struct sk_buff *skb_out;
    int res;
    struct nlmsghdr *nlh_out;
    char *msg = "Hello from kernel module!";

    skb_out = nlmsg_new(strlen(msg) + 1, 0);
    nlh_out = nlmsg_hdr(skb_out);
    strcpy(NLMSG_DATA(nlh_out), msg);

    NETLINK_CB(skb_out).dst_group = 0;
    res = nlmsg_unicast(nl_sk, skb_out, nlh->nlmsg_pid);

    if (res < 0)
        printk(KERN_INFO "Error while sending back to user\n");
}

static int __init hello_init(void)
{
    nl_sk = netlink_kernel_create(&init_net, NETLINK_USER, 0, hello_nl_recv_msg, NULL, THIS_MODULE);
    if (!nl_sk)
    {
        printk(KERN_ALERT "Error creating socket.\n");
        return -10;
    }
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Exiting hello module\n");
    netlink_kernel_release(nl_sk);
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
