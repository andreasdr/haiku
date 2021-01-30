/* Public domain. */

#ifndef _LINUX_KGDB_H
#define _LINUX_KGDB_H

#include <haiku-defs.h>
//#include <sys/types.h>
//#include <sys/systm.h>

inline int
in_dbg_master(void)
{
//#ifdef DDB
//	return (db_active);
//#endif
//	return (0);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
