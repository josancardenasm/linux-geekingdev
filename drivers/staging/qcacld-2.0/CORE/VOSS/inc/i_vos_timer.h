/*
 * Copyright (c) 2014 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

#if !defined( __I_VOS_TIMER_H )
#define __I_VOS_TIMER_H

/**=========================================================================

  \file  i_vos_timer.h

  \brief Linux-specific definitions for vOSS packets

  ========================================================================*/

/* $Header$ */

/*--------------------------------------------------------------------------
  Include Files
  ------------------------------------------------------------------------*/
#include <vos_timer.h>
#include <vos_types.h>
#include <linux/timer.h>
#include <linux/time.h>
#include <linux/jiffies.h>
#include <adf_os_lock.h>

/*--------------------------------------------------------------------------
  Preprocessor definitions and constants
  ------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/*--------------------------------------------------------------------------
  Type declarations
  ------------------------------------------------------------------------*/

typedef struct vos_timer_platform_s
{
   struct timer_list Timer;
   int threadID;
   v_U32_t cookie;
   adf_os_spinlock_t  spinlock;

} vos_timer_platform_t;

/**
 * __vos_system_ticks() - get system ticks
 *
 * Return: system tick in jiffies
 */
static inline vos_time_t __vos_system_ticks(void)
{
	return jiffies;
}

/**
 * __vos_system_ticks_to_msecs() - convert system ticks into milli seconds
 * @ticks: System ticks
 *
 * Return: system tick converted into milli seconds
 */
static inline uint32_t __vos_system_ticks_to_msecs(vos_time_t ticks)
{
	return jiffies_to_msecs(ticks);
}

/*
 * TODOs: Need to add deferred timer implementation
 *
*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __I_VOS_TIMER_H
