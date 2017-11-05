#include"header.h"
#include"declaration.h"


static void __exit clean(void)
{
	//unregister_chrdev(majorno,DEVNAME);
	unregister_chrdev_region(devid,nod);
	printk(KERN_INFO "BYE KERNEL\n");
}
module_exit(clean);
