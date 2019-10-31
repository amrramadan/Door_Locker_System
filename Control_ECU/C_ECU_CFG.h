/******************************************************************************
 *
 * Module: Control ECU
 *
 * File Name: C_ECU_CFG.h
 *
 * Description: Configuration file for Control ECU Module.
 *
 * Author: Amr Ramadan
 ******************************************************************************/

#ifndef C_ECU_CFG_H_
#define C_ECU_CFG_H_

#define CTRL_ECU_PASSCODE_SIZE 			5
#define CTRL_ECU_PASSCODE_MAX_NUMBER	9
#define CTRL_ECU_BUFFER_SIZE			6
#define MC1_READY						0x01
#define MC2_READY						0x02
#define EEPROM_LOCATION_ADDRESS			0x0511
#define EEPROM_PASSCODE_CHECK_ADDRESS	0x0211
#define LOCKER_OPEN_ANGLE				124
#define LOCKER_CLOSE_ANGLE				187

#endif /* C_ECU_CFG_H_ */
