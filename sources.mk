#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
# Assignment completed by Hongjian
#*****************************************************************************

# Add your Source files to this variable
SRC_DIR = ./src/
INC_DIR = ./include/

ifeq ($(PLATFORM),MSP432)
	SOURCES = $(SRC_DIR)main.c \
			  $(SRC_DIR)memory.c\
			  $(SRC_DIR)stats.c\
			  $(SRC_DIR)data.c\
			  $(SRC_DIR)course1.c
			$(SRC_DIR)interrupts_msp432p401r_gcc.c \
			$(SRC_DIR)startup_msp432p401r_gcc.c \
			$(SRC_DIR)system_msp432p401r.c
			
	INCLUDES = -I $(INC_DIR)common \
			   -I $(INC_DIR)CMSIS \
			   -I $(INC_DIR)msp432

else

	SOURCES = $(SRC_DIR)main.c \
			  $(SRC_DIR)memory.c\
			  $(SRC_DIR)stats.c\
			  $(SRC_DIR)data.c\
			  $(SRC_DIR)course1.c
	
	# Add your include paths to this variable

	INCLUDES = -I $(INC_DIR)common

endif





