/* Public domain. */

#ifndef _LINUX_VGAARB_H
#define _LINUX_VGAARB_H

#include <haiku-defs.h>
//#include <sys/errno.h>

#define VGA_RSRC_LEGACY_IO	0x01

struct pci_dev;

void vga_get_uninterruptible(struct pci_dev *, int);
void vga_put(struct pci_dev *, int);

inline int
vga_client_register(struct pci_dev *a, void *b, void *c, void *d)
{
	return -ENODEV;
}

inline int
vga_remove_vgacon(struct pci_dev *a)
{
//	return 0;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
