/* Public domain. */

#ifndef _LINUX_SYSRQ_H
#define _LINUX_SYSRQ_H

struct sysrq_key_op {
};

inline int
register_sysrq_key(int k, struct sysrq_key_op *op)
{
//	return 0;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int
unregister_sysrq_key(int k, struct sysrq_key_op *op)
{
//	return 0;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
