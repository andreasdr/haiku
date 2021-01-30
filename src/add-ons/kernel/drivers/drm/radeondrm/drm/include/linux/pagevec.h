/* Public domain. */

#ifndef _LINUX_PAGEVEC_H
#define _LINUX_PAGEVEC_H

#include <haiku-defs.h>
//#include <sys/types.h>
//#include <sys/systm.h>
//#include <sys/errno.h>

#define PAGEVEC_SIZE 15

struct pagevec {
	uint8_t	nr;
	struct vm_page *pages[PAGEVEC_SIZE];
};

void __pagevec_release(struct pagevec *);

inline unsigned int
pagevec_space(struct pagevec *pvec)
{
//	return PAGEVEC_SIZE - pvec->nr;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
pagevec_init(struct pagevec *pvec)
{
//	pvec->nr = 0;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
pagevec_reinit(struct pagevec *pvec)
{
//	pvec->nr = 0;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline unsigned int
pagevec_count(struct pagevec *pvec)
{
//	return pvec->nr;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline unsigned int
pagevec_add(struct pagevec *pvec, struct vm_page *page)
{
//	pvec->pages[pvec->nr++] = page;
//	return PAGEVEC_SIZE - pvec->nr;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
