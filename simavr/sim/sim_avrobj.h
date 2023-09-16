/*
	sim_avrobj.h

	Copyright 2023 AlexGuo1998 <AlexGuo1998@163.com>

 	This file is part of simavr.

	simavr is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	simavr is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with simavr.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SIM_AVROBJ_H__
#define __SIM_AVROBJ_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct elf_firmware_t elf_firmware_t;

int
avrobj_read_firmware(
	const char * file,
	elf_firmware_t * firmware);

#ifdef __cplusplus
};
#endif

#endif /*__SIM_AVROBJ_H__*/
