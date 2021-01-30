/* Public domain. */

#ifndef _LINUX_IRQFLAGS_H
#define _LINUX_IRQFLAGS_H

#include <haiku-defs.h>
//#include <machine/intr.h>

#define local_irq_save(x)	(x) = splhigh()
#define local_irq_restore(x)	splx((x))

#define local_irq_disable()	intr_disable()
#define local_irq_enable()	intr_enable()

inline int
irqs_disabled(void)
{
//	/* XXX not quite true */
//	return (1);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
