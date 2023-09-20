#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
char *name = "Embedded";
int loop_count = 1;
//module_param(name, charp, S_IRUGO);
module_param(name, charp, 0);
module_param(loop_count, int, S_IRUGO);

static int test_arguments_init(void)
{
    int i;
    printk(KERN_INFO"%s: In init\n", __func__);
    printk(KERN_INFO"%s: Loop Count:%d\n", __func__, loop_count);
    for (i = 0; i < loop_count; i++) 
        printk(KERN_INFO"%s: Hi %s\n", __func__, name);
    return 0;
}

static void test_arguments_exit(void)
{
    printk(KERN_INFO"%s: In exit\n", __func__);
}

module_init(test_arguments_init);
module_exit(test_arguments_exit);
MODULE_AUTHOR("JAMAL");
MODULE_DESCRIPTION("Argument Passing Example");
