/* Public domain. */

#ifndef _ASM_PGTABLE_H
#define _ASM_PGTABLE_H

#include <haiku-defs.h>
//#include <machine/pmap.h>
//#include <machine/pte.h>
#include <linux/types.h>

#define pgprot_val(v)	(v)
#define PAGE_KERNEL	0
#define PAGE_KERNEL_IO	0

inline pgprot_t
pgprot_writecombine(pgprot_t prot)
{
//#if PMAP_WC != 0
//	return prot | PMAP_WC;
//#else
//	return prot | PMAP_NOCACHE;
//#endif
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline pgprot_t
pgprot_noncached(pgprot_t prot)
{
//#if PMAP_DEVICE != 0
//	return prot | PMAP_DEVICE;
//#else
//	return prot | PMAP_NOCACHE;
//#endif
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#if defined(__i386__) || defined(__amd64__)
#define _PAGE_PRESENT	PG_V
#define _PAGE_RW	PG_RW
#define _PAGE_PAT	PG_PAT
#define _PAGE_PWT	PG_WT
#define _PAGE_PCD	PG_N
#endif

#endif
