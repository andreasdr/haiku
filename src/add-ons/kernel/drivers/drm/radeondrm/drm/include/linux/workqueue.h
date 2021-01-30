/*	$OpenBSD: workqueue.h,v 1.3 2020/06/08 04:48:15 jsg Exp $	*/
/*
 * Copyright (c) 2015 Mark Kettenis
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

#ifndef _LINUX_WORKQUEUE_H
#define _LINUX_WORKQUEUE_H

#include <haiku-defs.h>
//#include <sys/param.h>
//#include <sys/systm.h>
//#include <sys/task.h>
//#include <sys/timeout.h>
#include <linux/bitops.h>
#include <linux/atomic.h>
#include <linux/rcupdate.h>
#include <linux/kernel.h>
#include <linux/lockdep.h>
#include <linux/timer.h>

struct workqueue_struct;

extern struct workqueue_struct *system_wq;
extern struct workqueue_struct *system_highpri_wq;
extern struct workqueue_struct *system_unbound_wq;
extern struct workqueue_struct *system_long_wq;

#define WQ_HIGHPRI	1
#define WQ_FREEZABLE	2
#define WQ_UNBOUND	4

#define WQ_UNBOUND_MAX_ACTIVE	4	/* matches nthreads in drm_linux.c */

inline struct workqueue_struct *
alloc_workqueue(const char *name, int flags, int max_active)
{
//	struct taskq *tq = taskq_create(name, 1, IPL_TTY, 0);
//	return (struct workqueue_struct *)tq;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline struct workqueue_struct *
alloc_ordered_workqueue(const char *name, int flags)
{
//	struct taskq *tq = taskq_create(name, 1, IPL_TTY, 0);
//	return (struct workqueue_struct *)tq;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline struct workqueue_struct *
create_singlethread_workqueue(const char *name)
{
//	struct taskq *tq = taskq_create(name, 1, IPL_TTY, 0);
//	return (struct workqueue_struct *)tq;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
destroy_workqueue(struct workqueue_struct *wq)
{
//	taskq_destroy((struct taskq *)wq);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

struct work_struct {
	struct task task;
	struct taskq *tq;
};

typedef void (*work_func_t)(struct work_struct *);

inline void
INIT_WORK(struct work_struct *work, work_func_t func)
{
//	work->tq = (struct taskq *)system_wq;
//	task_set(&work->task, (void (*)(void *))func, work);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#define INIT_WORK_ONSTACK(x, y)	INIT_WORK((x), (y))

inline bool
queue_work(struct workqueue_struct *wq, struct work_struct *work)
{
//	work->tq = (struct taskq *)wq;
//	return task_add(work->tq, &work->task);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
cancel_work_sync(struct work_struct *work)
{
//	task_del(work->tq, &work->task);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#define work_pending(work)	task_pending(&(work)->task)

struct delayed_work {
	struct work_struct work;
	struct timeout to;
	struct taskq *tq;
};

#define system_power_efficient_wq ((struct workqueue_struct *)systq)

inline struct delayed_work *
to_delayed_work(struct work_struct *work)
{
//	return container_of(work, struct delayed_work, work);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

void
__delayed_work_tick(void *arg)
{
//	struct delayed_work *dwork = arg;
//
//	task_add(dwork->tq, &dwork->work.task);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
INIT_DELAYED_WORK(struct delayed_work *dwork, work_func_t func)
{
//	INIT_WORK(&dwork->work, func);
//	timeout_set(&dwork->to, __delayed_work_tick, &dwork->work);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
INIT_DELAYED_WORK_ONSTACK(struct delayed_work *dwork, work_func_t func)
{
//	INIT_WORK(&dwork->work, func);
//	timeout_set(&dwork->to, __delayed_work_tick, &dwork->work);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline bool
schedule_work(struct work_struct *work)
{
//	return task_add(work->tq, &work->task);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline bool
schedule_delayed_work(struct delayed_work *dwork, int jiffies)
{
//	dwork->tq = (struct taskq *)system_wq;
//	return timeout_add(&dwork->to, jiffies);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline bool
queue_delayed_work(struct workqueue_struct *wq,
    struct delayed_work *dwork, int jiffies)
{
//	dwork->tq = (struct taskq *)wq;
//	return timeout_add(&dwork->to, jiffies);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline bool
mod_delayed_work(struct workqueue_struct *wq,
    struct delayed_work *dwork, int jiffies)
{
//	dwork->tq = (struct taskq *)wq;
//	return (timeout_add(&dwork->to, jiffies) == 0);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline bool
cancel_delayed_work(struct delayed_work *dwork)
{
//	if (timeout_del(&dwork->to))
//		return true;
//	return task_del(dwork->tq, &dwork->work.task);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline bool
cancel_delayed_work_sync(struct delayed_work *dwork)
{
//	if (timeout_del(&dwork->to))
//		return true;
//	return task_del(dwork->tq, &dwork->work.task);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline bool
delayed_work_pending(struct delayed_work *dwork)
{
//	if (timeout_pending(&dwork->to))
//		return true;
//	return task_pending(&dwork->work.task);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

void flush_workqueue(struct workqueue_struct *);
bool flush_work(struct work_struct *);
bool flush_delayed_work(struct delayed_work *);
#define flush_scheduled_work()	flush_workqueue(system_wq)
#define drain_workqueue(x)	flush_workqueue(x)

#define destroy_work_on_stack(x)
#define destroy_delayed_work_on_stack(x)

struct rcu_work {
	struct work_struct work;
	struct rcu_head rcu;
};

inline void
INIT_RCU_WORK(struct rcu_work *work, work_func_t func)
{
//	INIT_WORK(&work->work, func);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline bool
queue_rcu_work(struct workqueue_struct *wq, struct rcu_work *work)
{
//	return queue_work(wq, &work->work);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
