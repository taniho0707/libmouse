SHELL = /bin/sh

PREFIX = arm-none-eabi-
LIBNAME := libmouse_arm
CPU = -mcpu=cortex-m4
FPU = -mfpu=fpv4-sp-d16
FLOAT-ABI = -mfloat-abi=softfp
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)
C_DEFS =  \
-DSTM32F412Cx \
-D__FPU_PRESENT -DARM_MATH_CM4
C_INCLUDES = 
CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections \
-fmessage-length=0 -fexceptions -fno-rtti -funsigned-char -fpermissive -fno-use-cxa-atexit -std=c++14 -Wno-narrowing -Wl,--gc-sections

BINPATH := /usr/bin
CC := $(BINPATH)/$(PREFIX)g++
AS := $(BINPATH)/$(PREFIX)g++ -x assembler-with-cpp
CP := $(BINPATH)/$(PREFIX)objcopy
AR := $(BINPATH)/$(PREFIX)ar
SZ := $(BINPATH)/$(PREFIX)size

.PHONY: all
all: $(LIBNAME)

OBJECTS = $(notdir $(CPP_SOURCES:.cpp=.o))
vpath %.cpp $(sort $(dir $(wildcard *.cpp)))
%.o: %.cpp
	$(CC) $(CFLAGS) $< -c

$(LIBNAME): $(patsubst %.cpp,%.o,$(wildcard *.cpp))
	$(AR) rcs $(LIBNAME).a $^

x86:
	${MAKE} "CC=g++" "CFLAGS=-Wall -funsigned-char -std=c++14" "LIBNAME=libmouse_x86"

.PHONY: clean
clean:
	rm -f *.o *.so *.a
