/*	$OpenBSD: ktime.h,v 1.5 2020/07/29 09:52:21 jsg Exp $	*/
/*
 * Copyright (c) 2013, 2014, 2015 Mark Kettenis
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _LINUX_KTIME_H
#define _LINUX_KTIME_H

#include <haiku-defs.h>
//#include <sys/time.h>
#include <linux/time.h>
#include <linux/jiffies.h>

typedef int64_t ktime_t;

inline ktime_t
ktime_get(void)
{
//	struct timespec ts;
//	nanouptime(&ts);
//	return TIMESPEC_TO_NSEC(&ts);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline ktime_t
ktime_get_raw(void)
{
//	struct timespec ts;
//	nanouptime(&ts);
//	return TIMESPEC_TO_NSEC(&ts);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int64_t
ktime_to_ms(ktime_t k)
{
//	return k / NSEC_PER_MSEC;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int64_t
ktime_to_us(ktime_t k)
{
//	return k / NSEC_PER_USEC;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int64_t
ktime_to_ns(ktime_t k)
{
//	return k;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int64_t
ktime_get_raw_ns(void)
{
//	return ktime_to_ns(ktime_get_raw());
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline struct timespec64
ktime_to_timespec64(ktime_t k)
{
//	struct timespec64 ts;
//	ts.tv_sec = k / NSEC_PER_SEC;
//	ts.tv_nsec = k % NSEC_PER_SEC;
//	if (ts.tv_nsec < 0) {
//		ts.tv_sec--;
//		ts.tv_nsec += NSEC_PER_SEC;
//	}
//	return ts;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline ktime_t
ktime_sub(ktime_t a, ktime_t b)
{
//	return a - b;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline ktime_t
ktime_add(ktime_t a, ktime_t b)
{
//	return a + b;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline ktime_t
ktime_add_us(ktime_t k, uint64_t us)
{
//	return k + (us * NSEC_PER_USEC);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline ktime_t
ktime_add_ns(ktime_t k, int64_t ns)
{
//	return k + ns;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline ktime_t
ktime_sub_ns(ktime_t k, int64_t ns)
{
//	return k - ns;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int64_t
ktime_us_delta(ktime_t a, ktime_t b)
{
//	return ktime_to_us(ktime_sub(a, b));
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int64_t
ktime_ms_delta(ktime_t a, ktime_t b)
{
//	return ktime_to_ms(ktime_sub(a, b));
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline bool
ktime_after(ktime_t a, ktime_t b)
{
//	return a > b;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline ktime_t
ns_to_ktime(uint64_t ns)
{
//	return ns;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#include <linux/timekeeping.h>

#endif
