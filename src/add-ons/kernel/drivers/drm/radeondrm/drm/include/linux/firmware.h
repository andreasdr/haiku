/* Public domain. */

#ifndef _LINUX_FIRMWARE_H
#define _LINUX_FIRMWARE_H

#include <haiku-defs.h>
//#include <sys/types.h>
//#include <sys/malloc.h>
//#include <sys/device.h>
#include <linux/types.h>
#include <linux/gfp.h>

#ifndef __DECONST
#define __DECONST(type, var)	((type)(__uintptr_t)(const void *)(var))
#endif

struct firmware {
	size_t size;
	const u8 *data;
};

inline int
request_firmware(const struct firmware **fw, const char *name,
    struct device *device)
{
//	int r;
//	struct firmware *f = malloc(sizeof(struct firmware), M_DRM,
//	    M_WAITOK | M_ZERO);
//	r = loadfirmware(name, __DECONST(u_char **, &f->data), &f->size);
//	if (r != 0) {
//		free(f, M_DRM, sizeof(struct firmware));
//		*fw = NULL;
//		return -r;
//	} else  {
//		*fw = f;
//		return 0;
//	}
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int
request_firmware_direct(const struct firmware **fw, const char *name,
    struct device *device)
{
	return request_firmware(fw, name, device);
}

#define request_firmware_nowait(a, b, c, d, e, f, g) -EINVAL

inline void
release_firmware(const struct firmware *fw)
{
//	if (fw)
//		free(__DECONST(u_char *, fw->data), M_DEVBUF, fw->size);
//	free(__DECONST(struct firmware *, fw), M_DRM, sizeof(*fw));
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
