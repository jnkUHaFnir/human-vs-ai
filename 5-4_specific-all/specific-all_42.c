#include <linux/module.h>
#include <linux/kernel.h>
#include <net/sock.h>
#include <linux/netlink.h>
#include <linux/skbuff.h>

#define NETLINK_USER 31

struct sock *nl_sk = NULL;

static void hello_nl_recv_msg(struct sk_buff *skb)
{
    struct nlmsghdr *nlh;
    struct sk_buff *skb_out;
    int pid;

    printk(KERN_INFO "Entering: %s\n", __FUNCTION__);

    nlh = nlmsg_hdr(skb);
    printk(KERN_INFO "Netlink received msg payload: %s\n", (char *)NLMSG_DATA(nlh));

    pid = nlh->nlmsg_pid; /* PID of sending process */

    // Allocate a new response buffer
    skb_out = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
    if (!skb_out) {
        printk(KERN_ERR "Failed to allocate new skb\n");
        return;
    }

    nlh = nlmsg_put(skb_out, 0, 0, NLMSG_DONE, NLMSG_SPACE(MAX_PAYLOAD));
    NETLINK_CB(skb_out).dst_group = 0;
    strncpy(nlmsg_data(nlh), "Hello from kernel", MAX_PAYLOAD);

    // Send the message back to the user program
    netlink_unicast(nl_sk, skb_out, pid, MSG_DONTWAIT);
}

static int __init hello_init(void)
{
    printk("Entering: %s\n", __FUNCTION__);

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
