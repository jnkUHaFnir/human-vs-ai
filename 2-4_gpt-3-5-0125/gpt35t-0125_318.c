static void hello_nl_recv_msg(struct sk_buff *skb)
{
    struct nlmsghdr *nlh;
    int pid;

    printk(KERN_INFO "Entering: %s\n", __FUNCTION__);

    nlh = (struct nlmsghdr *)skb->data;
    printk(KERN_INFO "Netlink received msg payload: %s\n", (char *)NLMSG_DATA(nlh));

    pid = nlh->nlmsg_pid; /* pid of sending process */
    NETLINK_CB(skb).dst_group = 0; /* not in mcast group */

    printk("About to send msg back:\n");
    netlink_unicast(nl_sk, skb, pid, MSG_DONTWAIT);
}
