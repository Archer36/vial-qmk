#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

enum layer_names {
  _ZERO,
  _ONE,
  _TWO,
  _THREE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ZERO] = LAYOUT(
    KC_MPLY, KC_HOME, KC_MUTE,
    MO(1),   KC_UP,   RGB_MOD,
    KC_LEFT, KC_DOWN, KC_RGHT
),

[_ONE] = LAYOUT(
    RESET,   BL_STEP, KC_STOP,
    _______, KC_HOME, RGB_MOD,
    KC_MPRV, KC_END , KC_MNXT
),

[_TWO] = LAYOUT(
    _______, _______, _______,
    _______, _______, _______,
    _______, _______, _______
),

[_THREE] = LAYOUT(
    _______, _______, _______,
    _______, _______, _______,
    _______, _______, _______
)

};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsvCyan = {127, 255, 63};
    HSV hsvGreen = {85, 255, 63};
    HSV hsvRed = {0, 255, 63};

    RGB rgb;

    if (layer_state_is(0)) {
        // Set underglow to cyan for layer 0
        rgb = hsv_to_rgb(hsvCyan);
    } else if (layer_state_is(1)) {
        // Set underglow to green for layer 1
        rgb = hsv_to_rgb(hsvGreen);
    } else {
        // Set underglow to red for default/unknown
        rgb = hsv_to_rgb(hsvRed); 
    }

    for (uint8_t i = led_min; i <= led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) { // 0x02 == underglow
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_my_per_key_rgb);
}
