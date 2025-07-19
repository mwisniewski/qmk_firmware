#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUMERIC 1
#define _MOUSE 2
#define _RGB_ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMERIC,
  MOUSE,
  RGB_ADJUST,
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_NUMERIC)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_RGB_ADJUST, KC_END)
#define KC_ADPU LT(_RGB_ADJUST, KC_PGUP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(LT(2,KC_GRV), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, LT(2,KC_MINS), KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, MO(1), MO(1), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LBRC, KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LT(3,KC_PGUP), KC_PGDN, KC_HOME, LT(3,KC_END), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, KC_PPLS, KC_PMNS, LALT_T(KC_PAST), LCTL_T(KC_BSLS), KC_BSPC, KC_DEL, KC_ENT, KC_SPC, KC_RALT, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT),
	[_NUMERIC] = LAYOUT(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_NO, KC_TRNS, KC_HASH, KC_DLR, KC_LBRC, KC_RBRC, KC_GRV, KC_TRNS, KC_TRNS, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_NO, KC_TRNS, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_P1, KC_P2, KC_P3, KC_PENT, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_PENT, KC_NO),
	[_MOUSE] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_WH_D, KC_WH_U, KC_WH_D, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_BTN3, KC_BTN1, KC_BTN2, KC_BTN1, KC_BTN2, KC_BTN3, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R),
	[_RGB_ADJUST] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SPI, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, RGB_SPD, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_M_P, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("DEFAULT\n"), false);
            break;
        case _NUMERIC:
            oled_write_P(PSTR("NUMERIC\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOUSE\n"), false);
            break;
		case _RGB_ADJUST:
            oled_write_P(PSTR("ADJUST RGB\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_P(PSTR("UNKNOWN\n"), false);
    }

    oled_write_P(PSTR("\n"), false);
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
	oled_write_P(PSTR("\n"), false);
	oled_write_P(PSTR("PhobosX"), false);
    
    return false;
}

#endif

// layer_state_t layer_state_set_user(layer_state_t state) {
    // switch (get_highest_layer(state)) {
    // case _QWERTY:
        // rgblight_setrgb (0x00,  0x00, 0xFF);
        // break;
    // case _NUMERIC:
        // rgblight_setrgb (0xFF,  0x00, 0x00);
        // break;
    // case _MOUSE:
        // rgblight_setrgb (0x00,  0xFF, 0x00);
        // break;
    // case _RGB_ADJUST:
        // rgblight_setrgb (0x7A,  0x00, 0xFF);
        // break;
    // default: //  for any other layers, or the default layer
        // rgblight_setrgb (0x00,  0xFF, 0xFF);
        // break;
    // }
  // return state;
// }

// Funkcja do rozwiązania problemów z inicjalizacją USB
void keyboard_post_init_user(void) {
    // Opóźnienie dla stabilnej inicjalizacji USB
    wait_ms(100);
    
    // Force USB re-enumeration if needed
    #ifdef SPLIT_KEYBOARD
    if (is_keyboard_master()) {
        // Dodatkowe opóźnienie dla master side
        wait_ms(50);
        
        // Debug: sprawdzenie ustawień handedness
        #ifdef CONSOLE_ENABLE
        uprintf("Is left hand: %s\n", is_keyboard_left() ? "YES" : "NO");
        uprintf("Is master: %s\n", is_keyboard_master() ? "YES" : "NO");
        #endif
    }
    #endif
}

// Dodatkowa funkcja dla suspend/resume USB
void suspend_wakeup_init_user(void) {
    // Krótkie opóźnienie po wakeup
    wait_ms(50);
}





