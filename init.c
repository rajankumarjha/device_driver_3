#include"header.h"
#include"fops.h"
#include"declaration.h"
int majorno,minorno,nod;
dev_t devid;
EXPORT_SYMBOL(mysymbol);
static int __init initfunc(void)
{
	majorno=MAJORNO;
	minorno=MINORNO;
	nod=NOD;
	printk(KERN_INFO "Hello kernel here we are\n");
	if(majorno==0)
	{
	majorno=alloc_chrdev_region(&devid,minorno,nod,DEVNAME);
	if(majorno==-1)
	{
		printk(KERN_ERR"ALLOC NOT WORKING\n");
		goto out;
	}
	}
	else
	{
	majorno=register_chrdev(majorno,DEVNAME,&fops);
	if(majorno==-1)
	{
		printk(KERN_ERR"Register_dev error\n");
		goto out;
	}
	}

	printk(KERN_INFO "MAJORNO %d \n",MAJOR(devid));
	printk(KERN_INFO "MINORNO %d \n",MINOR(devid));
	return 0;
	
out:
	return -1;


}

module_init(initfunc);
