/* Public domain. */

#ifndef _DRM_WRITEBACK_H
#define _DRM_WRITEBACK_H

#include <haiku-defs.h>
#include <drm/drm_connector.h>

struct drm_writeback_connector {
	struct drm_connector base;
};

struct drm_writeback_job {
	struct dma_fence *out_fence;
	struct drm_framebuffer *fb;
};

inline struct drm_writeback_connector *
drm_connector_to_writeback(struct drm_connector *connector)
{
//	return container_of(connector, struct drm_writeback_connector, base);
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline struct dma_fence *
drm_writeback_get_out_fence(struct drm_writeback_connector *connector)
{
//	return NULL;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
drm_writeback_cleanup_job(struct drm_writeback_job *j)
{
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int
drm_writeback_prepare_job(struct drm_writeback_job *j)
{
//	return 0;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int
drm_writeback_set_fb(struct drm_connector_state *cs, struct drm_framebuffer *fb)
{
//	return 0;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
