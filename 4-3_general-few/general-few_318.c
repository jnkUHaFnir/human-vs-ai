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

void send_nl_message(int pid, char *message) {
    struct sk_buff *skb_out;
    struct nlmsghdr *nlh;
    int msg_size;
    int res;

    msg_size = strlen(message);

    skb_out = nlmsg_new(msg_size, 0);
    if (!skb_out) {
        printk(KERN_ERR "Failed to allocate new skb\n");
        return;
    }

    nlh = nlmsg_put(skb_out, 0, 0, NLMSG_DONE, msg_size, 0);
    NETLINK_CB(skb_out).dst_group = 0;

    strncpy(nlmsg_data(nlh), message, msg_size);

    res = nlmsg_unicast(nl_sk, skb_out, pid);
    if (res < 0) {
        printk(KERN_ERR "Error while sending back to user\n");
    }
}

static void hello_nl_recv_msg(struct sk_buff *skb) {
    struct nlmsghdr *nlh;
    int pid;

    printk(KERN_INFO "Entering: %s\n", __FUNCTION__);

    nlh = nlmsg_hdr(skb);
    printk(KERN_INFO "Netlink received msg payload: %s\n", (char*)NLMSG_DATA(nlh));
    pid = nlh->nlmsg_pid;

    printk("About to send message back to user\n");
    send_nl_message(pid, "Hello from kernel");

    printk(KERN_INFO "Successfully sent message back to user\n");
}

static int __init hello_init(void) {
    printk(KERN_INFO "Entering: %s\n", __FUNCTION__);

    nl_sk = netlink_kernel_create(&init_net, NETLINK_USER, 0, hello_nl_recv_msg, NULL, THIS_MODULE);
    if (!nl_sk) {
        printk(KERN_ALERT "Error creating socket.\n");
        return -10;
    }

    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "Exiting hello module\n");
    netlink_kernel_release(nl_sk);
}

module_init(hello_init);
module_exit(hello_exit);
