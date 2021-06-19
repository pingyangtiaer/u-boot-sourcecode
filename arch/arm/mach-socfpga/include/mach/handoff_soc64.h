/* SPDX-License-Identifier: GPL-2.0
 *
 * Copyright (C) 2016-2020 Intel Corporation <www.intel.com>
 *
 */

#ifndef _HANDOFF_SOC64_H_
#define _HANDOFF_SOC64_H_

/*
 * Offset for HW handoff from Quartus tools
 */
/* HPS handoff */
#define SOC64_HANDOFF_MAGIC_BOOT	0x424F4F54
#define SOC64_HANDOFF_MAGIC_MUX	0x504D5558
#define SOC64_HANDOFF_MAGIC_IOCTL	0x494F4354
#define SOC64_HANDOFF_MAGIC_FPGA	0x46504741
#define SOC64_HANDOFF_MAGIC_DELAY	0x444C4159
#define SOC64_HANDOFF_MAGIC_CLOCK	0x434C4B53
#define SOC64_HANDOFF_MAGIC_MISC	0x4D495343

#define SOC64_HANDOFF_OFFSET_LENGTH	0x4
#define SOC64_HANDOFF_OFFSET_DATA	0x10
#define SOC64_HANDOFF_SIZE		4096

#define SOC64_HANDOFF_BASE		0xFFE3F000
#define SOC64_HANDOFF_MISC		(SOC64_HANDOFF_BASE + 0x610)
#define SOC64_HANDOFF_MUX		(SOC64_HANDOFF_BASE + 0x10)
#define SOC64_HANDOFF_IOCTL		(SOC64_HANDOFF_BASE + 0x1A0)
#define SOC64_HANDOFF_FPGA		(SOC64_HANDOFF_BASE + 0x330)
#define SOC64_HANDOFF_DELAY		(SOC64_HANDOFF_BASE + 0x3F0)
#define SOC64_HANDOFF_CLOCK		(SOC64_HANDOFF_BASE + 0x580)

#if IS_ENABLED(CONFIG_TARGET_SOCFPGA_STRATIX10)
#define SOC64_HANDOFF_CLOCK_OSC	(SOC64_HANDOFF_BASE + 0x608)
#define SOC64_HANDOFF_CLOCK_FPGA	(SOC64_HANDOFF_BASE + 0x60C)
#else
#define SOC64_HANDOFF_CLOCK_OSC	(SOC64_HANDOFF_BASE + 0x5fc)
#define SOC64_HANDOFF_CLOCK_FPGA	(SOC64_HANDOFF_BASE + 0x600)
#endif

#define SOC64_HANDOFF_MUX_LEN			96
#define SOC64_HANDOFF_IOCTL_LEN			96
#if IS_ENABLED(CONFIG_TARGET_SOCFPGA_STRATIX10)
#define SOC64_HANDOFF_FPGA_LEN			42
#else
#define SOC64_HANDOFF_FPGA_LEN			40
#endif
#define SOC64_HANDOFF_DELAY_LEN			96

#ifndef __ASSEMBLY__
#include <asm/types.h>
enum endianness {
	LITTLE_ENDIAN = 0,
	BIG_ENDIAN
};

int socfpga_get_handoff_size(void *handoff_address, enum endianness endian);
int socfpga_handoff_read(void *handoff_address, void *table, u32 table_len,
			 enum endianness big_endian);
#endif
#endif /* _HANDOFF_SOC64_H_ */
