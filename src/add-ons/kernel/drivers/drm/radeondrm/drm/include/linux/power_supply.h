/* Public domain. */

#ifndef _LINUX_POWER_SUPPLY_H
#define _LINUX_POWER_SUPPLY_H

inline int
power_supply_is_system_supplied(void)
{
//	/* XXX return 0 if on battery */
//	return (1);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
