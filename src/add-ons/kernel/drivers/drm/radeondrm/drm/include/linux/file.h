/* Public domain. */

#ifndef _LINUX_FILE_H
#define _LINUX_FILE_H

/* both for printf */
#include <haiku-defs.h>
//#include <sys/types.h> 
//#include <sys/systm.h>

#define fput(a)
#define fd_install(a, b)
#define put_unused_fd(a)

inline int
get_unused_fd_flags(unsigned int flags)
{
//	printf("%s: stub\n", __func__);
//	return -1;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
