/* Public domain. */

#ifndef _ASM_CPUFEATURE_H
#define _ASM_CPUFEATURE_H

#if defined(__amd64__) || defined(__i386__)

#define X86_FEATURE_CLFLUSH	1
#define X86_FEATURE_XMM4_1	2
#define X86_FEATURE_PAT		3
#define X86_FEATURE_HYPERVISOR	4

inline bool
static_cpu_has(uint16_t f)
{
//	switch (f) {
//	case X86_FEATURE_CLFLUSH:
//		return curcpu()->ci_cflushsz != 0;
//	case X86_FEATURE_XMM4_1:
//		return (cpu_ecxfeature & CPUIDECX_SSE41) != 0;
//	case X86_FEATURE_PAT:
//		return (curcpu()->ci_feature_flags & CPUID_PAT) != 0;
//	case X86_FEATURE_HYPERVISOR:
//		return (cpu_ecxfeature & CPUIDECX_HV) != 0;
//	default:
//		return false;
//	}
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#define boot_cpu_has(x) static_cpu_has(x)

inline void
clflushopt(volatile void *addr)
{
//	if (curcpu()->ci_feature_sefflags_ebx & SEFF0EBX_CLFLUSHOPT)
//		__asm volatile("clflushopt %0" : "+m" (*(volatile char *)addr));
//	else
//		__asm volatile("clflush %0" : "+m" (*(volatile char *)addr));
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif

#endif
