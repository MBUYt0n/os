#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>

struct task_struct *task;
struct task_struct *task_child;
struct list_head *list;

int iterate_init(void)
{
    printk(KERN_INFO "my_kernel_module %d\n", current->pid);

    for_each_process(task)
    {
        printk(KERN_INFO "PARENT PID: %d PROCESS: %s STATE: %u\n", task->pid, task->comm, task_state_index(task));
        list_for_each(list, &task->children)
        {
            task_child = list_entry(list, struct task_struct, sibling);
            printk(KERN_INFO "    CHILD OF %s[%d] PID: %d PROCESS: %s STATE: %u\n", task->comm, task->pid,
                   task_child->pid, task_child->comm, task_state_index(task_child));
        }
    }

    return 0;

} 

void cleanup_exit(void) 
{
    printk(KERN_INFO "my_kernel_module %d\n", current->pid);
}

module_init(iterate_init);
module_exit(cleanup_exit); 

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("ITERATE THROUGH ALL PROCESSES/CHILD PROCESSES IN THE OS");
MODULE_AUTHOR("Shusrith");