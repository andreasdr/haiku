/* Public domain. */

#ifndef _LINUX_OF_H
#define _LINUX_OF_H

#ifdef __macppc__
inline int
of_machine_is_compatible(const char *model)
{
//	extern char *hw_prod;
//	return (strcmp(model, hw_prod) == 0);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}
#endif

#endif
