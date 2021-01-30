/* Public domain. */

#ifndef _LINUX_CAPABILITY_H
#define _LINUX_CAPABILITY_H

#include <haiku-defs.h>
//#include <sys/param.h>
//#include <sys/systm.h>
//#include <sys/ucred.h>
//#include <machine/cpu.h>

#define CAP_SYS_ADMIN	0x1
inline int 
capable(int cap) 
{ 
//	KASSERT(cap == CAP_SYS_ADMIN);
//	return suser(curproc) == 0;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
} 

#endif
