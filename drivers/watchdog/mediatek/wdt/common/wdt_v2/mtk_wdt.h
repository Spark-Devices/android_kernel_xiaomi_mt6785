/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __WDT_HW_H__
#define __WDT_HW_H__

#define MTK_WDT_BASE			toprgu_base

#define MTK_WDT_MODE			(MTK_WDT_BASE+0x0000)
#define MTK_WDT_IRQ_CLR			(MTK_WDT_MODE)
#define MTK_WDT_LENGTH			(MTK_WDT_BASE+0x0004)
#define MTK_WDT_RESTART			(MTK_WDT_BASE+0x0008)
#define MTK_WDT_STATUS			(MTK_WDT_BASE+0x000C)
#define MTK_WDT_INTERVAL		(MTK_WDT_BASE+0x0010)
#define MTK_WDT_SWRST			(MTK_WDT_BASE+0x0014)
#define MTK_WDT_SWSYSRST		(MTK_WDT_BASE+0x0018)
#define MTK_WDT_NONRST_REG		(MTK_WDT_BASE+0x0020)
#define MTK_WDT_NONRST_REG2		(MTK_WDT_BASE+0x0024)
#define MTK_WDT_REQ_MODE		(MTK_WDT_BASE+0x0030)
#define MTK_WDT_REQ_IRQ_EN		(MTK_WDT_BASE+0x0034)
#define MTK_WDT_EXT_REQ_CON		(MTK_WDT_BASE+0x0038)
#define MTK_WDT_DEBUG_CTL		(MTK_WDT_BASE+0x0040)
#define MTK_WDT_DEBUG_CTL2		(MTK_WDT_BASE+0x00A0)
#define MTK_WDT_LATCH_CTL		(MTK_WDT_BASE+0x0044)
#define MTK_WDT_LATCH_CTL2		(MTK_WDT_BASE+0x0048)
#define MTK_WDT_RSTDEG_EN1		(MTK_WDT_BASE+0x0080)
#define MTK_WDT_RSTDEG_EN2		(MTK_WDT_BASE+0x0084)
#define MTK_WDT_SYSDBG_DEG_EN1	(MTK_WDT_BASE+0x0088)
#define MTK_WDT_SYSDBG_DEG_EN2	(MTK_WDT_BASE+0x008C)
#define MTK_WDT_DEBUG_2_REG		(MTK_WDT_BASE+0x0508)
#define MTK_WDT_COUNTER			(MTK_WDT_BASE+0x0514)

/*WDT_MODE*/
#define MTK_WDT_MODE_KEYMASK		(0xff00)
#define MTK_WDT_MODE_KEY		(0x22000000)

#define MTK_WDT_MODE_DDR_RESERVE  (0x0080)
#define MTK_WDT_MODE_DUAL_MODE  (0x0040)
#define MTK_WDT_MODE_IRQ_LEVEL_EN   (0x0020)
/*
 * MTK_WDT_MODE_AUTO_RESTART is replaced by MTK_WDT_NONRST2_BYPASS_PWR_KEY
 * of NONRST_REG2 for common kernel projects and two stage timeout design
 */
#define MTK_WDT_MODE_EXTRA_CNT    (0x0010)
#define MTK_WDT_MODE_IRQ		(0x0008)
#define MTK_WDT_MODE_EXTEN		(0x0004)
#define MTK_WDT_MODE_EXT_POL		(0x0002)
#define MTK_WDT_MODE_ENABLE		(0x0001)

/*WDT_IRQ_CLR*/
#define MTK_WDT_IRQ_CLR_KEY        (0x23000000)
#define MTK_WDT_IRQ_CLR_MASK       (0x1FF)
/* clear WDT_STATUS [4~0] */
#define MTK_WDT_IRQ_CLR_EXTB       (1 << 0)
/* clear WDT_STATUS [17~16] */
#define MTK_WDT_IRQ_CLR_EXT        (1 << 1)
/* clear WDT_STATUS [28] */
#define MTK_WDT_IRQ_CLR_SEJ        (1 << 2)
/* clear WDT_STATUS [29] */
#define MTK_WDT_IRQ_CLR_IRQ_STS    (1 << 3)
/* clear WDT_STATUS [30] */
#define MTK_WDT_IRQ_CLR_SW_WDT     (1 << 4)
/* clear WDT_STATUS [31] */
#define MTK_WDT_IRQ_CLR_WDT_STS    (1 << 5)
/* clear event_b to SPM */
#define MTK_WDT_IRQ_CLR_WAKE_UP    (1 << 6)
/* deassert wdt irq */
#define MTK_WDT_IRQ_CLR_DEASSERT   (1 << 7)
#define MTK_WDT_IRQ_CLR_DEBUGSYS   (1 << 8)

/*WDT_LENGTH*/
#define MTK_WDT_LENGTH_TIME_OUT	(0xffe0)
#define MTK_WDT_LENGTH_KEYMASK	(0x001f)
#define MTK_WDT_LENGTH_KEY		(0x0008)
#define MTK_WDT_LENGTH_CTL_KEY	(0x95 << 24)

/*WDT_RESTART*/
#define MTK_WDT_RESTART_KEY		(0x1971)

/*WDT_STATUS*/
#define MTK_WDT_STATUS_SPM_THERMAL_RST		(1 << 0)
#define MTK_WDT_STATUS_SPM_RST			(1 << 1)
#define MTK_WDT_STATUS_EINT_RST			(1 << 2)
#define MTK_WDT_STATUS_SYSRST_RST			(1 << 3)
#define MTK_WDT_STATUS_DVFSP_RST			(1 << 4)
#define MTK_WDT_STATUS_SSPM_RST			(1 << 16)
#define MTK_WDT_STATUS_MDDBG_RST			(1 << 17)
#define MTK_WDT_STATUS_THERMAL_DIRECT_RST	(1 << 18)
#define MTK_WDT_STATUS_DEBUGWDT_RST		(1 << 19)
#define MTK_WDT_STATUS_SECURITY_RST		(1 << 28)
#define MTK_WDT_STATUS_IRQWDT_RST			(1 << 29)
#define MTK_WDT_STATUS_SWWDT_RST			(1 << 30)
#define MTK_WDT_STATUS_HWWDT_RST			(1 << 31)

/*WDT_INTERVAL*/
#define MTK_WDT_INTERNAL_KEY		(0x66000000)
#define MTK_WDT_INTERVAL_MASK		(0x0fff)

/*WDT_SWRST*/
#define MTK_WDT_SWRST_KEY		(0x1209)

/*WDT_SWSYSRST*/
#define MTK_WDT_SWSYS_RST_MM_RST            (0x00000002)
#define MTK_WDT_SWSYS_RST_MFG_RST           (0x00000004)
#define MTK_WDT_SWSYS_RST_VENC_RST          (0x00000008)
#define MTK_WDT_SWSYS_RST_VDEC_RST          (0x00000010)
#define MTK_WDT_SWSYS_RST_IMG_RST           (0x00000020)
#define MTK_WDT_SWSYS_RST_MD_RST            (0x00000080)
#define MTK_WDT_SWSYS_RST_CONN_RST          (0x00000200)
#define MTK_WDT_SWSYS_RST_APMIXED_RST       (0x00000400)
#define MTK_WDT_SWSYS_RST_CONN_MCU_RST      (0x00001000)
#define MTK_WDT_SWSYS_RST_CONMCU_RST        MTK_WDT_SWSYS_RST_CONN_MCU_RST
#define MTK_WDT_SWSYS_RST_RESERVED_RST      (0x00004000)
#define MTK_WDT_SWSYS_RST_C2K_RST           (0x00008000)
#define MTK_WDT_SWSYS_RST_AUDIO_RST         (0x00020000)
#define MTK_WDT_SWSYS_RST_CAMSYS_RST        (0x00040000)
#define MTK_WDT_SWSYS_RST_KEY               (0x88000000)

/* Reboot source */
#define RGU_STAGE_MASK      (0x7)
#define RGU_STAGE_PRELOADER (0x1)
#define RGU_STAGE_LK        (0x2)
#define RGU_STAGE_KERNEL    (0x3)
#define RGU_STAGE_DA        (0x4)

/* WDT_NONRST_REG2 */
#define MTK_WDT_NONRST2_SSPM_RESET     (1 << 0)
#define MTK_WDT_NONRST2_BYPASS_PWR_KEY (1 << 13)
#define MTK_WDT_NONRST2_SUSPEND_DIS    (1 << 14)
/* 31:29: 3-bits for current stage */
#define MTK_WDT_NONRST2_STAGE_OFS      (29)
/* 28:26: 3-bits for last stage */
#define MTK_WDT_NONRST2_LAST_STAGE_OFS (26)

/*MTK_WDT_REQ_IRQ*/
#define MTK_WDT_REQ_IRQ_KEY		(0x44000000)
#define MTK_WDT_REQ_IRQ_DEBUG_EN		(0x80000)
#define MTK_WDT_REQ_IRQ_SPM_THERMAL_EN		(0x0001)
#define MTK_WDT_REQ_IRQ_SPM_SCPSYS_EN		(0x0002)
#define MTK_WDT_REQ_IRQ_EINT_EN			(1<<2)
#define MTK_WDT_REQ_IRQ_SYSRST_EN		(1<<3)
#define MTK_WDT_REQ_IRQ_THERMAL_EN		(1<<18)

/*MTK_WDT_REQ_MODE*/
#define MTK_WDT_REQ_MODE_KEY		(0x33000000)
#define MTK_WDT_REQ_MODE_DEBUG_EN		(0x80000)
#define MTK_WDT_REQ_MODE_SPM_THERMAL		(0x0001)
#define MTK_WDT_REQ_MODE_SPM_SCPSYS		(0x0002)
#define MTK_WDT_REQ_MODE_EINT			(1<<2)
#define MTK_WDT_REQ_MODE_SYSRST			(1<<3)
#define MTK_WDT_REQ_MODE_THERMAL		(1<<18)

/* MTK_WDT_DEBUG_CTL */
#define MTK_WDT_DEBUG_CTL_KEY           (0x59000000)
#define MTK_RG_MCU_CACHE_PRESERVE       (0x00000008)
#define MTK_WDT_DVFSRC_PAUSE_PULSE          (0x00008000)
#define MTK_WDT_DVFSRC_SUCECESS_ACK         (0x00200000)

/* MTK_WDT_DEBUG_CTL2 */
#define MTK_WDT_DEBUG_CTL2_KEY           (0x55000000)
#define MTK_WDT_DEBUG_CTL_DVFSRC_EN      (1 << 9)
#define MTK_WDT_DEBUG_CTL_EMI_DCS_EN     (1 << 8)

/* MTK_WDT_LATCH_CTL */
#define MTK_WDT_LATCH_CTL_KEY            (0x95000000)
#define MTK_WDT_LATCH_CTL_DVFSRC         (1 << 13)

/* MTK_WDT_LATCH_CTL2 */
#define MTK_WDT_LATCH_CTL2_KEY      (0x95000000)
#define MTK_WDT_DFD_EN              (1 << 17)
#define MTK_WDT_DFD_THERMAL1_DIS    (1 << 18)
#define MTK_WDT_DFD_THERMAL2_DIS    (1 << 19)
#define MTK_WDT_DFD_TIMEOUT_SHIFT   (0)
#define MTK_WDT_DFD_TIMEOUT_MASK    (0x1FFFF << MTK_WDT_DFD_TIMEOUT_SHIFT)

/*MTK_WDT_RSTDEG_EN*/
#define MTK_WDT_RSTDEG_EN1_KEY			(0xa357)
#define MTK_WDT_RSTDEG_EN2_KEY			(0x67d2)

/*MTK_WDT_SYSDBG_DEG_EN*/
#define MTK_WDT_SYSDBG_DEG_EN1_KEY		(0x1b2a)
#define MTK_WDT_SYSDBG_DEG_EN2_KEY		(0x4f59)

enum wdt_rst_modes {
	WDT_RST_MODE_DEFAULT,
	WDT_RST_MODE_PMIC,
};

extern void __inner_flush_dcache_all(void);


#endif   /*__WDT_HW_H__*/
