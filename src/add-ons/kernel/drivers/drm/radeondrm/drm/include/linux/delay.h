/* Public domain. */

#ifndef _LINUX_DELAY_H
#define _LINUX_DELAY_H

#include <haiku-defs.h>
//#include <sys/param.h>

inline void
udelay(unsigned long usecs)
{
//	DELAY(usecs);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
ndelay(unsigned long nsecs)
{
//	DELAY(MAX(nsecs / 1000, 1));
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
usleep_range(unsigned long min, unsigned long max)
{
//	DELAY((min + max) / 2);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
mdelay(unsigned long msecs)
{
//	int loops = msecs;
//	while (loops--)
//		DELAY(1000);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#define drm_msleep(x)		mdelay(x)

#endif
