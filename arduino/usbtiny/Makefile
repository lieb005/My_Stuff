# ======================================================================
# USBtiny global Makefile
#
# Copyright 2006-2010 Dick Streefland
#
# This is free software, licensed under the terms of the GNU General
# Public License as published by the Free Software Foundation.
# ======================================================================

GCCCORE= attiny25
#GCCCORE= attiny2313

AVRCORE = -pt25
#AVRCORE    = -pt2313

DIR	= spi ir usbtinyisp template util

all clean clobber:
	$(MAKE) $(MFLAGS) -C util $@
#	$(MAKE) $(MFLAGS) -C template $@
	$(MAKE) $(MFLAGS) -C usbtinyisp $@

#	@for i in $(DIR); do $(MAKE) $(MFLAGS) -C $$i $@; done
