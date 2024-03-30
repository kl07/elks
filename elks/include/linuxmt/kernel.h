#ifndef __LINUXMT_KERNEL_H
#define __LINUXMT_KERNEL_H

#include <linuxmt/types.h>
#include <stddef.h>

/*
 * 'kernel.h' contains some often-used function prototypes etc
 */

#ifdef __KERNEL__

#define INT_MAX		((int)(~0U>>1))
#define UINT_MAX	(~0U)
#define LONG_MAX	((long)(~0UL>>1))
#define ULONG_MAX	(~0UL)

/* FIXME move compiler-specific attributes to new header file */
#define noreturn            __attribute__((__noreturn__))
//#define printfesque(n)    __attribute__((__format__(__gnu_printf__, n, n + 1)))
#define printfesque(n)

#define structof(p,t,m) ((t *) ((char *) (p) - offsetof (t,m)))

extern char running_qemu;

extern void do_exit(int) noreturn;

extern int kill_pg(pid_t,sig_t,int);
extern int kill_sl(void);

extern void halt(void) noreturn;
extern void panic(const char *, ...) noreturn;
extern void printk(const char *, ...) printfesque(1);
extern void early_putchar(int);

extern int wait_for_keypress(void);
extern int in_group_p(gid_t);

extern int sys_execve(const char *,char *,size_t);

/*
 * This is defined as a macro, but at some point this might become a
 * real subroutine that sets a flag if it returns true (to do
 * BSD-style accounting where the process is flagged if it uses root
 * privs).  The implication of this is that you should do normal
 * permissions checks first, and check suser() last.
 *
 * "suser()" checks against the effective user id.
 */

#define suser() (current->euid == 0)

#endif

#endif
