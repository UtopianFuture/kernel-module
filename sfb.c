#include <linux/kernel.h> /* Needed for KERN_INFO */
#include <linux/module.h> /* Needed by all modules */

int init_module(void) {
  uint64_t val;
  __asm__ __volatile__("csrrd %0, 0x80 \n\t" : "=r"(val));
  printk(KERN_INFO "sfb: 0x%llx\n", val);
  __asm__ __volatile__("li.d $t1, 0x0 \n\t"
                       "ori $t0, $zero, %0 \n\t"
                       "csrxchg $t1, $t0, %1 \n\t"
                       :
                       : "i"(0x100), "i"(0x80)
                       : "$t0", "$t1");
  __asm__ __volatile__("csrrd %0, 0x80 \n\t" : "=r"(val));
  printk(KERN_INFO "sfb: 0x%llx\n", val);
  return 0;
}

void cleanup_module(void) { printk(KERN_INFO "Goodbye world \n"); }

MODULE_LICENSE("GPL");
