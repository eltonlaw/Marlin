/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"

#if ENABLED(SDCARD_REPORT_INFORMATION)

#include "../gcode.h"
#include "../../sd/cardreader.h"
#include "../../core/serial.h"

/**
 * M39: Report SD Card information
 * Parameters:
 *   Pn SD slot number, default 0
 *   Sn Response format. S0 returns a plain text response, S2 returns a response in JSON format.
 * Examples:
 *    M39  ; report information for SD card 0 in plain text format
 *    M39 P1 S2 ; report information for SD card 1 in JSON format
 */
void GcodeSuite::M39() {

  int slot = -1;
  if (parser.seen('P'))
    slot = parser.value_int();
  int resp_format = -1;
  if (parser.seenval('S')) {
    resp_format = parser.value_int();
  }
  SERIAL_ECHO_START();
  SERIAL_ECHOPGM("M39()");
  SERIAL_ECHOPAIR("sd_slot=", slot);
  SERIAL_ECHOLNPAIR("format", resp_format);
}

#endif // SDCARD_REPORT_INFORMATION
