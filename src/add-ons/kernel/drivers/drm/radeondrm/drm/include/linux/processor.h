/* Public domain. */

#ifndef _LINUX_PROCESSOR_H
#define _LINUX_PROCESSOR_H

#include <haiku-defs.h>
//#include <sys/systm.h>
/* sparc64 cpu.h needs time.h and siginfo.h (indirect via param.h) */
//#include <sys/param.h>
//#include <machine/cpu.h>
#include <linux/jiffies.h>

inline void
cpu_relax(void)
{
//	CPU_BUSY_CYCLE();
//	if (cold) {
//		delay(tick);
//		jiffies++;
//	}
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
