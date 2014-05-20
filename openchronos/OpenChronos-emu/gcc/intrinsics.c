// intrinsics.c
#include <intrinsics.h>

/* pfs: 2010-06-13 none of the code below has ben tested
 * because I have yet to get msp430-gdbproxy working with my FET
 */
#ifdef EMU
void __delay_cycles(unsigned long __cycles)
{
}

//__set_interrupt_state  used in bsp_msp430_defs.h, rf1a.c
void     __set_interrupt_state(istate_t state)
{
}

	
//__get_interrupt_state  used in bsp_msp430_defs.h, rf1a.c
istate_t __get_interrupt_state(void)
{
	return 0;
} 

unsigned short __even_in_range(unsigned short __value, unsigned short __bound)
{
	return __value;
}
#else

/* function: __even_in_range used only in adc12.c
 * moved to separate assembler file even_in_range.s
 * unsigned short __even_in_range(unsigned short __value, unsigned short __bound)
 * the object is to create a more efficient switch statement
 */

//__delay_cycles  used in main.c, rf1a.c, bsp_board.c
void __delay_cycles(unsigned long __cycles)
{
	// divide by eight
	asm("clrc");
	asm("rra.w %[src]" 
		: [src] "=r" (__cycles) 
		: "[src]" (__cycles) );
	asm("clrc");
	asm("rra.w %[src]" 
		: [src] "=r" (__cycles) 
		: "[src]" (__cycles) );
	asm("clrc");
	asm("rra.w %[src]" 
		: [src] "=r" (__cycles) 
		: "[src]" (__cycles) );
	asm("DelayLoop:");
	asm("nop");	// add nops to increase loop to eight clock cycles
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("dec.w %[src]"
		: [src] "=r" (__cycles) 
		: "[src]" (__cycles));
	asm("jne DelayLoop");
}

//__set_interrupt_state  used in bsp_msp430_defs.h, rf1a.c
void     __set_interrupt_state(istate_t state)
{
	 __asm__("bis %0,r2" : : "ir" ((uint16_t) state));
}

	
//__get_interrupt_state  used in bsp_msp430_defs.h, rf1a.c
istate_t __get_interrupt_state(void)
{
	return(READ_SR&0x0008);
 }
 
#endif 
