cmake_minimum_required(VERSION 3.12)
project(u-boot-MT7621 C)

#SET(HSOT_NAME "192.168.10.113") # set ip adress router


set(CMAKE_C_STANDARD 99)

add_definitions(-DSTAGING_DIR=${CMAKE_SOURCE_DIR}/staging_dir)

SET(CMAKE_C_COMPILER "${CMAKE_SOURCE_DIR}/toolchain/buildroot-gcc342/bin/mipsel-linux-uclibc-gcc")
SET(CMAKE_CXX_COMPILER "${CMAKE_SOURCE_DIR}/toolchain/buildroot-gcc342/bin/mipsel-linux-uclibc-g++")
SET(CMAKE_AR "${CMAKE_SOURCE_DIR}/toolchain/buildroot-gcc342/bin/mipsel-linux-uclibc-ar")
SET(CMAKE_LINKER "${CMAKE_SOURCE_DIR}/toolchain/buildroot-gcc342/bin/mipsel-linux-uclibc-ld")
SET(CMAKE_RANLIB "${CMAKE_SOURCE_DIR}/toolchain/buildroot-gcc342/bin/mipsel-linux-uclibc-ranlib")
SET(CMAKE_NM "${CMAKE_SOURCE_DIR}/toolchain/buildroot-gcc342/bin/mipsel-linux-uclibc-nm")
SET(CMAKE_OBJDUMP "${CMAKE_SOURCE_DIR}/toolchain/buildroot-gcc342/bin/mipsel-linux-uclibc-objdump")
SET(CMAKE_OBJCOPY "${CMAKE_SOURCE_DIR}/toolchain/buildroot-gcc342/bin/mipsel-linux-uclibc-objcopy")
SET(CMAKE_STRIP "${CMAKE_SOURCE_DIR}/toolchain/buildroot-gcc342/bin/mipsel-linux-uclibc-strip")

SET(COMMON_FLAGS
        " -mthumb -mthumb-interwork -ffunction-sections -fdata-sections
        -g -fno-common -fmessage-length=0 -specs=nosys.specs -specs=nano.specs -fpch-preprocess")

SET(CMAKE_CXX_FLAGS_INIT "${COMMON_FLAGS} -std=c++11")
SET(CMAKE_C_FLAGS_INIT "${COMMON_FLAGS} -std=gnu99")


SET(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,-gc-sections, -T, -Wl,-u ${LINKER_SCRIPT}")
add_definitions(-D__weak=__attribute__\(\(weak\)\) -D__packed=__attribute__\(\(__packed__\)\)
        -DCFG_ENV_IS_IN_NAND -DMT7621_ASIC_BOARD -DMTK_NAND
        #[[
        -DASIC_BOARD -DMT7621_MP -DMT7621_USE_GE1 -DMAC_TO_MT7530_MODE
        -DON_BOARD_NAND_BOOTSTRAP -DMT7621_CPU_880MHZ -DMT7621_CPU_FREQUENCY -DON_BOARD_DDR3 -DON_BOARD_DDR_WIDTH_16
        -DON_BOARD_16BIT_DRAM_BUS -DON_BOARD_2048M_DRAM_COMPONENT -DMT7621_DDR_1066MHZ -MT7621_DDR_SPEED
        -DPDMA_NEW -DRX_SCATTER_GATTER_DMA -DRALINK_DUAL_VPE_FUN -DRALINK_DUAL_CORE_FUN -DDDR_ACT_SETTING
        -DDEFAULT_DDR3_2048M -DUBOOT_RAM -DHTTPD_SUPPORT
        ]]
        )

add_definitions(-DSTAGING_DIRD=${CMAKE_SOURCE_DIR}/stagingdir)


file(GLOB_RECURSE SOURCES "include/*.*" "board/rt2880/*.*" "board/rt2880/include/*.*" "include/asm/*.*" "include/asm-mips/*.*" "include/bedbug/*.*" "include/configs/*.*" "include/linux/*.*"
        "include/linux/byteorder/*.*" "include/linux/mtd/*.*" "include/linux/unaligned/*.*" "include/linux/usb/*.*" "include/lzma/*.*" "include/mtd/*.*"
        "lib_generic/*.*" "lib_mips/*.*" "net/*.*" "rtc/*.*" "stage1/*.*" "common/*.*" "cpu/ralink_soc/*.*" "disk/*.*" "drivers/*.*"
        "drivers/msdc/*.*" "drivers/nand/*.*" "drivers/rtl8367/*.*" "drivers/rtl8367/api_8367b/*.*" "drivers/rtl8367/api_8370/*.*"
        "drivers/usb/host/*.*" "fs/fat/*.*" "httpd/*.*" "/httpd/vendors/*.*" )
include_directories( "${CMAKE_SOURCE_DIR}/toolchain/buildroot-gcc342/include"

        "include" "board/rt2880/" "board/rt2880/include/" "include/asm/" "include/asm-mips/" "include/bedbug/" "include/configs/" "include/linux/"
        "include/linux/byteorder/" "include/linux/mtd/" "include/linux/unaligned/" "include/linux/usb/" "include/lzma/" "include/mtd/"
        "lib_generic/" "lib_mips/" "net/" "rtc/" "stage1/" "common/" "cpu/ralink_soc/" "disk/" "drivers/"
        "drivers/msdc/" "drivers/nand/" "drivers/rtl8367/" "drivers/rtl8367/api_8367b/" "drivers/rtl8367/api_8370/"
        "drivers/usb/host/" "fs/fat/" "httpd/" "/httpd/vendors/"

        )


add_executable(${PROJECT_NAME}  ${SOURCES} )




