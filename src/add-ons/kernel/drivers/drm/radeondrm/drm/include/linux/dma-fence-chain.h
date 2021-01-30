/* Public domain. */

#ifndef _LINUX_DMA_FENCE_CHAIN_H
#define _LINUX_DMA_FENCE_CHAIN_H

#include <haiku-defs.h>
#include <linux/dma-fence.h>

struct dma_fence_chain {
	struct dma_fence base;
	struct dma_fence *fence;
	struct dma_fence *prev;
	uint64_t prev_seqno;
};

inline int
dma_fence_chain_find_seqno(struct dma_fence **df, uint64_t seqno)
{
//	if (seqno == 0)
//		return 0;
//	STUB();
//	return -ENOSYS;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline struct dma_fence_chain *
to_dma_fence_chain(struct dma_fence *fence)
{
//	STUB();
//	return NULL;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#define dma_fence_chain_for_each(a, b)

inline void
dma_fence_chain_init(struct dma_fence_chain *chain, struct dma_fence *prev,
    struct dma_fence *fence, uint64_t seqno)
{
	chain->fence = fence;
	chain->prev = prev;
	chain->prev_seqno = 0;
}

#endif
