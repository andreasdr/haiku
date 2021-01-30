/* Public domain. */

#ifndef _LINUX_MM_H
#define _LINUX_MM_H

#include <haiku-defs.h>
//#include <sys/types.h>
//#include <sys/param.h>
//#include <sys/malloc.h>
//#include <sys/stdint.h>
//#include <sys/atomic.h>
//#include <machine/cpu.h>
//#include <uvm/uvm_extern.h>
#include <linux/fs.h>
#include <linux/shrinker.h>
#include <linux/overflow.h>
#include <asm/pgtable.h>

#define PageHighMem(x)	0

#define page_address(x)		VM_PAGE_TO_PHYS(x)
#define page_to_phys(page)	(VM_PAGE_TO_PHYS(page))
#define page_to_pfn(pp)		(VM_PAGE_TO_PHYS(pp) / PAGE_SIZE)
#define pfn_to_page(pfn)	(PHYS_TO_VM_PAGE(ptoa(pfn)))
#define nth_page(page, n)	(&(page)[(n)])
#define offset_in_page(off)	((vaddr_t)(off) & PAGE_MASK)
#define set_page_dirty(page)	atomic_clearbits_int(&page->pg_flags, PG_CLEAN)

#define PAGE_ALIGN(addr)	(((addr) + PAGE_MASK) & ~PAGE_MASK)

#define PFN_UP(x)		(((x) + PAGE_SIZE-1) >> PAGE_SHIFT)
#define PFN_DOWN(x)		((x) >> PAGE_SHIFT)
#define PFN_PHYS(x)		((x) << PAGE_SHIFT)

#define is_vmalloc_addr(ptr)	true

inline void *
kvmalloc(size_t size, gfp_t flags)
{
//	return malloc(size, M_DRM, flags);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void *
kvmalloc_array(size_t n, size_t size, int flags)
{
//	if (n != 0 && SIZE_MAX / n < size)
//		return NULL;
//	return malloc(n * size, M_DRM, flags);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void *
kvcalloc(size_t n, size_t size, int flags)
{
//	return kvmalloc_array(n, size, flags | M_ZERO);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void *
kvzalloc(size_t size, int flags)
{
//	return malloc(size, M_DRM, flags | M_ZERO);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
kvfree(const void *objp)
{
//	free((void *)objp, M_DRM, 0);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline long
si_mem_available(void)
{
//	return uvmexp.free;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#define MAX_ORDER	11

inline unsigned int
get_order(size_t size)
{
//	return flsl((size - 1) >> PAGE_SHIFT);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
