# ======================================================================
# Makefile for USBtinyISP AVR programmer
#
# Copyright 2006-2010 Dick Streefland
#
# This is free software, licensed under the terms of the GNU General
# Public License as published by the Free Software Foundation.
# ======================================================================

include ../inc.mk

USBTINY		= ../usbtiny
TARGET_ARCH	= -mmcu=$(GCCCORE)
OBJECTS		= main.o
FLASH_CMD	= avrdude -p$(AVRCORE) -U flash:w:main.hex -cpickit2
FUSES_CMD	= avrdude -p$(AVRCORE) -U hfuse:w:0xdf:m -U lfuse:w:0xef:m
STACK		= 32
FLASH		= 2048
SRAM		= 128
SCHEM		= 

include $(USBTINY)/common.mk
