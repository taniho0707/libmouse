SHELL = /bin/sh

PREFIX = arm-none-eabi-
LIBNAME := libmouse_arm.so
CPU = -mcpu=cortex-m4
FPU = -mfpu=fpv4-sp-d16
FLOAT-ABI = -mfloat-abi=softfp
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)
C_DEFS =  \
-DSTM32F412Cx \
-D__FPU_PRESENT -DARM_MATH_CM4
C_INCLUDES = 
CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections \
-fmessage-length=0 -fexceptions -fno-rtti -funsigned-char -fpermissive -fno-use-cxa-atexit -std=c++14 -Wno-narrowing -shared -fPIC

BINPATH := /usr/bin
CC := $(BINPATH)/$(PREFIX)g++
AS := $(BINPATH)/$(PREFIX)g++ -x assembler-with-cpp
CP := $(BINPATH)/$(PREFIX)objcopy
AR := $(BINPATH)/$(PREFIX)ar
SZ := $(BINPATH)/$(PREFIX)size

.PHONY: all
all: $(LIBNAME)

$(LIBNAME): $(wildcard *.cpp)
	$(CC) $(CFLAGS) $(wildcard *.cpp) -o $(LIBNAME)

x86:
	${MAKE} "CC=g++" "CFLAGS=-Wall -funsigned-char -std=c++14 -shared -fPIC" "LIBNAME=libmouse_x86.so"

.PHONY: clean
clean:
	rm -f *.o *.so
