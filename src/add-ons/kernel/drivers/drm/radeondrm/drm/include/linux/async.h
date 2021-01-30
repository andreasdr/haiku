/* Public domain. */

#ifndef _LINUX_ASYNC_H
#define _LINUX_ASYNC_H

#include <haiku-defs.h>
//#include <sys/types.h>

typedef uint64_t async_cookie_t;
typedef void (*async_func_t) (void *, async_cookie_t);

inline async_cookie_t
async_schedule(async_func_t func, void *data)
{
	func(data, 0);
	return 0;
}

#endif
