/*
 * Copyright 2007 Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Bek, host.haiku@gmx.de
 */
#include "driver.h"

int32 api_version = B_CUR_DRIVER_API_VERSION;
device_t device;

status_t
init_hardware(void)
{
	dprintf("radeondrm: %s\n", __func__);
	return B_OK;
}


status_t
init_driver(void)
{
	dprintf("radeondrm: %s\n", __func__);
	return B_OK;
}


void
uninit_driver(void)
{
}


const char**
publish_devices(void)
{
	static const char* published_paths[] = {
		"drm/radeon/0",
		NULL
	};
	dprintf("radeondrm: %s\n", __func__);

	return published_paths;
}


static status_t
radeondrm_open (const char *name, uint32 flags, void** cookie)
{
	dprintf("radeondrm: %s\n" , __func__ );
	*cookie = &device;
	return B_OK;
}


static status_t
radeondrm_read (void* cookie, off_t a, void* b, size_t* num_bytes)
{
	dprintf("radeondrm: %s\n" , __func__ );
	*num_bytes = 0;
	return B_IO_ERROR;
}


static status_t
radeondrm_write (void* cookie, off_t a, const void* b, size_t* num_bytes)
{
	dprintf("radeondrm: %s\n" , __func__ );
	*num_bytes = 0;
	return B_IO_ERROR;
}

static status_t
radeondrm_close (void* cookie)
{
	device_t* device = (device_t*) cookie;
	dprintf("radeondrm: %s\n" , __func__ );
	return B_OK;
}


static status_t
radeondrm_free (void* cookie)
{
	dprintf("radeondrm: %s\n" , __func__ );
	return B_OK;
}

device_hooks driver_hooks = {
	radeondrm_open,
	radeondrm_close,
	radeondrm_free,
	radeondrm_read,
	radeondrm_write
};


device_hooks*
find_device(const char* name)
{
	return &driver_hooks;
}

