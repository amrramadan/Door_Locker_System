/******************************************************************************
 *
 * Module: Control ECU
 *
 * File Name: C_ECU.C
 *
 * Description: Source file for Control ECU Module.
 *
 * Author: Amr Ramadan
 ******************************************************************************/
#include "C_ECU.h"

uint8 compare_buffers;
uint8 eeprom_write;
uint8 eeprom_read;
uint8 counter = LOW;
uint8 buffer_1[CTRL_ECU_BUFFER_SIZE];
uint8 buffer_2[CTRL_ECU_BUFFER_SIZE];
uint8 buffer_3[CTRL_ECU_BUFFER_SIZE];
#define NEW_PASSCODE 0
int main() {
	UART_init();
	EEPROM_init();
	SET_BIT(DDRD, PD5);
#if NEW_PASSCODE == 1
	while (UART_receiveByte() != MC1_READY) {}
	UART_receiveString(buffer_1);
	while (counter < CTRL_ECU_PASSCODE_SIZE) {
		eeprom_write = buffer_1[counter];
		EEPROM_writeByte(EEPROM_LOCATION_ADDRESS + counter, eeprom_write);
		_delay_ms(50);
		counter = counter + HIGH;
	}
#endif
	while (HIGH) {
		counter = LOW;
		while (counter < CTRL_ECU_PASSCODE_SIZE) {
			EEPROM_readByte(EEPROM_LOCATION_ADDRESS + counter, &eeprom_read);
			_delay_ms(50);
			buffer_2[counter] = eeprom_read;
			counter = counter + HIGH;
		}

		while (UART_receiveByte() != MC1_READY) {}
		UART_receiveString(buffer_3);
		compare_buffers = strcmp(buffer_2, buffer_3);
		_delay_ms(100);
		if (compare_buffers == LOW) {
			UART_sendByte(LOW);
			timer1_PWM_init(LOCKER_OPEN_ANGLE);
			_delay_ms(1500);
			timer1_PWM_init(LOCKER_CLOSE_ANGLE);
		} else {
			UART_sendByte(HIGH);
		}

	}
}

