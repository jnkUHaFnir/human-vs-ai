#include <linux/module.h>  
#include <linux/kernel.h>  
#include <linux/init.h>  
#include <net/sock.h>  
#include <linux/socket.h>  
#include <linux/net.h>  
#include <asm/types.h>  
#include <linux/netlink.h>  
#include <linux/skbuff.h>  
 
#define NETLINK_USER 31  

struct sock *nl_sk = NULL;  

static void hello_nl_recv_msg(struct sk_buff *skb)  
{
        struct nlmsghdr *nlh;  
        int pid;  

        printk(KERN_INFO "Entering: %s\n", __FUNCTION__);  

        nlh = (struct nlmsghdr*)skb->data;  

        printk(KERN_INFO "Netlink received msg payload: %s\n", (char*)NLMSG_DATA(nlh));  

        pid = nlh->nlmsg_pid; /* pid of sending process */  

        NETLINK_CB(skb).dst_group = 0; /* not in mcast group */  
        NETLINK_CB(skb).pid = 0;       /* from kernel */  

        struct nlmsghdr *reply_nlhdr;
        struct sk_buff *skb_out;
        int reply_msg_size = strlen("Hello from kernel") + 1;

        skb_out = nlmsg_new(reply_msg_size, 0);
        if (!skb_out) {
            printk(KERN_WARNING "Failed to create new skb\n");
            return;
        }

        reply_nlhdr = nlmsg_put(skb_out, 0, 0, NLMSG_DONE, reply_msg_size, 0);
        strncpy(NLMSG_DATA(reply_nlhdr), "Hello from kernel", reply_msg_size);

        netlink_unicast(nl_sk, skb_out, pid, MSG_DONTWAIT);  
}

static int __init hello_init(void)  
{  
        printk("Entering: %s\n",__FUNCTION__);  
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
        printk(KERN_INFO "exiting hello module\n");  
        netlink_kernel_release(nl_sk);  
}  

module_init(hello_init);  
module_exit(hello_exit);  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <linux/netlink.h>  

#define NETLINK_USER 31  
#define MAX_PAYLOAD 1024  /* maximum payload size*/  

struct sockaddr_nl src_addr, dest_addr;  
struct nlmsghdr *nlh = NULL;  
struct iovec iov;  
int sock_fd;  
struct msghdr msg;  

int main()  
{  
    sock_fd = socket(PF_NETLINK, SOCK_RAW, NETLINK_USER);  
    if (sock_fd < 0)  
        return -1;  

    memset(&src_addr, 0, sizeof(src_addr));  
    src_addr.nl_family = AF_NETLINK;  
    src_addr.nl_pid = getpid();  /* self pid */  
    /* interested in group 1<<0 */  
    bind(sock_fd, (struct sockaddr*)&src_addr, sizeof(src_addr));  

    memset(&dest_addr, 0, sizeof(dest_addr));  
    dest_addr.nl_family = AF_NETLINK;  
    dest_addr.nl_pid = 0;   /* For Linux Kernel */  
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

    memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD));
    recvmsg(sock_fd, &msg, 0);  
    printf("Received message payload: %s\n", NLMSG_DATA(nlh));  

    close(sock_fd);  

    return 0;
}
