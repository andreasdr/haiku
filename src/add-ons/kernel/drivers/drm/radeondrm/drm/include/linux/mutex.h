/* Public domain. */

#ifndef _LINUX_MUTEX_H
#define _LINUX_MUTEX_H

#include <haiku-defs.h>
//#include <sys/stdint.h>
//#include <sys/rwlock.h>
#include <linux/list.h>
#include <linux/spinlock_types.h>

#define DEFINE_MUTEX(x)		struct rwlock x

#define mutex_lock_interruptible_nested(rwl, subc) \
					mutex_lock_interruptible(rwl)
#define mutex_lock(rwl)			rw_enter_write(rwl)
#define mutex_lock_nest_lock(rwl, sub)	rw_enter_write(rwl)
#define mutex_lock_nested(rwl, sub)	rw_enter_write(rwl)
#define mutex_trylock(rwl)		(rw_enter(rwl, RW_WRITE | RW_NOSLEEP) == 0)
#define mutex_unlock(rwl)		rw_exit_write(rwl)
#define mutex_is_locked(rwl)		(rw_status(rwl) != 0)
#define mutex_destroy(rwl)

inline int
mutex_lock_interruptible(struct rwlock *rwl)
{
//	if (rw_enter(rwl, RW_WRITE | RW_INTR) != 0)
//		return -EINTR;
//	return 0;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

enum mutex_trylock_recursive_result {
	MUTEX_TRYLOCK_FAILED,
	MUTEX_TRYLOCK_SUCCESS,
	MUTEX_TRYLOCK_RECURSIVE
};

inline enum mutex_trylock_recursive_result
mutex_trylock_recursive(struct rwlock *rwl)
{
//	if (rw_status(rwl) == RW_WRITE)
//		return MUTEX_TRYLOCK_RECURSIVE;
//	if (mutex_trylock(rwl))
//		return MUTEX_TRYLOCK_SUCCESS;
//	return MUTEX_TRYLOCK_FAILED;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

int atomic_dec_and_mutex_lock(volatile int *, struct rwlock *);

#endif
