#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		LCTL(KC_Z), LCTL(KC_C), LCTL(KC_V), LCTL(LSFT(KC_M)), KC_MUTE),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};



void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}