#include "mousejiggler.h" 

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  RAPIDF
};


bool rapid_fire = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		RAPIDF)

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
  if (rapid_fire) {
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    tap_code(KC_MS_LEFT);
    tap_code(KC_MS_RIGHT);
    tap_code(KC_MS_WH_UP);
    tap_code(KC_MS_WH_DOWN);
  } else {

  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RAPIDF:
      if (record->event.pressed) {
        rapid_fire = true;
      } else {
        rapid_fire = false;
      }
      break;
  }
  return true;
}

    /*    SEND_STRING("1");
    tap_code(KC_MS_BTN1);
    tap_code(KC_MS_BTN1);
    SEND_STRING(SS_LCTL("c"));
    tap_code(KC_RIGHT);
    SEND_STRING(SS_LCTL("v"));
    SEND_STRING("yaughtyaughtyaught");
    tap_code(KC_MS_BTN1);
    tap_code(KC_MS_BTN1);
    tap_code(KC_MS_BTN1);*/