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

enum discord_keycodes {
  DISCORD_MUTE = SAFE_RANGE,
  DISCORD_DEAFEN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(

    KC_MPRV, KC_MPLY, KC_MNXT,
    KC_F20, KC_F21, KC_F22,
    KC_MPLY, KC_MPLY, KC_MUTE

    )
};


/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (!clockwise) {
      tap_code(KC_DOWN);
    } else {
      tap_code(KC_UP);
    }
  } else if (index == 1) { /* Second encoder */
    if (!clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}

//Custom discord macros


// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
//     switch (keycode) {
//       case DISCORD_MUTE:
//           SEND_STRING(SS_DOWN(X_F20) "m" SS_UP(X_F20));
//           return false; break;
//       case DISCORD_DEAFEN:
//       }
//     }
//     return true; // Process all other keycodes normally
//   };
