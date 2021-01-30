#ifndef HAIKU_DEFS_H
#define HAIKU_DEFS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u_int unsigned int

//./sys/param.h:62:
#define      MAXCOMLEN       16              /* max command name remembered */

// ./sys/errno.h:54
#define ENOMEM         12      /* Cannot allocate memory */

// ./sys/malloc.h:59:
#define       M_CANFAIL       0x0004

// ./sys/malloc.h:57:
#define       M_WAITOK        0x0001

// ./sys/malloc.h:58:
#define       M_NOWAIT        0x0002

// ./sys/malloc.h:182:
#define M_DRM                145     /* Direct Rendering Manager */

// ./sys/errno.h:66:
#define EINVAL         22      /* Invalid argument */

//./sys/sys/errno.h:43:
#define ENOENT             2       /* No such file or directory */

//sys/sys/errno.h:80:
#define ERANGE               34      /* Result too large */

//sys/sys/errno.h:72:
#define ENOSPC               28      /* No space left on device */

//sys/sys/errno.h:151:
#define ENOSYS              78      /* Function not implemented */

//sys/sys/errno.h:52:
#define EDEADLK              11      /* Resource deadlock avoided */

//sys/sys/errno.h:60:
#define EBUSY                16      /* Device busy */

//sys/sys/errno.h:83:
#define EAGAIN               35      /* Resource temporarily unavailable */

//sys/sys/errno.h:84:
#define EWOULDBLOCK  EAGAIN  /* Operation would block */

//sys/sys/errno.h:45:
#define EINTR                4       /* Interrupted system call */

//sys/sys/errno.h:180:
#define ERESTART    -1      /* restart syscall */

//sys/sys/errno.h
#define EFAULT               14      /* Bad address */

// sys/sys/errno.h:55:
#define EACCES               13      /* Permission denied */

// sys/sys/errno.h:98:
#define EOPNOTSUPP   45      /* Operation not supported */

// sys/sys/fcntl.h:107:
#define     O_CLOEXEC       0x10000         /* atomically set FD_CLOEXEC */

//sys/sys/errno.h:169:
#define ENOTSUP             91      /* Not supported */

//sys/sys/errno.h:63:
#define ENODEV               19      /* Operation not supported by device */

// sys/errno.h:47:
#define ENXIO            6       /* Device not configured */

// sys/errno.h:86:
#define EALREADY 37      /* Operation already in progress */

// sys/errno.h:42:
#define EPERM            1       /* Operation not permitted */

//sys/sys/errno.h:181
#define EJUSTRETURN -2      /* don't modify regs, just return */

//sys/sys/param.h:101:
#define     PZERO   22              /* No longer magic, shouldn't be here.  XXX */

// arch/amd64/include/param.h:52:
#define   PAGE_SHIFT      12

//arch/amd64/include/param.h:53:
#define   PAGE_SIZE       (1 << PAGE_SHIFT)

// arch/amd64/include/param.h:54:
#define   PAGE_MASK       (PAGE_SIZE - 1)

// ./sys/tree.h:306:
#define RB_RED         1

// ./arch/amd64/include/intrdefs.h:27:
#define      IPL_TTY         0x9     /* terminal */

// arch/amd64/include/intrdefs.h:21:
#define        IPL_NONE        0x0     /* nothing */

// sys/rwlock.h:117:
#define RW_NOSLEEP             0x0040UL /* don't wait for the lock */

// sys/rwlock.h:110:
#define RW_WRITE               0x0001UL /* exclusive lock */

// sys/errno.h:173:
#define EPROTO          95      /* Protocol error */

// sys/errno.h:46:
#define EIO              5       /* Input/output error */

// sys/errno.h:119:
#define ETIMEDOUT       60      /* Operation timed out */

// sys/param.h:111:
#define PCATCH          0x100   /* OR'd with pri for tsleep to check signals */

// ./sys/sys/select.h:69:
#define   __NBBY  8

// ./sys/sys/select.h:111:
#define  NBBY    __NBBY

// sys/sys/errno.h:48:
#define E2BIG                7       /* Argument list too long */

// sys/sys/errno.h:61:
#define EEXIST               17      /* File exists */

//
typedef uint64_t bus_addr_t;

// sys/arch/amd64/include/bus.h:78:
typedef u_long bus_size_t;

// ./arch/amd64/include/_types.h:122:
typedef long                  __ptrdiff_t;

// ./sys/arch/amd64/include/_types.h:115:
typedef unsigned long             __paddr_t;

// sys/sys/types.h:126:
typedef __paddr_t   paddr_t;

// ./sys/arch/amd64/include/pci_machdep.h:48:
typedef void *pci_chipset_tag_t;

// sys/arch/amd64/include/bus.h:563:
typedef struct bus_dma_segment bus_dma_segment_t;

// ./sys/arch/amd64/include/bus.h:561
/*
 *	bus_dma_segment_t
 *
 *	Describes a single contiguous DMA transaction.  Values
 *	are suitable for programming into DMA registers.
 */
struct bus_dma_segment {
	bus_addr_t	ds_addr;	/* DMA address */
	bus_size_t	ds_len;		/* length of transfer */
	/*
	 * Ugh. need this so can pass alignment down from bus_dmamem_alloc
	 * to scatter gather maps. only the first one is used so the rest is
	 * wasted space. bus_dma could do with fixing the api for this.
	 */
	 bus_size_t	_ds_boundary;	/* don't cross */
	 bus_size_t	_ds_align;	/* align to me */
};
typedef struct bus_dma_segment	bus_dma_segment_t;


// ./sys/arch/amd64/include/bus.h:646
/*
 *	bus_dmamap_t
 *
 *	Describes a DMA mapping.
 */
struct bus_dmamap {
	/*
	 * PRIVATE MEMBERS: not for use by machine-independent code.
	 */
	bus_size_t	_dm_size;	/* largest DMA transfer mappable */
	int		_dm_flags;	/* misc. flags */
	int		_dm_segcnt;	/* number of segs this map can map */
	bus_size_t	_dm_maxsegsz;	/* largest possible segment */
	bus_size_t	_dm_boundary;	/* don't cross this */

	void		*_dm_cookie;	/* cookie for bus-specific functions */

	/*
	 * PUBLIC MEMBERS: these are used by machine-independent code.
	 */
	bus_size_t	dm_mapsize;	/* size of the mapping */
	int		dm_nsegs;	/* # valid segments in mapping */
	bus_dma_segment_t dm_segs[1];	/* segments; variable length */
};

//./sys/arch/amd64/include/bus.h:544:
typedef struct bus_dmamap            *bus_dmamap_t;

// ./sys/arch/amd64/include/bus.h:543:
typedef struct bus_dma_tag           *bus_dma_tag_t;

// ./sys/arch/amd64/include/pci_machdep.h:49:
typedef u_int32_t pcitag_t;

// ./sys/arch/amd64/include/bus.h:78:
typedef u_long bus_size_t;

// ./sys/arch/amd64/include/bus.h:84:
typedef const struct x86_bus_space_ops *bus_space_tag_t;

// ./sys/arch/amd64/include/bus.h:563:
typedef struct bus_dma_segment       bus_dma_segment_t;

// ./sys/dev/pci/pcivar.h:54:
typedef u_int32_t pcireg_t;           /* configuration space register XXX */

// arch/amd64/include/bus.h:85:
typedef     u_long bus_space_handle_t;

// sys/sys/fcntl.h:64:
#define      O_RDWR          0x0002          /* open for reading and writing */

// 
typedef struct mutex {
} mutex;

// 
typedef struct rwlock {
} rwlock;

// 
typedef struct task {
} task;

// 
typedef struct timeout {
} timeout;

//
typedef struct agp_info {
} agp_info;

//
typedef struct klist {
} klist;

//
typedef struct pool {
} pool;

typedef struct selinfo {
} selinfo;

typedef struct cfattach {
} cfattach;

typedef struct wsscreen_descr {
} wsscreen_descr;

typedef struct wsscreen_list {
} wsscreen_list;

typedef struct wsdisplay_accessops {
} wsdisplay_accessops;

typedef struct cfdriver {
} cfdriver;

typedef struct wsemuldisplaydev_attach_args {
} wsemuldisplaydev_attach_args;


// sys/dev/i2c/i2c_io.h:45:
typedef uint16_t i2c_addr_t;

//./sys/dev/i2c/i2c_io.h:47
/* High-level I2C operations. */
#define	I2C_OPMASK_STOP		1
#define	I2C_OPMASK_WRITE	2
#define	I2C_OPMASK_BLKMODE	4

//./sys/dev/i2c/i2c_io.h:57
typedef enum {
	I2C_OP_READ		= 0,
	I2C_OP_READ_WITH_STOP	= I2C_OPMASK_STOP,
	I2C_OP_WRITE		= I2C_OPMASK_WRITE,
	I2C_OP_WRITE_WITH_STOP	= I2C_OPMASK_WRITE   | I2C_OPMASK_STOP,
	I2C_OP_READ_BLOCK	= I2C_OPMASK_BLKMODE | I2C_OPMASK_STOP,
	I2C_OP_WRITE_BLOCK	= I2C_OPMASK_BLKMODE | I2C_OPMASK_WRITE |
					I2C_OPMASK_STOP,
} i2c_op_t;

// sys/dev/i2c/i2cvar.h:62:
typedef struct i2c_controller {
	void	*ic_cookie;		/* controller private */

	/*
	 * These provide synchronization in the presence of
	 * multiple users of the i2c bus.  When a device
	 * driver wishes to perform transfers on the i2c
	 * bus, the driver should acquire the bus.  When
	 * the driver is finished, it should release the
	 * bus.
	 *
	 * This is provided by the back-end since a single
	 * controller may present e.g. i2c and smbus views
	 * of the same set of i2c wires.
	 */
	int	(*ic_acquire_bus)(void *, int);
	void	(*ic_release_bus)(void *, int);

	/*
	 * The preferred API for clients of the i2c interface
	 * is the scripted API.  This handles i2c controllers
	 * that do not provide raw access to the i2c signals.
	 */
	int	(*ic_exec)(void *, i2c_op_t, i2c_addr_t, const void *, size_t,
		    void *, size_t, int);

	int	(*ic_send_start)(void *, int);
	int	(*ic_send_stop)(void *, int);
	int	(*ic_initiate_xfer)(void *, i2c_addr_t, int);
	int	(*ic_read_byte)(void *, uint8_t *, int);
	int	(*ic_write_byte)(void *, uint8_t, int);

	void	*(*ic_intr_establish)(void *, void *, int, int (*)(void *),
		    void *, const char *);
	const char *(*ic_intr_string)(void *, void *);
} *i2c_tag_t;

// sys/dev/i2c/i2c_bitbang.h:46:
#define    I2C_NBITS               4

// sys/dev/i2c/i2c_bitbang.h:42:
#define    I2C_BIT_SDA             0       /* SDA signal */

// sys/dev/i2c/i2c_bitbang.h:43:
#define    I2C_BIT_SCL             1       /* SCL signal */

// sys/dev/i2c/i2c_bitbang.h:48
struct i2c_bitbang_ops {
	void		(*ibo_set_bits)(void *, uint32_t);
	void		(*ibo_set_dir)(void *, uint32_t);
	uint32_t	(*ibo_read_bits)(void *);
	uint32_t	ibo_bits[I2C_NBITS];
};

typedef struct cpu_info {
	int ci_inatomic; 
} cpu_info;

typedef struct uvm_object {
} uvm_object;

typedef struct proc_p_p {
	int ps_pid;
};

typedef struct proc {
	struct proc_p_p* p_p;
} proc;

typedef struct vm_page {
};

typedef struct bios_regs {
};

typedef struct {
	pcitag_t tag;
	int line, pin;
} pci_intr_handle_t;

typedef struct pci_softc {
} pci_softc;

// sys/device.h
typedef struct device {
	char	dv_xname[16];		/* external name (name + unit) */
	struct pci_softc* dv_parent;
};

typedef struct {
} taskqueue;

struct uvm_pagerops {
};

extern volatile struct proc* curproc;
extern volatile struct taskqueue* systq;
extern int cpu_ecxfeature;

#define __unused

#define     howmany(x, y)   (((x)+((y)-1))/(y))

#define __packed	 __attribute__((packed))

#define hz	0
#define ticks	0
#define cold	0

//sys/param.h:204:
#define nitems(_a)      (sizeof((_a)) / sizeof((_a)[0]))

// ./sys/arch/amd64/include/_types.h:116:
typedef unsigned long             __vsize_t;

// ./sys/sys/types.h:127:
typedef __vsize_t vsize_t;

// ./sys/uvm/uvm_extern.h:66:
typedef off_t voff_t;         /* XXX: offset within a uvm_object */

//
typedef bool boolean_t;

// sys/arch/amd64/include/_types.h:114:
typedef unsigned long               __vaddr_t;

// sys/sys/types.h:125:
typedef __vaddr_t   vaddr_t;

// ./sys/uvm/uvm_extern.h:75:
typedef struct vm_page  *vm_page_t;

//./sys/uvm/uvm_extern.h:63:
typedef int vm_fault_t;

//./sys/uvm/uvm_extern.h:97:
typedef int           vm_prot_t;

//
#define letoh32(x)	(x)
#define	letoh16(x)	(x)

// types
typedef int8_t   __s8;
typedef uint8_t  __u8;
typedef int16_t  __s16;
typedef uint16_t __u16;
typedef int32_t  __s32;
typedef uint32_t __u32;
typedef int64_t  __s64;
typedef uint64_t __u64;

typedef int8_t   s8;
typedef uint8_t  u8;
typedef int16_t  s16;
typedef uint16_t u16;
typedef int32_t  s32;
typedef uint32_t u32;
typedef int64_t  s64;
typedef uint64_t u64;

typedef uint16_t __le16; 
typedef uint16_t __be16; 
typedef uint32_t __le32; 
typedef uint32_t __be32;
typedef uint64_t __le64; 
typedef uint64_t __be64; 

//./dev/pci/pcidevs.h:111:
#define PCI_VENDOR_APPLE        0x106b          /* Apple */

//dev/pci/pcireg.h:619:
#define PCI_PCIE_LCSR2_TLS 0x0000000f

//dev/pci/pcireg.h:620:
#define PCI_PCIE_LCSR2_TLS_2_5     0x00000001

//dev/pci/pcireg.h:621:
#define PCI_PCIE_LCSR2_TLS_5       0x00000002

//dev/pci/pcireg.h:622:
#define PCI_PCIE_LCSR2_TLS_8       0x00000003

//dev/pci/pcireg.h:623:
#define PCI_PCIE_LCSR2_TLS_16      0x00000004

//dev/pci/pcireg.h:624:
#define PCI_PCIE_LCSR2_TLS_32      0x00000005

//./arch/amd64/include/bus.h:472:
#define  BUS_SPACE_BARRIER_READ  0x01            /* force read barrier */

//./arch/amd64/include/bus.h:473:
#define  BUS_SPACE_BARRIER_WRITE 0x02            /* force write barrier */

//sys/malloc.h:60:
#define M_ZERO          0x0008

//sys/rwlock.h:112:
#define RW_DOWNGRADE           0x0004UL /* downgrade exclusive to shared */

//./dev/wscons/wsconsio.h:536:
#define     WSDISPLAY_BURN_VBLANK   0x0001

//sys/dev/wscons/wsdisplayvar.h
struct wsdisplay_emulops {
	int	(*cursor)(void *c, int on, int row, int col);
	int	(*mapchar)(void *, int, unsigned int *);
	int	(*putchar)(void *c, int row, int col, u_int uc, uint32_t attr);
	int	(*copycols)(void *c, int row, int srccol, int dstcol,
		    int ncols);
	int	(*erasecols)(void *c, int row, int startcol, int ncols,
		    uint32_t);
	int	(*copyrows)(void *c, int srcrow, int dstrow, int nrows);
	int	(*eraserows)(void *c, int row, int nrows, uint32_t attr);
	int	(*pack_attr)(void *c, int fg, int bg, int flags,
		    uint32_t *attrp);
	void	(*unpack_attr)(void *c, uint32_t attr, int *fg, int *bg,
		    int *ul);
/* fg / bg values. Made identical to ANSI terminal color codes. */
#define WSCOL_BLACK	0
#define WSCOL_RED	1
#define WSCOL_GREEN	2
#define WSCOL_BROWN	3
#define WSCOL_BLUE	4
#define WSCOL_MAGENTA	5
#define WSCOL_CYAN	6
#define WSCOL_WHITE	7
/* flag values: */
#define WSATTR_REVERSE	1
#define WSATTR_HILIT	2
#define WSATTR_BLINK	4
#define WSATTR_UNDERLINE 8
#define WSATTR_WSCOLORS 16
};

//sys/dev/wscons/wsconsio.h:57:
#define    WSFONT_NAME_SIZE        32

//sys/dev/wscons/wsconsio.h:510
struct wsdisplay_font {
	char name[WSFONT_NAME_SIZE];
	int index;
#define WSDISPLAY_MAXFONTCOUNT	8
	int firstchar, numchars;
	int encoding;
#define WSDISPLAY_FONTENC_ISO 0
#define WSDISPLAY_FONTENC_IBM 1
	u_int fontwidth, fontheight, stride;
#define WSDISPLAY_MAXFONTSZ	(512*1024)
	int bitorder, byteorder;
#define	WSDISPLAY_FONTORDER_KNOWN	0	/* i.e, no need to convert */
#define	WSDISPLAY_FONTORDER_L2R		1
#define	WSDISPLAY_FONTORDER_R2L		2
	void *cookie;
	void *data;
};


//./dev/rasops/rasops.h
struct rasops_info {
	/* These must be filled in by the caller */
	int	ri_depth;	/* depth in bits */
	u_char	*ri_bits;	/* ptr to bits */
	int	ri_width;	/* width (pels) */
	int	ri_height;	/* height (pels) */
	int	ri_stride;	/* stride in bytes */

	void	*ri_hw;		/* driver private data; ignored by rasops */

	/*
	 * These are optional and will default if zero. Meaningless
	 * on depths other than 15, 16, 24 and 32 bits per pel. On
	 * 24 bit displays, ri_{r,g,b}num must be 8.
	 */
	u_char	ri_rnum;	/* number of bits for red */
	u_char	ri_gnum;	/* number of bits for green */
	u_char	ri_bnum;	/* number of bits for blue */
	u_char	ri_rpos;	/* which bit red starts at */
	u_char	ri_gpos;	/* which bit green starts at */
	u_char	ri_bpos;	/* which bit blue starts at */
};

//dev/pci/pcidevs.h:64:
#define    PCI_VENDOR_ATI  0x1002          /* ATI */

//./sys/memrange.h:33:
#define MDF_WRITECOMBINE    (1<<1)  /* region supports "write combine" action */

//uvm/uvm_extern.h:164:
#define    PHYSLOAD_DEVICE 0x01    /* don't add to the page queue */

//sys/pool.h:182:
#define PR_WAITOK        0x0001 /* M_WAITOK */

//sys/pool.h:185:
#define PR_ZERO          0x0008 /* M_ZERO */

//sys/errno.h:69:
#define ENOTTY           25      /* Inappropriate ioctl for device */

//arch/amd64/include/bus.h:526:
#define    BUS_DMA_NOCACHE         0x0800  /* map memory uncached */

//sys/rwlock.h:111:
#define RW_READ                        0x0002UL /* shared lock */

//arch/amd64/include/bus.h:493:
#define    BUS_SPACE_MAP_LINEAR            0x0002

//dev/pci/pcireg.h:467:
#define PCI_ROM_REG 0x30

//./dev/pci/pcireg.h:469:
#define PCI_ROM_ENABLE                   0x00000001

//dev/pci/pcidevs.h:1377:
#define  PCI_PRODUCT_ATI_RADEON_QY       0x5159          /* Radeon VE */

// sys/device.h:66:
#define DVACT_QUIESCE           2       /* warn the device about suspend */

// sys/device.h:67:
#define DVACT_SUSPEND           3       /* suspend the device */

// sys/device.h:68:
#define DVACT_RESUME            4       /* resume the device */

// sys/device.h:69:
#define DVACT_WAKEUP            5       /* tell device to recover after resume */

// dev/pci/pcireg.h:140:
#define    PCI_CLASS_DISPLAY                       0x03

// dev/pci/pcireg.h:189:
#define    PCI_SUBCLASS_DISPLAY_VGA                0x00

// dev/pci/pcireg.h:71:
#define     PCI_COMMAND_STATUS_REG                  0x04

// dev/pci/pcireg.h:73:
#define     PCI_COMMAND_IO_ENABLE                   0x00000001

// dev/pci/pcireg.h:74:
#define     PCI_COMMAND_MEM_ENABLE                  0x00000002

// dev/pci/pcireg.h:413:
#define    PCI_MAPREG_TYPE_MEM                     0x00000000

// dev/pci/pcireg.h:422:
#define PCI_MAPREG_MEM_TYPE_64BIT               0x00000004

// dev/pci/pcireg.h:404:
#define    PCI_MAPREG_START                0x10

// dev/pci/pcireg.h:405:
#define    PCI_MAPREG_END                  0x28

// dev/pci/pcireg.h:414:
#define    PCI_MAPREG_TYPE_IO                      0x00000001

// dev/pci/pcireg.h:487:
#define PCI_CAP_AGP                0x02

// dev/pci/pcireg.h:500:
#define PCI_CAP_PCIEXPRESS         0x10

// dev/pci/pcivar.h:167:
#define    PCI_FLAGS_MSI_ENABLED   0x20            /* Message Signaled Interrupt */

// arch/amd64/include/specialreg.h:181:
#define     CPUIDECX_HV     0x80000000      /* Running on hypervisor */

// arch/amd64/include/bus.h:515:
#define    BUS_DMA_WAITOK          0x0000  /* safe to sleep (pseudo-flag) */

#endif
