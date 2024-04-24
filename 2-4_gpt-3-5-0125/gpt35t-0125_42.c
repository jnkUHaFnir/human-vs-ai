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

        nlh = (struct nlmsghdr *)skb->data;  
        printk(KERN_INFO "Netlink received msg payload: %s\n", (char *)NLMSG_DATA(nlh));  
        pid = nlh->nlmsg_pid; /* pid of sending process */  
        NETLINK_CB(skb).dst_group = 0; /* not in mcast group */  
        NETLINK_CB(skb).pid = 0; /* from kernel */  
        
        // Prepare a new netlink message
        struct sk_buff *skb_out;
        int msg_size;
        int res;
        
        msg_size = strlen("Response") + 1;
        nlh = nlmsg_new(msg_size, GFP_KERNEL);
        if (!nlh) {
            printk(KERN_ERR "Failed to allocate netlink message\n");
            return;
        }

        strcpy(nlmsg_data(nlh), "Response");
              
        skb_out = nlmsg_new(msg_size, GFP_KERNEL);
        if (!skb_out) {
            printk(KERN_ERR "Failed to allocate a new sk_buff\n");
            nlmsg_free(nlh);
            return;
        }

        NETLINK_CB(skb_out).pid = 0;
        NETLINK_CB(skb_out).dst_group = 0;

        res = nlmsg_unicast(nl_sk, skb_out, pid);
        if (res < 0) {
            printk(KERN_ERR "Error sending message back to the user program\n");
        }

}  

static int __init hello_init(void)  
{  
        printk("Entering: %s\n", __FUNCTION__);  
        nl_sk = netlink_kernel_create(&init_net, NETLINK_USER, 0, hello_nl_recv_msg, NULL, THIS_MODULE);  
        if (!nl_sk) {   
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
