/* Public domain. */

#ifndef _LINUX_SLAB_H
#define _LINUX_SLAB_H

#include <haiku-defs.h>
//#include <sys/types.h>
//#include <sys/malloc.h>

#include <linux/types.h>
#include <linux/workqueue.h>
#include <linux/gfp.h>

inline void *
kmalloc(size_t size, int flags)
{
//	return malloc(size, M_DRM, flags);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void *
kmalloc_array(size_t n, size_t size, int flags)
{
//	if (n != 0 && SIZE_MAX / n < size)
//		return NULL;
//	return malloc(n * size, M_DRM, flags);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void *
kcalloc(size_t n, size_t size, int flags)
{
//	if (n != 0 && SIZE_MAX / n < size)
//		return NULL;
//	return malloc(n * size, M_DRM, flags | M_ZERO);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void *
kzalloc(size_t size, int flags)
{
//	return malloc(size, M_DRM, flags | M_ZERO);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
kfree(const void *objp)
{
//	free((void *)objp, M_DRM, 0);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
