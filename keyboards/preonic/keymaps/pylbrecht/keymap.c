/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define HRM_F SFT_T(KC_F)
#define HRM_J SFT_T(KC_J)
#define HRM_K RALT_T(KC_K)
#define HRM_D LALT_T(KC_D)

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _SYMBOLS,
  _ADJUST,
};

enum preonic_keycodes {
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | OSM  | Ctrl | GUI  |      |Lower |    Space    |Raise |      | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
  KC_ESC,  KC_A,    KC_S,    HRM_D,   HRM_F,   KC_G,    KC_H,    HRM_J,   HRM_K,   KC_L,    KC_SCLN, CW_TOGG,
  _______, CTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH), _______,
  OSM(MOD_LCTL | MOD_LSFT), KC_LCTL, KC_LGUI, _______, LOWER,   KC_SPC,  KC_SPC,  RAISE,   _______, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  =   |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  -   |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  _   |   1  |   2  |   3  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   0  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, _______, _______, _______, KC_EQL,  KC_7, KC_8, KC_9, KC_ASTR, _______,
  _______, _______, _______, _______, _______, _______, KC_MINS, KC_4, KC_5, KC_6, KC_PLUS, _______,
  _______, _______, _______, _______, _______, _______, KC_UNDS, KC_1, KC_2, KC_3, KC_BSLS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_0, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |   {  |   }  |   ~  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |   (  |   )  |   `  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   [  |   ]  |   |  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_preonic_grid(
  _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_TILD, _______, _______, _______, _______, _______, _______,
  _______, KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, KC_GRV, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_PIPE, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |QK_BOOT|     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_preonic_grid(
 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R'
);


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _SYMBOLS, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _SYMBOLS, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_SYMBOLS);
            update_tri_layer(_LOWER, _SYMBOLS, _ADJUST);
          } else {
            layer_off(_SYMBOLS);
            update_tri_layer(_LOWER, _SYMBOLS, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};

#if defined(OS_DETECTION_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
os_variant_t os;
uint32_t swap_alt_gui(uint32_t trigger_time, void *cb_arg) {
    os = detected_host_os();
    if (os) {
        switch (os) {
            case OS_MACOS:
            case OS_IOS:
                keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = true;
                break;
            default:
                keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = false;
                break;
        }
        eeconfig_update_user(keymap_config.raw);
        clear_keyboard();
    }
    return os ? 0 : 500;
}
#endif

void keyboard_post_init_user(void) {
#if defined(OS_DETECTION_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
    defer_exec(100, swap_alt_gui, NULL);
#endif
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        case KC_SEMICOLON:  // On Colemak this maps to KC_O
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
