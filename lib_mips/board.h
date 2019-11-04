//
// Created by v.nimych on 16.10.19.
//

#ifndef U_BOOT_MT7621_BOARD_H
#define U_BOOT_MT7621_BOARD_H
#include <common.h>


int check_uboot_image(ulong image_ptr, ulong image_size);
int flash_uboot_image(ulong image_ptr, ulong image_size);
int flash_kernel_image(ulong image_ptr, ulong image_size);








#endif //U_BOOT_MT7621_BOARD_H
