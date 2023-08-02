#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/string.h>


#define IPADDRESS(addr) \
	((unsigned char *)&addr)[3], \
	((unsigned char *)&addr)[2], \
	((unsigned char *)&addr)[1], \
	((unsigned char *)&addr)[0]
	
static struct nf_hook_ops *nf_blockipaddr_ops = NULL;


static char *ip_addr_rule = "23.46.202.144";

static unsigned int nf_blockipaddr_handler(void *priv, struct sk_buff *skb, const struct nf_hook_state *state)
{
	if (!skb) {
		return NF_ACCEPT;
	} else {
		char *str = (char *)kmalloc(16, GFP_KERNEL);
		u32 sip;
		struct sk_buff *sb = NULL;
		struct iphdr *iph;

		sb = skb;
		iph = ip_hdr(sb);
		sip = ntohl(iph->saddr);
		
		sprintf(str, "%u.%u.%u.%u", IPADDRESS(sip));
		if(!strcmp(str, ip_addr_rule)) {
			printk(KERN_INFO "Blocked a packet from ynet!\n");
			return NF_DROP;
		} else {
			return NF_ACCEPT;
		}
	}
}

static int __init nf_minifirewall_init(void) {

	nf_blockipaddr_ops = (struct nf_hook_ops*)kcalloc(1, sizeof(struct nf_hook_ops), GFP_KERNEL);
	if (nf_blockipaddr_ops != NULL) {
		nf_blockipaddr_ops->hook = (nf_hookfn*)nf_blockipaddr_handler;
		nf_blockipaddr_ops->hooknum = NF_INET_PRE_ROUTING;
		nf_blockipaddr_ops->pf = NFPROTO_IPV4;
		nf_blockipaddr_ops->priority = NF_IP_PRI_FIRST;

		nf_register_net_hook(&init_net, nf_blockipaddr_ops);
	}
	return 0;
}

static void __exit nf_minifirewall_exit(void) {

	if (nf_blockipaddr_ops  != NULL) {
		nf_unregister_net_hook(&init_net, nf_blockipaddr_ops);
		kfree(nf_blockipaddr_ops);
	}
	printk(KERN_INFO "Exit");
}

module_init(nf_minifirewall_init);
module_exit(nf_minifirewall_exit);

MODULE_LICENSE("GPL");

