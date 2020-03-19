#ifndef _SYS_STAT_H
#define _SYS_STAT_H

#include <features.h>
#include <sys/types.h>
#include __SYSINC__(stat.h)

int lstat __P((__const char * __path, struct stat * __statbuf));
int fstat __P((int __fd, struct stat * __statbuf));

/* hysterical raisins */
#define S_IREAD		S_IRUSR /* read permission, owner */
#define S_IWRITE	S_IWUSR /* write permission, owner */
#define S_IEXEC		S_IXUSR /* execute/search permission, owner */

int stat (const char * restrict path, struct stat * restrict buf);
int mkdir(const char *pathm, mode_t mode);
int mknod(char *path, mode_t mode, dev_t dev);
int mkfifo(char *path, mode_t mode);
mode_t umask(mode_t mode);
int chmod(const char *path, mode_t mode);
int chown(const char *path, uid_t owner, gid_t group);

#endif
