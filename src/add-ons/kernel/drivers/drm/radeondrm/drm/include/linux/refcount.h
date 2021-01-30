/* Public domain. */

#ifndef _LINUX_REFCOUNT_H
#define _LINUX_REFCOUNT_H

#include <haiku-defs.h>
//#include <sys/types.h>
#include <linux/atomic.h>

typedef atomic_t refcount_t;

inline bool
refcount_dec_and_test(uint32_t *p)
{
	return atomic_dec_and_test(p);
}

inline bool
refcount_inc_not_zero(uint32_t *p)
{
//	return atomic_inc_not_zero(p);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
refcount_set(uint32_t *p, int v)
{
//	atomic_set(p, v);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline bool
refcount_dec_and_lock_irqsave(volatile int *v, struct mutex *lock,
    unsigned long *flags)
{
//	if (atomic_add_unless(v, -1, 1))
//		return false;
//
//	mtx_enter(lock);
//	if (atomic_dec_return(v) == 0)
//		return true;
//	mtx_leave(lock);
//	return false;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
