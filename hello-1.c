/*
 *  hello-1.c - The simplest kernel module.
 */
#include <linux/kernel.h> /* Needed for KERN_INFO */
#include <linux/module.h> /* Needed by all modules */

int init_module(void) {
  printk(KERN_INFO "Hello world \n");

  /*
   * A non 0 return means init_module failed; module can't be loaded.
   */
  return 0;
}

void cleanup_module(void) { printk(KERN_INFO "Goodbye world \n"); }

MODULE_LICENSE("GPL");
