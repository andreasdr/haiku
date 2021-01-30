/* Public domain. */

#ifndef _LINUX_IOPORT_H
#define _LINUX_IOPORT_H

#include <haiku-defs.h>
//#include <sys/types.h>

struct resource {
	u_long	start;
	u_long	end;
};

inline resource_size_t
resource_size(const struct resource *r)
{
//	return r->end - r->start + 1;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#define DEFINE_RES_MEM(_start, _size)		\
	{					\
		.start = (_start),		\
		.end = (_start) + (_size) - 1,	\
	}

#endif
