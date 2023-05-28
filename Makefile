#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
#Author: HOGNJIAN ZHU	
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#       .o - Generate .o object file from .c
#		-i - Genearate preprocessed .i file
#		-asm - Generate assembly file
#
#		compile-all: compile all the file, generate .o for each .c object

#		build: Compile all the file and generate the final .out output

#		clean: remove all the output and intermediate files
#
# Platform Overrides:
#   CC 
#	LD
#	CPU 
#	FPU 
#	ARCH 
#	FLOAT-ABI 
#	SPECS 
#	LINKERFILE 
#	LDFLAGS
#	OBJDUMP 
#	SIZE
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST #default platform


# Compiler Flags and Defines


#Target Executable
TARGET = finalAssesssment

#Objects file
OBJS = $(SOURCES:.c=.o)

#Asembly file
ASM = $(SOURCES:.c =.asm)

#Preprocessed file
PREP = $(SOURCES:.c =.i)

#Dependency files
DEP = $(SOURCES:.c=.d)

CFLAGS = -Wall -g -O0 -std=c99 -D$(PLATFORM) $(ARMFLAGS) #-Werror 
CPPFLAGs = -E
DEPFLAGS = -MMD -MP

ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = ld
	SIZE = size
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJDUMP = objdump
endif

ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CPU = cortex-m4
	FPU = fpv4-sp-d16
	ARCH = armv7e-m
	FLOAT-ABI = hard
	SPECS = nosys.specs
	LINKERFILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKERFILE)
	OBJDUMP = arm-none-eabi-objdump
	SIZE = arm-none-eabi-size 
	ARMFLAGS = -mcpu=$(CPU) -mthumb --specs=$(SPECS) -march=$(ARCH) -mfloat-abi=$(FLOAT-ABI) -mfpu=$(FPU)
endif

# IF VERBOSE 
ifeq ($(VERBOSE), true)
	CFLAGS += -DVERBOSE
endif


%.o : %.c 
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

%.i : %.c
	$(CC) $(INCLUDES) $(CPPFLAGs) $< $(CFLAGS) -o $@

%.asm : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

$(TARGET).out: $(OBJS) $(DEP) 
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJS)


# Compile All command, generate .o file for each object
.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $^ $(CFLAGS) -o $@


#Build 
#create the C1M2.out file
.PHONY: build
build: $(TARGET).out



# clean command
#Remove all the .map .out .o .asm .i file
.PHONY: clean
clean:
	echo "Cleaning all projects"
	rm -rf ${SRC_DIR}*{.o,.out,.map,.asm,.i} $(TARGET).out
	ls
	sleep 2
	clear
