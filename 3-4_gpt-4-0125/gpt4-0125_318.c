#include <linux/string.h>

static void hello_nl_recv_msg(struct sk_buff *skb)
{
    struct nlmsghdr *nlh;
    struct sk_buff *skb_out;
    int pid;
    int msg_size;
    char *msg = "Hello from kernel";
    int res;

    printk(KERN_INFO "Entering: %s\n", __FUNCTION__);

    nlh = (struct nlmsghdr*)skb->data;
    printk(KERN_INFO "Netlink received msg payload: %s\n", (char*)NLMSG_DATA(nlh));
    pid = nlh->nlmsg_pid; /* pid of sending process */
    msg_size = strlen(msg);

    skb_out = nlmsg_new(msg_size, 0);
    if (!skb_out)
    {
        printk(KERN_ERR "Failed to allocate new skb\n");
        return;
    }

    nlh = nlmsg_put(skb_out, 0, 0, NLMSG_DONE, msg_size, 0);
    if(nlh==NULL)
    {
        nlmsg_free(skb_out);
        printk(KERN_ERR "Failed to put nlmsg\n");
        return;
    }

    strncpy(nlmsg_data(nlh), msg, msg_size);

    res = nlmsg_unicast(nl_sk, skb_out, pid);

    if (res < 0)
        printk(KERN_INFO "Error while sending back to user\n");
}
