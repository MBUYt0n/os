// // // // // // // // #include <unistd.h>
// // // // // // // // #include <stdio.h>
// // // // // // // // #include <stdlib.h>
// // // // // // // // #include <sys/types.h>
// // // // // // // // int glob = 6; /* external variable in initialized data */
// // // // // // // // char buf[] = "a write to stdout\n";
// // // // // // // // int main(void)
// // // // // // // // {
// // // // // // // //     int var; /* automatic variable on the stack */
// // // // // // // //     pid_t pid;
// // // // // // // //     var = 88;
// // // // // // // //     if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
// // // // // // // //         printf("write error");
// // // // // // // //     printf("before fork\n"); /* we don't flush stdout */
// // // // // // // //     if ((pid = fork()) < 0)
// // // // // // // //     {
// // // // // // // //         printf("fork error");
// // // // // // // //     }
// // // // // // // //     else if (pid == 0)
// // // // // // // //     {           /* child */
// // // // // // // //         glob++; /* modify variables */
// // // // // // // //         var++;
// // // // // // // //     }
// // // // // // // //     else
// // // // // // // //     {
// // // // // // // //         sleep(2); /* parent */
// // // // // // // //     }
// // // // // // // //     printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
// // // // // // // //     exit(0);
// // // // // // // // }

// // // // // // // #include <stdio.h>
// // // // // // // #include <unistd.h>
// // // // // // // #include <stdlib.h>
// // // // // // // int main()
// // // // // // // {
// // // // // // //     int pid;
// // // // // // //     pid = fork(); // return 3 values, 0--to the child process, >0 pare>if(pid<0)
// // // // // // //     if (pid < 0)
// // // // // // //     {
// // // // // // //         printf("fork error\n");
// // // // // // //         exit(1);
// // // // // // //     }
// // // // // // //     else if (pid == 0)
// // // // // // //     {
// // // // // // //         sleep(5);
// // // // // // //         printf("child process\n");
// // // // // // //         printf("child id=%d,parent=%d\n", getpid(), getppid());
// // // // // // //     }
// // // // // // //     else
// // // // // // //     {
// // // // // // //         printf("parent process\n");
// // // // // // //         printf("parent id=%d, child id=%d\n", getpid(), pid);
// // // // // // //         exit(1);
// // // // // // //     }
// // // // // // //     return 0;
// // // // // // // }

// // // // // // #include <stdio.h>
// // // // // // #include <unistd.h>
// // // // // // #include <stdlib.h>
// // // // // // int main()
// // // // // // {
// // // // // //     int pid;
// // // // // //     pid = fork(); // return 3 values, 0--to the child process, >0 pare>if(pid<0)
// // // // // //     if (pid < 0)
// // // // // //     {
// // // // // //         printf("fork error\n");
// // // // // //         exit(1);
// // // // // //     }
// // // // // //     else if (pid == 0)
// // // // // //     {
// // // // // //         sleep(5);
// // // // // //         printf("child process\n");
// // // // // //         printf("child id=%d,parent=%d\n", getpid(), getppid());
// // // // // //         exit(1);
// // // // // //     }
// // // // // //     else
// // // // // //     {
// // // // // //         printf("parent process\n");
// // // // // //         printf("parent id=%d, child id=%d\n", getpid(), pid);
// // // // // //         exit(1);
// // // // // //     }
// // // // // //     return 0;
// // // // // // }

// // // // // #include <stdio.h>
// // // // // #include <unistd.h>
// // // // // #include <stdlib.h>
// // // // // int main()
// // // // // {
// // // // //     fork();
// // // // //     printf("one\n");
// // // // //     fork();
// // // // //     printf("two\n");
// // // // //     fork();
// // // // //     printf("three\n");
// // // // // }

// // // // #include <stdio.h>
// // // // #include <sys/wait.h>
// // // // #include <unistd.h>
// // // // int main()
// // // // {
// // // //     if (fork() == 0)
// // // //         printf("child process\n");
// // // //     else
// // // //     {
// // // //         wait(NULL);
// // // //         printf("Parent process\n");
// // // //     }
// // // //     return 0;
// // // // }

// // // #include <pthread.h>
// // // #include <stdio.h>
// // // #include <stdlib.h>
// // // void *PrintHello()
// // // {
// // //     printf("hello\n");
// // //     pthread_exit(NULL);
// // // }
// // // int main(int argc, char *argv[])
// // // {
// // //     pthread_t tid;
// // //     int rc;
// // //     rc = pthread_create(&tid, NULL, PrintHello, NULL);
// // //     if (rc)
// // //     {
// // //         printf("ERROR; return code from pthread_create() is %d\n", rc);
// // //         exit(1);
// // //     }
// // //     pthread_join(tid, NULL);
// // //     pthread_exit(NULL);
// // // }

// // #include <pthread.h>
// // #include <stdio.h>
// // #include <stdlib.h>
// // int a[10];
// // void *fact(void *n)
// // {
// //     int i, var;
// //     int sum = 0;
// //     var = *((int *)n);
// //     printf("Hello World! It's me, thread %d\n", var);
// //     for (i = 0; i < var; i++)
// //     {
// //         sum = sum + i;
// //     }

// //     int *result = malloc(sizeof(int));
// //     *result = sum;
// //     return result;
// // }

// // int main(int argc, char *argv[])
// // {
// //     pthread_t tid;
// //     int n = 9;
// //     int rc;
// //     int *sum1;
// //     rc = pthread_create(&tid, NULL, fact, (void *)&n);
// //     if (rc)
// //     {
// //         printf("ERROR; return code from pthread_create() is %d\n", rc);
// //         exit(1);
// //     }
// //     pthread_join(tid, (void **)&sum1);
// //     printf("sum=%d\n", *sum1);
// //     /* Last thing that main() should do */
// //     pthread_exit(NULL);
// // }

// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// int a[10];
// void *PrintHello(void *n)
// {
//     // int i;
//     int var;
//     var = (int)n;
//     printf("Hello World! It's me, thread %d\n", var);
//     var = var + 2;
//     return (void *)var;
//     pthread_exit(NULL);
// }
// // int a[10];
// int main(int argc, char *argv[])
// {
//     pthread_t tid;
//     int n = 9;
//     int rc;
//     void *a;
//     rc = pthread_create(&tid, NULL, PrintHello, (void *)n);
//     if (rc)
//     {
//         printf("ERROR; return code from pthread_create() is %d\n", rc);
//         exit(1);
//     }
//     pthread_join(tid, &a);
//     printf("%d\n", (int)a);
//     /* Last thing that main() should do */
//     pthread_exit(NULL);
// }

#include <linux/module.h>
#include <linux/kernel.h>
/* This function is called when the module is loaded. */
int simple_init(void)
{
    printk(KERN_INFO "Loading Module\n");
    return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void)
{
    printk(KERN_INFO "Removing Module\n");
}

module_init(simple_init);
module_exit(simple_exit);