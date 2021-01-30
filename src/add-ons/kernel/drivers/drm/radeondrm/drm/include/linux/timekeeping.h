/* Public domain. */

#ifndef _LINUX_TIMEKEEPING_H
#define _LINUX_TIMEKEEPING_H

#define ktime_get_boottime()	ktime_get()
#define get_seconds()		gettime()

inline time_t
ktime_get_real_seconds(void)
{
//	return gettime();
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline ktime_t
ktime_get_real(void)
{
	struct timespec ts;
	nanotime(&ts);
	return TIMESPEC_TO_NSEC(&ts);
}

inline uint64_t
ktime_get_ns(void)
{
//	return ktime_get();
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
