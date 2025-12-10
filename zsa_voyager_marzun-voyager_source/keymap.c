#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    MT(MOD_LALT, KC_ESCAPE),KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_LEFT_CTRL,   KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_GUI,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       OSL(1),         
                                                    KC_SPACE,       KC_BSPC,                                        MT(MOD_LSFT, KC_TAB),LT(2, KC_ENTER)
  ),
  [1] = LAYOUT_voyager(
    KC_TILD,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_GRAVE,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_BSLS,        KC_F12,         
    KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,                                        KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_ASTR,        QK_LLCK,        
    KC_TRANSPARENT, KC_LEFT_CTRL,   KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,                                        KC_1,           KC_2,           KC_3,           KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
  [2] = LAYOUT_voyager(
    ST_MACRO_0,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PAGE_UP,     LALT(KC_UP),    LALT(KC_DOWN),  
    ST_MACRO_1,     LALT(LGUI(KC_E)),KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  RGB_TOG,                                        KC_DELETE,      KC_HOME,        KC_END,         KC_PGDN,        LALT(KC_LEFT),  LALT(KC_RIGHT), 
    ST_MACRO_2,     KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,                                KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       LALT(LGUI(LCTL(KC_LEFT))),LALT(LGUI(LCTL(KC_RIGHT))),
    KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    RGB_VAD,        RGB_VAI,                                        LALT(LGUI(KC_UP)),LGUI(LCTL(KC_LEFT)),LGUI(LCTL(KC_RIGHT)),LALT(LGUI(KC_DOWN)),LGUI(KC_LEFT_CTRL),KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};





extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {188,255,255}, {188,255,255}, {188,255,255}, {169,255,84}, {169,255,84}, {169,255,84}, {188,255,255}, {188,255,255}, {188,255,255}, {169,255,84}, {169,255,84}, {169,255,84}, {188,255,255}, {188,255,255}, {188,255,255}, {169,255,84}, {169,255,84}, {169,255,84}, {169,255,84}, {188,255,255} },

    [2] = { {212,255,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {212,255,255}, {27,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {41,255,255}, {212,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {41,255,255}, {41,255,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,255,255}, {41,255,255}, {41,255,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {212,255,255}, {212,255,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {212,255,255}, {212,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {212,255,255}, {212,255,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_Q));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_LSFT(SS_TAP(X_T)));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_W));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
