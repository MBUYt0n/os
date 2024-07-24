#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>

int thread_fn1(void *data);
int thread_fn2(void *data);
int thread_fn3(void *data);

static struct task_struct *task1;
static struct task_struct *task2;
static struct task_struct *task3;

int thread_fn1(void *data)
{
    pr_info("Thread 1 (PID: %d, Executable name: %s)\n", current->pid, current->comm);
    task2 = kthread_create(thread_fn2, NULL, "mythread2");
    if (!IS_ERR(task2))
        wake_up_process(task2);
    return 0;
}

int thread_fn2(void *data)
{
    pr_info("  Thread 2 (PID: %d, Executable name: %s)\n", current->pid, current->comm);
    task3 = kthread_create(thread_fn3, NULL, "mythread3");
    if (!IS_ERR(task3))
        wake_up_process(task3);
    return 0;
}

int thread_fn3(void *data)
{
    pr_info("    Thread 3 (PID: %d, Executable name: %s)\n", current->pid, current->comm);
    return 0;
}

static int __init osprj_init(void)
{
    task1 = kthread_run(thread_fn1, NULL, "mythread1");
    if (IS_ERR(task1))
    {
        pr_err("Failed to create thread 1\n");
        return PTR_ERR(task1);
    }
    return 0;
}

static void __exit osprj_exit(void)
{
    if (task1)
    {
        kthread_stop(task1);
        task1 = NULL;
    }
    if (task2)
    {
        kthread_stop(task2);
        task2 = NULL;
    }
    if (task3)
    {
        kthread_stop(task3);
        task3 = NULL;
    }
}

module_init(osprj_init);
module_exit(osprj_exit);
MODULE_LICENSE("GPL");
