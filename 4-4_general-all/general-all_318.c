#include <sys/socket.h>
#include <linux/netlink.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
    if (sock_fd < 0)
    {
        perror("socket");
        return -1;
    }

    memset(&src_addr, 0, sizeof(src_addr));
    src_addr.nl_family = AF_NETLINK;
    src_addr.nl_pid = getpid(); /* self pid */
    bind(sock_fd, (struct sockaddr *)&src_addr, sizeof(src_addr));

    struct nlmsghdr *nlh_send = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
    nlh_send->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
    nlh_send->nlmsg_pid = getpid();
    nlh_send->nlmsg_flags = 0;

    strcpy(NLMSG_DATA(nlh_send), "Hello");

    struct iovec iov_send;
    iov_send.iov_base = (void *)nlh_send;
    iov_send.iov_len = nlh_send->nlmsg_len;

    struct sockaddr_nl dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.nl_family = AF_NETLINK;
    dest_addr.nl_pid = 0; /* For Linux Kernel */
    dest_addr.nl_groups = 0; /* unicast */

    struct msghdr msg_send;
    memset(&msg_send, 0, sizeof(msg_send));
    msg_send.msg_name = (void *)&dest_addr;
    msg_send.msg_namelen = sizeof(dest_addr);
    msg_send.msg_iov = &iov_send;
    msg_send.msg_iovlen = 1;

    printf("Sending message to kernel\n");
    sendmsg(sock_fd, &msg_send, 0);

    struct nlmsghdr *nlh_recv = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
    struct iovec iov_recv;
    iov_recv.iov_base = (void *)nlh_recv;
    iov_recv.iov_len = nlh_recv->nlmsg_len;

    struct msghdr msg_recv;
    memset(&msg_recv, 0, sizeof(msg_recv));
    msg_recv.msg_iov = &iov_recv;
    msg_recv.msg_iovlen = 1;

    printf("Waiting for message from kernel\n");

    recvmsg(sock_fd, &msg_recv, 0);
    printf("Received message payload: %s\n", (char *)NLMSG_DATA(nlh_recv));

    close(sock_fd);

    return 0;
}
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <net/sock.h>
#include <linux/netlink.h>
#include <linux/skbuff.h>

#define NETLINK_USER 31

struct sock *nl_sk = NULL;

static void hello_nl_recv_msg(struct sk_buff *skb)
{
    struct nlmsghdr *nlh;
    unsigned char *msg_data;

    printk(KERN_INFO "Entering: %s\n", __FUNCTION__);

    nlh = nlmsg_hdr(skb);
    msg_data = NLMSG_DATA(nlh);
    printk(KERN_INFO "Netlink message received from user program: %s\n", (char *)msg_data);

    struct sk_buff *skb_out;
    struct nlmsghdr *nlh_out;
    
    int pid = nlh->nlmsg_pid; /* pid of sending process */

    skb_out = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
    if (!skb_out)
    {
        printk(KERN_ERR "Failed to allocate new skb\n");
        return;
    }

    nlh_out = nlmsg_put(skb_out, 0, 0, NLMSG_SPACE(MAX_PAYLOAD), 0);
    strcpy(NLMSG_DATA(nlh_out), "Hello from kernel");

    NETLINK_CB(skb_out).portid = 0;           /* from kernel */
    NETLINK_CB(skb_out).dst_group = 0;        /* not in mcast group */
    NETLINK_CB(skb_out).pid = 0;               /* from kernel */
    NETLINK_CB(skb_out).dst_pid = pid;

    /* Send message back to user program */
    nlmsg_unicast(nl_sk, skb_out, pid);
}

static int __init hello_init(void)
{
    printk(KERN_INFO "Entering: %s\n", __FUNCTION__);

    struct netlink_kernel_cfg cfg = {
        .input = hello_nl_recv_msg,
    };

    nl_sk = netlink_kernel_create(&init_net, NETLINK_USER, &cfg);
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
