/* Copyright 2021 hanachi-ap
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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
          KA01, KA02, KA03, KA04, KA05, KA06,                   KA10, KA11, KA12, KA13, KA14, KA15, KA16, \
          KB01, KB02, KB03, KB04, KB05, KB06,                   KB10, KB11, KB12, KB13, KB14, KB15, KB16, \
          KC01, KC02, KC03, KC04, KC05, KC06, KC07,       KC09, KC10, KC11, KC12, KC13, KC14, KC15,       \
    KD01,                   KD04, KD05, KD06, KD07, KD08, KD09, KD10, KD11, KD12                          \
) { \
   { KA01, KA02, KA03, KA04, KA05, KA06, KC_NO,KC_NO, KC_NO, KA10, KA11, KA12, KA13, KA14, KA15, KA16 }, \
   { KB01, KB02, KB03, KB04, KB05, KB06, KC_NO,KC_NO, KC_NO, KB10, KB11, KB12, KB13, KB14, KB15, KB16 }, \
   { KC01, KC02, KC03, KC04, KC05, KC06, KC07, KC_NO, KC09,  KC10, KC11, KC12, KC13, KC14, KC15, KC_NO}, \
   { KD01, KC_NO,KC_NO,KD04, KD05, KD06, KD07, KD08,  KD09,  KD10, KD11, KD12, KC_NO,KC_NO,KC_NO,KC_NO}  \
}

#define LAYOUT_SIDE_B( \
    KA16, KA15, KA14, KA13, KA12, KA11, KA10,                   KA06, KA05, KA04, KA03, KA02, KA01,   \
    KB16, KB15, KB14, KB13, KB12, KB11, KB10,                   KB06, KB05, KB04, KB03, KB02, KB01,   \
          KC15, KC14, KC13, KC12, KC11, KC10, KC09,       KC07, KC06, KC05, KC04, KC03, KC02, KC01,   \
                            KD12, KD11, KD10, KD09, KD08, KD07, KD06, KD05, KD04,                  KD01 \
) { \
   { KA01, KA02, KA03, KA04, KA05, KA06, KC_NO,KC_NO, KC_NO, KA10, KA11, KA12, KA13, KA14, KA15, KA16 }, \
   { KB01, KB02, KB03, KB04, KB05, KB06, KC_NO,KC_NO, KC_NO, KB10, KB11, KB12, KB13, KB14, KB15, KB16 }, \
   { KC01, KC02, KC03, KC04, KC05, KC06, KC07, KC_NO, KC09,  KC10, KC11, KC12, KC13, KC14, KC15, KC_NO}, \
   { KD01, KC_NO,KC_NO,KD04, KD05, KD06, KD07, KD08,  KD09,  KD10, KD11, KD12, KC_NO,KC_NO,KC_NO,KC_NO}  \
}
