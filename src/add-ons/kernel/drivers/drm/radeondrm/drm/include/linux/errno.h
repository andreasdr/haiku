/* Public domain. */

#ifndef _LINUX_ERRNO_H
#define _LINUX_ERRNO_H

#include <haiku-defs.h>
//#include <sys/errno.h>

#define ERESTARTSYS	EINTR
#define EREMOTEIO	EIO
#define ENOTSUPP	ENOTSUP
#define ECHRNG		EINVAL
#define EHWPOISON	EIO

#endif
