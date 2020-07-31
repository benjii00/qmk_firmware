/* Copyright 2020 Benjamin
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
#define _BL 0
#define _FL 1

enum discord_keycodes {
  DISCORD_MUTE = SAFE_RANGE,
  DISCORD_DEAFEN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base */
  [_BL] = LAYOUT(
    KC_MPLY,  LT(_FL, KC_MPLY), KC_MUTE,
    KC_F20,   DISCORD_DEAFEN,   DISCORD_MUTE,
    KC_MPRV,  KC_MPLY,          KC_MNXT
  ),
  [_FL] = LAYOUT(
    _______, _______, _______,
    _______, RESET,   _______,
    _______, _______, _______
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (!clockwise) {
      tap_code(KC_F23);
    } else {
      tap_code(KC_F24);
    }
  } else if (index == 1) { /* Second encoder */
    if (!clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}

//Discord macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case DISCORD_MUTE:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_SLCK) "m" SS_UP(X_SLCK));
        }
        break;
        return false;
      case DISCORD_DEAFEN:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_SLCK) "d" SS_UP(X_SLCK) SS_TAP(X_SLCK));
        }
        break;
        return false;
    }
    return true; // Process all other keycodes normally
  };
