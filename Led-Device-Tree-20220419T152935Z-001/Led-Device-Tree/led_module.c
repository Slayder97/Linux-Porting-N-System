#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include "led_module.h"

#define AUTHOR  "Huu Thinh <huuthinh1603@gmail.com>"
#define DESC    "This module is led"

static int led_probe(struct platform_device *pdev)
{
	struct resource *res;
	uint32_t val;
	uint32_t __iomem *base_addr;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if(!res)
		return -ENOMEM;
	
	base_addr = ioremap(res->start, res->end - res->start);
	if(!base_addr)
		return -ENOMEM;
	
	val = readl(base_addr + GPIO_OE_OFFSET);
	val &= ~(LED);
	writel(val, base_addr + GPIO_OE_OFFSET);
	
	val = readl(base_addr + GPIO_SETDATAOUT_OFFSET);
	val |= LED;
	writel(val, base_addr + GPIO_SETDATAOUT_OFFSET);

	platform_set_drvdata(pdev, base_addr);
	
	printk(KERN_INFO "Huu Thinh: %s\t%d\n", __func__, __LINE__);
	return 0;
}

static int led_remove(struct platform_device *pdev)
{
	uint32_t val;
	uint32_t __iomem *base_addr = platform_get_drvdata(pdev);

	val = readl(base_addr + GPIO_CLEARDATAOUT_OFFSET);
	val |= LED;
	writel(val, base_addr + GPIO_CLEARDATAOUT_OFFSET);

	iounmap(base_addr);
	return 0;
}

static struct of_device_id led_of_id[] = {
	{.compatible = "led, module", },
	{ }
};

static struct platform_driver led_driver = {
	.probe = led_probe,
	.remove = led_remove,
	.driver = {
		.name = "led, module",
		.of_match_table = led_of_id,
	},
};

module_platform_driver(led_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESC);
