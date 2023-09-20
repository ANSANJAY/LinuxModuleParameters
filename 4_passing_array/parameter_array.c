#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

int param_array[4];
static int argc_count = 0;
module_param_array(param_array, int, &argc_count, S_IWUSR| S_IRUSR);

static int test_arguments_init(void)
{
	int i = 0;
	printk("%s\n", __func__);
	printk("Argc count:%d\n", argc_count);
	printk("Array elements:\n");
	for (i = 0; i < sizeof(param_array)/sizeof(param_array[i]); i++) {
		printk("%d:\t%d\n", i, param_array[i]);
	}
	return 0;
}

static void test_arguments_exit(void)
{
	printk("%s\n", __func__);
}


module_init(test_arguments_init);
module_exit(test_arguments_exit);

