/************************************************************************************
** VENDOR_EDIT
** Copyright (C), 2018-2019, OPLUS Mobile Comm Corp., Ltd
**
** Description:
**    For P80 charger ic driver
**
** Version: 1.0
** Date created: 2018-11-09
** Author: Jianchao.Shi@PSW.BSP.CHG
**
** --------------------------- Revision History: ------------------------------------
* <version>       <date>         <author>              			<desc>
* Revision 1.0    2018-11-09   Jianchao.Shi@PSW.BSP.CHG   	Created for new architecture
*************************************************************************************/
#ifndef __OPLUS_BATTERY_MTK6779_H__
#define __OPLUS_BATTERY_MTK6779_H__

#include <linux/device.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>
#include <linux/mutex.h>
#include <linux/notifier.h>
#include <linux/spinlock.h>
#include <linux/timer.h>
#include <linux/wait.h>
#include <mt-plat/charger_type.h>
#include <mt-plat/mtk_charger.h>
#include <mt-plat/mtk_battery.h>
#include <mt-plat/charger_class.h>

/* PD */
#include "../../../misc/mediatek/typec/tcpc/inc/tcpm.h"

#include "../../../misc/mediatek/typec/tcpc/inc/mtk_direct_charge_vdm.h"

struct charger_manager;
#include "../../supply/mediatek/charger/mtk_pe_intf.h"
#include "../../supply/mediatek/charger/mtk_pe20_intf.h"
#include "../../supply/mediatek/charger/mtk_pdc_intf.h"
#include "../../supply/mediatek/charger/mtk_pe40_intf.h"
#include "../../supply/mediatek/charger/mtk_charger_init.h"
#include "../../supply/mediatek/charger/mtk_charger_intf.h"

//====================================================================//
/* mtk_pe40_intf begin */
#define CONFIG_MTK_PUMP_EXPRESS_PLUS_40_SUPPORT

#define VBUS_IDX_MAX 5

struct pe40_power_cap {
	uint8_t selected_cap_idx;
	uint8_t nr;
	uint8_t pwr_limit[PDO_MAX_NR];
	int max_mv[PDO_MAX_NR];
	int min_mv[PDO_MAX_NR];
	int ma[PDO_MAX_NR];
	int maxwatt[PDO_MAX_NR];
	int minwatt[PDO_MAX_NR];
};

typedef enum {
	STEP_CHG_STATUS_STEP1 = 0,	/*16C~44C*/
	STEP_CHG_STATUS_STEP2,
	STEP_CHG_STATUS_STEP3,
	STEP_CHG_STATUS_STEP4,
	STEP_CHG_STATUS_INVALID
} OPLUS_STEP_CHG_STATUS;

#ifdef VENDOR_EDIT

struct mtk_pmic {
	struct charger_manager* oplus_info;
};

//extern int mt_power_supply_type_check(void);
extern enum charger_type mt_get_charger_type(void);
//int battery_meter_get_charger_voltage(void);
extern int mt6360_get_vbus_rising(void);
extern int mt6360_check_charging_enable(void);
extern int mt6360_suspend_charger(bool suspend);
extern int mt6360_set_rechg_voltage(int rechg_mv);
extern int mt6360_reset_charger(void);
extern int mt6360_set_chging_term_disable(bool disable);
extern int mt6360_aicl_enable(bool enable);
extern int mt6360_set_register(u8 addr, u8 mask, u8 data);
//extern int oplus_battery_meter_get_battery_voltage(void);
//extern int charger_pretype_get(void);

//extern int get_rtc_spare_fg_value(void);
//extern int set_rtc_spare_fg_value(int val);
//extern int get_rtc_spare_oplus_fg_value(void);
//extern int set_rtc_spare_oplus_fg_value(int val);

//extern int mt_get_chargerid_volt(void);
//extern void mt_set_chargerid_switch_val(int value);
//extern int mt_get_chargerid_switch_val(void);


extern void mt_power_off(void);
extern void mt_usb_connect(void);
extern void mt_usb_disconnect(void);

//extern int oplus_usb_switch_gpio_gpio_init(void);

//#if defined(CONFIG_OPLUS_CHARGER_MTK6763) || defined(CONFIG_OPLUS_CHARGER_MTK6771)
//extern int oplus_battery_meter_get_battery_voltage(void);
//extern bool meter_fg_30_get_battery_authenticate(void);

//extern int qpnp_charger_type_get(void);
//extern bool qpnp_lbc_is_usb_chg_plugged_in(void);
//extern int qpnp_get_prop_charger_voltage_now(void);
//extern int qpnp_get_prop_battery_voltage_now(void);
//extern int qpnp_set_pmic_soc_memory(int soc);
//extern int qpnp_get_pmic_soc_memory(void);

bool oplus_pmic_check_chip_is_null(void);
extern int oplus_get_typec_sbu_voltage(void);
extern void oplus_set_water_detect(bool enable);
extern int oplus_get_water_detect(void);
extern bool oplus_check_hvdcp_support(void);
extern enum power_supply_type mt6360_get_hvdcp_type(void);
void mt6360_enable_hvdcp_detect(void);
#ifdef VENDOR_EDIT
void oplus_gauge_set_event(int event);
#endif
#endif
#endif /* __OPLUS_BATTERY_MTK6885_H__ */
