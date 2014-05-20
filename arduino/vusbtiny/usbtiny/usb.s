	.file	"usb.c"
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.stabs	"/home/mark/workspace_c/usbtiny/usbtinyisp/",100,0,2,.Ltext0
	.stabs	"../usbtiny/usb.c",100,0,2,.Ltext0
	.text
.Ltext0:
	.stabs	"gcc2_compiled.",60,0,0,0
	.stabs	"int:t(0,1)=r(0,1);-32768;32767;",128,0,0,0
	.stabs	"char:t(0,2)=r(0,2);0;127;",128,0,0,0
	.stabs	"long int:t(0,3)=@s32;r(0,3);020000000000;017777777777;",128,0,0,0
	.stabs	"unsigned int:t(0,4)=r(0,4);0;0177777;",128,0,0,0
	.stabs	"long unsigned int:t(0,5)=@s32;r(0,5);0;037777777777;",128,0,0,0
	.stabs	"long long int:t(0,6)=@s64;r(0,6);01000000000000000000000;0777777777777777777777;",128,0,0,0
	.stabs	"long long unsigned int:t(0,7)=@s64;r(0,7);0;01777777777777777777777;",128,0,0,0
	.stabs	"short int:t(0,8)=r(0,8);-32768;32767;",128,0,0,0
	.stabs	"short unsigned int:t(0,9)=r(0,9);0;0177777;",128,0,0,0
	.stabs	"signed char:t(0,10)=@s8;r(0,10);-128;127;",128,0,0,0
	.stabs	"unsigned char:t(0,11)=@s8;r(0,11);0;255;",128,0,0,0
	.stabs	"float:t(0,12)=r(0,1);4;0;",128,0,0,0
	.stabs	"double:t(0,13)=r(0,1);4;0;",128,0,0,0
	.stabs	"long double:t(0,14)=r(0,1);4;0;",128,0,0,0
	.stabs	"short _Fract:t(0,15)=r(0,1);1;0;",128,0,0,0
	.stabs	"_Fract:t(0,16)=r(0,1);2;0;",128,0,0,0
	.stabs	"long _Fract:t(0,17)=r(0,1);4;0;",128,0,0,0
	.stabs	"long long _Fract:t(0,18)=r(0,1);8;0;",128,0,0,0
	.stabs	"unsigned short _Fract:t(0,19)=r(0,1);1;0;",128,0,0,0
	.stabs	"unsigned _Fract:t(0,20)=r(0,1);2;0;",128,0,0,0
	.stabs	"unsigned long _Fract:t(0,21)=r(0,1);4;0;",128,0,0,0
	.stabs	"unsigned long long _Fract:t(0,22)=r(0,1);8;0;",128,0,0,0
	.stabs	"_Sat short _Fract:t(0,23)=r(0,1);1;0;",128,0,0,0
	.stabs	"_Sat _Fract:t(0,24)=r(0,1);2;0;",128,0,0,0
	.stabs	"_Sat long _Fract:t(0,25)=r(0,1);4;0;",128,0,0,0
	.stabs	"_Sat long long _Fract:t(0,26)=r(0,1);8;0;",128,0,0,0
	.stabs	"_Sat unsigned short _Fract:t(0,27)=r(0,1);1;0;",128,0,0,0
	.stabs	"_Sat unsigned _Fract:t(0,28)=r(0,1);2;0;",128,0,0,0
	.stabs	"_Sat unsigned long _Fract:t(0,29)=r(0,1);4;0;",128,0,0,0
	.stabs	"_Sat unsigned long long _Fract:t(0,30)=r(0,1);8;0;",128,0,0,0
	.stabs	"short _Accum:t(0,31)=r(0,1);2;0;",128,0,0,0
	.stabs	"_Accum:t(0,32)=r(0,1);4;0;",128,0,0,0
	.stabs	"long _Accum:t(0,33)=r(0,1);8;0;",128,0,0,0
	.stabs	"long long _Accum:t(0,34)=r(0,1);8;0;",128,0,0,0
	.stabs	"unsigned short _Accum:t(0,35)=r(0,1);2;0;",128,0,0,0
	.stabs	"unsigned _Accum:t(0,36)=r(0,1);4;0;",128,0,0,0
	.stabs	"unsigned long _Accum:t(0,37)=r(0,1);8;0;",128,0,0,0
	.stabs	"unsigned long long _Accum:t(0,38)=r(0,1);8;0;",128,0,0,0
	.stabs	"_Sat short _Accum:t(0,39)=r(0,1);2;0;",128,0,0,0
	.stabs	"_Sat _Accum:t(0,40)=r(0,1);4;0;",128,0,0,0
	.stabs	"_Sat long _Accum:t(0,41)=r(0,1);8;0;",128,0,0,0
	.stabs	"_Sat long long _Accum:t(0,42)=r(0,1);8;0;",128,0,0,0
	.stabs	"_Sat unsigned short _Accum:t(0,43)=r(0,1);2;0;",128,0,0,0
	.stabs	"_Sat unsigned _Accum:t(0,44)=r(0,1);4;0;",128,0,0,0
	.stabs	"_Sat unsigned long _Accum:t(0,45)=r(0,1);8;0;",128,0,0,0
	.stabs	"_Sat unsigned long long _Accum:t(0,46)=r(0,1);8;0;",128,0,0,0
	.stabs	"void:t(0,47)=(0,47)",128,0,0,0
	.stabs	"/usr/avr/include/avr/pgmspace.h",130,0,0,0
	.stabs	"/usr/avr/include/inttypes.h",130,0,0,0
	.stabs	"/usr/lib/gcc/avr/4.8.0/include/stdint.h",130,0,0,0
	.stabs	"/usr/avr/include/stdint.h",130,0,0,0
	.stabs	"int8_t:t(4,1)=(0,10)",128,0,121,0
	.stabs	"uint8_t:t(4,2)=(0,11)",128,0,122,0
	.stabs	"int16_t:t(4,3)=(0,1)",128,0,123,0
	.stabs	"uint16_t:t(4,4)=(0,4)",128,0,124,0
	.stabs	"int32_t:t(4,5)=(0,3)",128,0,125,0
	.stabs	"uint32_t:t(4,6)=(0,5)",128,0,126,0
	.stabs	"int64_t:t(4,7)=(0,6)",128,0,128,0
	.stabs	"uint64_t:t(4,8)=(0,7)",128,0,129,0
	.stabs	"intptr_t:t(4,9)=(4,3)",128,0,142,0
	.stabs	"uintptr_t:t(4,10)=(4,4)",128,0,147,0
	.stabs	"int_least8_t:t(4,11)=(4,1)",128,0,159,0
	.stabs	"uint_least8_t:t(4,12)=(4,2)",128,0,164,0
	.stabs	"int_least16_t:t(4,13)=(4,3)",128,0,169,0
	.stabs	"uint_least16_t:t(4,14)=(4,4)",128,0,174,0
	.stabs	"int_least32_t:t(4,15)=(4,5)",128,0,179,0
	.stabs	"uint_least32_t:t(4,16)=(4,6)",128,0,184,0
	.stabs	"int_least64_t:t(4,17)=(4,7)",128,0,192,0
	.stabs	"uint_least64_t:t(4,18)=(4,8)",128,0,199,0
	.stabs	"int_fast8_t:t(4,19)=(4,1)",128,0,213,0
	.stabs	"uint_fast8_t:t(4,20)=(4,2)",128,0,218,0
	.stabs	"int_fast16_t:t(4,21)=(4,3)",128,0,223,0
	.stabs	"uint_fast16_t:t(4,22)=(4,4)",128,0,228,0
	.stabs	"int_fast32_t:t(4,23)=(4,5)",128,0,233,0
	.stabs	"uint_fast32_t:t(4,24)=(4,6)",128,0,238,0
	.stabs	"int_fast64_t:t(4,25)=(4,7)",128,0,246,0
	.stabs	"uint_fast64_t:t(4,26)=(4,8)",128,0,253,0
	.stabs	"intmax_t:t(4,27)=(4,7)",128,0,273,0
	.stabs	"uintmax_t:t(4,28)=(4,8)",128,0,278,0
	.stabn	162,0,0,0
	.stabn	162,0,0,0
	.stabs	"int_farptr_t:t(2,1)=(4,5)",128,0,77,0
	.stabs	"uint_farptr_t:t(2,2)=(4,6)",128,0,81,0
	.stabn	162,0,0,0
	.stabs	"/usr/lib/gcc/avr/4.8.0/include/stddef.h",130,0,0,0
	.stabs	"size_t:t(5,1)=(0,4)",128,0,212,0
	.stabn	162,0,0,0
	.stabs	"/usr/avr/include/avr/io.h",130,0,0,0
	.stabs	"/usr/avr/include/avr/fuse.h",130,0,0,0
	.stabs	"__fuse_t:t(7,1)=(7,2)=s3low:(0,11),0,8;high:(0,11),8,8;extended:(0,11),16,8;;",128,0,244,0
	.stabn	162,0,0,0
	.stabn	162,0,0,0
	.stabn	162,0,0,0
	.stabs	"../usbtiny/usb.h",130,0,0,0
	.stabs	"byte_t:t(8,1)=(0,11)",128,0,13,0
	.stabs	"uint_t:t(8,2)=(0,4)",128,0,14,0
	.stabn	162,0,0,0
	.stabs	" :T(0,48)=eDESCRIPTOR_TYPE_DEVICE:1,DESCRIPTOR_TYPE_CONFIGURATION:2,DESCRIPTOR_TYPE_STRING:3,DESCRIPTOR_TYPE_INTERFACE:4,DESCRIPTOR_TYPE_ENDPOINT:5,;",128,0,0,0
	.stabs	" :T(0,49)=eTX_STATE_IDLE:0,TX_STATE_RAM:1,TX_STATE_ROM:2,TX_STATE_CALLBACK:3,;",128,0,0,0
	.section	.text.usb_init,"ax",@progbits
	.stabs	"usb_init:F(0,47)",36,0,373,usb_init
.global	usb_init
	.type	usb_init, @function
usb_init:
	.stabd	46,0,0
	.stabn	68,0,374,.LM0-.LFBB1
.LM0:
.LFBB1:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	.stabn	68,0,375,.LM1-.LFBB1
.LM1:
	in r24,0x35
	ori r24,lo8(3)
	out 0x35,r24
	.stabn	68,0,376,.LM2-.LFBB1
.LM2:
	in r24,0x3b
	ori r24,lo8(64)
	out 0x3b,r24
	.stabn	68,0,384,.LM3-.LFBB1
.LM3:
/* #APP */
 ;  384 "../usbtiny/usb.c" 1
	sei
 ;  0 "" 2
/* #NOAPP */
	ret
	.size	usb_init, .-usb_init
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
	.section	.text.usb_poll,"ax",@progbits
	.stabs	"usb_poll:F(0,47)",36,0,393,usb_poll
.global	usb_poll
	.type	usb_poll, @function
usb_poll:
	.stabd	46,0,0
	.stabn	68,0,394,.LM4-.LFBB2
.LM4:
.LFBB2:
	push r17
	push r28
	push r29
/* prologue: function */
/* frame size = 0 */
/* stack size = 3 */
.L__stack_usage = 3
	.stabn	68,0,398,.LM5-.LFBB2
.LM5:
	lds r22,usb_rx_len
	tst r22
	brne .+2
	rjmp .L3
	.stabn	68,0,400,.LM6-.LFBB2
.LM6:
	lds r24,usb_rx_off
	ldi r28,lo8(12)
	ldi r29,0
	sub r28,r24
	sbc r29,__zero_reg__
	subi r28,lo8(-(usb_rx_buf))
	sbci r29,hi8(-(usb_rx_buf))
.LBB7:
.LBB8:
	.stabn	68,0,202,.LM7-.LFBB2
.LM7:
	ldi r24,lo8(1)
	sts usb_tx_state,r24
	.stabn	68,0,204,.LM8-.LFBB2
.LM8:
	lds r24,usb_rx_token
	cpi r24,lo8(45)
	breq .+2
	rjmp .L4
	.stabn	68,0,206,.LM9-.LFBB2
.LM9:
	ldd r17,Y+6
	.stabn	68,0,207,.LM10-.LFBB2
.LM10:
	ldd r24,Y+7
	cpse r24,__zero_reg__
	.stabn	68,0,209,.LM11-.LFBB2
.LM11:
	ldi r17,lo8(-1)
.L5:
	.stabn	68,0,211,.LM12-.LFBB2
.LM12:
	ld r24,Y
	andi r24,lo8(96)
	.stabn	68,0,212,.LM13-.LFBB2
.LM13:
	brne .L6
	.stabn	68,0,214,.LM14-.LFBB2
.LM14:
	ldd r24,Y+1
	cpse r24,__zero_reg__
	rjmp .L7
	.stabn	68,0,220,.LM15-.LFBB2
.LM15:
	st Y,__zero_reg__
	.stabn	68,0,222,.LM16-.LFBB2
.LM16:
	std Y+1,__zero_reg__
	.stabn	68,0,216,.LM17-.LFBB2
.LM17:
	ldi r24,lo8(2)
	rjmp .L8
.L7:
	.stabn	68,0,224,.LM18-.LFBB2
.LM18:
	cpi r24,lo8(5)
	brne .L9
	.stabn	68,0,226,.LM19-.LFBB2
.LM19:
	ldd r24,Y+2
	sts usb_new_address,r24
	rjmp .L10
.L9:
	.stabn	68,0,231,.LM20-.LFBB2
.LM20:
	cpi r24,lo8(6)
	brne .L11
	.stabn	68,0,233,.LM21-.LFBB2
.LM21:
	ldi r24,lo8(2)
	sts usb_tx_state,r24
	.stabn	68,0,234,.LM22-.LFBB2
.LM22:
	ldd r24,Y+3
	cpi r24,lo8(1)
	breq .L33
	.stabn	68,0,239,.LM23-.LFBB2
.LM23:
	cpi r24,lo8(2)
	breq .L34
	.stabn	68,0,245,.LM24-.LFBB2
.LM24:
	cpi r24,lo8(3)
	breq .+2
	rjmp .L10
	.stabn	68,0,247,.LM25-.LFBB2
.LM25:
	ldd r24,Y+2
	tst r24
	breq .L35
	.stabn	68,0,260,.LM26-.LFBB2
.LM26:
	cpi r24,lo8(2)
	breq .+2
	rjmp .L10
	.stabn	68,0,263,.LM27-.LFBB2
.LM27:
	ldi r24,lo8(22)
	.stabn	68,0,262,.LM28-.LFBB2
.LM28:
	ldi r28,lo8(string_device)
	ldi r29,hi8(string_device)
	rjmp .L8
.L11:
	.stabn	68,0,276,.LM29-.LFBB2
.LM29:
	cpi r24,lo8(8)
	brne .L13
	.stabn	68,0,278,.LM30-.LFBB2
.LM30:
	ldi r24,lo8(1)
	st Y,r24
	rjmp .L8
.L13:
	.stabn	68,0,281,.LM31-.LFBB2
.LM31:
	cpi r24,lo8(10)
	breq .+2
	rjmp .L10
	.stabn	68,0,283,.LM32-.LFBB2
.LM32:
	st Y,__zero_reg__
	.stabn	68,0,284,.LM33-.LFBB2
.LM33:
	ldi r24,lo8(1)
	rjmp .L8
.L6:
	.stabn	68,0,289,.LM34-.LFBB2
.LM34:
	movw r24,r28
	rcall usb_setup
	.stabn	68,0,291,.LM35-.LFBB2
.LM35:
	cpi r24,lo8(-1)
	brne .L8
	.stabn	68,0,293,.LM36-.LFBB2
.LM36:
	ldi r25,lo8(3)
	sts usb_tx_state,r25
	rjmp .L8
.L33:
	.stabn	68,0,237,.LM37-.LFBB2
.LM37:
	ldi r24,lo8(18)
	.stabn	68,0,236,.LM38-.LFBB2
.LM38:
	ldi r28,lo8(descr_device)
	ldi r29,hi8(descr_device)
	rjmp .L8
.L34:
	.stabn	68,0,242,.LM39-.LFBB2
.LM39:
	ldi r24,lo8(18)
	.stabn	68,0,241,.LM40-.LFBB2
.LM40:
	ldi r28,lo8(descr_config)
	ldi r29,hi8(descr_config)
	rjmp .L8
.L35:
	.stabn	68,0,250,.LM41-.LFBB2
.LM41:
	ldi r24,lo8(4)
	.stabn	68,0,249,.LM42-.LFBB2
.LM42:
	ldi r28,lo8(string_langid)
	ldi r29,hi8(string_langid)
.L8:
	.stabn	68,0,297,.LM43-.LFBB2
.LM43:
	cp r17,r24
	brlo .L14
.L30:
	.stabn	68,0,279,.LM44-.LFBB2
.LM44:
	mov r17,r24
.L14:
	.stabn	68,0,301,.LM45-.LFBB2
.LM45:
	sts usb_tx_data+1,r29
	sts usb_tx_data,r28
	rjmp .L15
.L4:
.LBE8:
.LBE7:
	.stabn	68,0,400,.LM46-.LFBB2
.LM46:
	subi r22,lo8(-(-3))
.LBB11:
.LBB9:
	.stabn	68,0,304,.LM47-.LFBB2
.LM47:
	breq .L37
	.stabn	68,0,306,.LM48-.LFBB2
.LM48:
	movw r24,r28
	rcall usb_out
.L37:
	.stabn	68,0,203,.LM49-.LFBB2
.LM49:
	ldi r17,0
.L15:
	.stabn	68,0,309,.LM50-.LFBB2
.LM50:
	sts usb_tx_total,r17
	.stabn	68,0,310,.LM51-.LFBB2
.LM51:
	ldi r24,lo8(-61)
	sts usb_tx_buf,r24
.LBE9:
.LBE11:
	.stabn	68,0,401,.LM52-.LFBB2
.LM52:
	sts usb_tx_len,__zero_reg__
	.stabn	68,0,402,.LM53-.LFBB2
.LM53:
	sts usb_rx_len,__zero_reg__
.L3:
	.stabn	68,0,405,.LM54-.LFBB2
.LM54:
	lds r24,usb_tx_len
	cpse r24,__zero_reg__
	rjmp .L17
	.stabn	68,0,405,.LM55-.LFBB2
.LM55:
	lds r24,usb_tx_state
	tst r24
	brne .+2
	rjmp .L17
.LBB12:
.LBB13:
	.stabn	68,0,324,.LM56-.LFBB2
.LM56:
	lds r25,usb_tx_buf
	ldi r18,lo8(-120)
	eor r25,r18
	sts usb_tx_buf,r25
	.stabn	68,0,325,.LM57-.LFBB2
.LM57:
	lds r17,usb_tx_total
	.stabn	68,0,326,.LM58-.LFBB2
.LM58:
	cpi r17,lo8(9)
	brsh .L38
	.stabn	68,0,331,.LM59-.LFBB2
.LM59:
	tst r17
	breq .L20
	rjmp .L19
.L38:
	.stabn	68,0,328,.LM60-.LFBB2
.LM60:
	ldi r17,lo8(8)
.L19:
	.stabn	68,0,334,.LM61-.LFBB2
.LM61:
	cpi r24,lo8(3)
	brne .L21
	.stabn	68,0,336,.LM62-.LFBB2
.LM62:
	mov r22,r17
	ldi r24,lo8(usb_tx_buf+1)
	ldi r25,hi8(usb_tx_buf+1)
	rcall usb_in
	mov r17,r24
	rjmp .L22
.L21:
	.stabn	68,0,341,.LM63-.LFBB2
.LM63:
	lds r30,usb_tx_data
	lds r31,usb_tx_data+1
	.stabn	68,0,342,.LM64-.LFBB2
.LM64:
	cpi r24,lo8(1)
	brne .L23
	movw r26,r30
	ldi r20,lo8(usb_tx_buf+1)
	ldi r21,hi8(usb_tx_buf+1)
	movw r28,r20
.L25:
	movw r18,r26
	subi r18,-1
	sbci r19,-1
	movw r30,r18
	.stabn	68,0,346,.LM65-.LFBB2
.LM65:
	ld r24,X
	st Y+,r24
	mov r24,r28
	sub r24,r20
	.stabn	68,0,344,.LM66-.LFBB2
.LM66:
	cp r24,r17
	brsh .L24
	movw r26,r18
	rjmp .L25
.L23:
	ldi r18,lo8(usb_tx_buf+1)
	ldi r19,hi8(usb_tx_buf+1)
	.stabn	68,0,342,.LM67-.LFBB2
.LM67:
	movw r26,r18
.L26:
.LBB14:
	.stabn	68,0,353,.LM68-.LFBB2
.LM68:
/* #APP */
 ;  353 "../usbtiny/usb.c" 1
	lpm r24, Z
	
 ;  0 "" 2
/* #NOAPP */
.LBE14:
	.stabn	68,0,355,.LM69-.LFBB2
.LM69:
	st X+,r24
	adiw r30,1
	mov r24,r26
	sub r24,r18
	.stabn	68,0,351,.LM70-.LFBB2
.LM70:
	cp r24,r17
	brlo .L26
.L24:
	.stabn	68,0,358,.LM71-.LFBB2
.LM71:
	sts usb_tx_data+1,r31
	sts usb_tx_data,r30
.L22:
	.stabn	68,0,360,.LM72-.LFBB2
.LM72:
	lds r24,usb_tx_total
	sub r24,r17
	sts usb_tx_total,r24
.L20:
	.stabn	68,0,362,.LM73-.LFBB2
.LM73:
	mov r22,r17
	ldi r24,lo8(usb_tx_buf+1)
	ldi r25,hi8(usb_tx_buf+1)
	rcall crc
	.stabn	68,0,363,.LM74-.LFBB2
.LM74:
	ldi r24,lo8(3)
	add r24,r17
	sts usb_tx_len,r24
	.stabn	68,0,364,.LM75-.LFBB2
.LM75:
	cpi r17,lo8(8)
	brsh .L17
	.stabn	68,0,366,.LM76-.LFBB2
.LM76:
	sts usb_tx_state,__zero_reg__
.L17:
	.stabn	68,0,342,.LM77-.LFBB2
.LM77:
	ldi r24,lo8(10)
.L27:
.LBE13:
.LBE12:
	.stabn	68,0,410,.LM78-.LFBB2
.LM78:
	sbic 0x16,3
	rjmp .L2
	subi r24,lo8(-(-1))
	.stabn	68,0,410,.LM79-.LFBB2
.LM79:
	brne .L27
	.stabn	68,0,415,.LM80-.LFBB2
.LM80:
	sts usb_new_address,__zero_reg__
	.stabn	68,0,416,.LM81-.LFBB2
.LM81:
	sts usb_address,__zero_reg__
	rjmp .L2
.L10:
.LBB15:
.LBB10:
	.stabn	68,0,279,.LM82-.LFBB2
.LM82:
	ldi r24,0
	rjmp .L30
.L2:
/* epilogue start */
.LBE10:
.LBE15:
	.stabn	68,0,421,.LM83-.LFBB2
.LM83:
	pop r29
	pop r28
	pop r17
	ret
	.size	usb_poll, .-usb_poll
	.stabs	"data:r(0,50)=*(8,1)",64,0,393,28
	.stabn	192,0,0,.LBB7-.LFBB2
	.stabn	224,0,0,.LBE7-.LFBB2
	.stabs	"data:r(0,50)",64,0,393,28
	.stabn	192,0,0,.LBB11-.LFBB2
	.stabn	224,0,0,.LBE11-.LFBB2
	.stabs	"len:r(8,1)",64,0,318,17
	.stabs	"src:r(0,50)",64,0,319,30
	.stabn	192,0,0,.LBB13-.LFBB2
	.stabn	224,0,0,.LBE13-.LFBB2
	.stabs	"data:r(0,50)",64,0,393,28
	.stabn	192,0,0,.LBB15-.LFBB2
	.stabn	224,0,0,.LBE15-.LFBB2
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
	.section	.progmem.data,"a",@progbits
	.type	descr_config, @object
	.size	descr_config, 18
descr_config:
	.byte	9
	.byte	2
	.byte	18
	.byte	0
	.byte	1
	.byte	1
	.byte	0
	.byte	-128
	.byte	50
	.byte	9
	.byte	4
	.byte	0
	.byte	0
	.byte	0
	.byte	-1
	.byte	0
	.byte	0
	.byte	0
	.type	descr_device, @object
	.size	descr_device, 18
descr_device:
	.byte	18
	.byte	1
	.byte	1
	.byte	1
	.byte	-1
	.byte	0
	.byte	0
	.byte	8
	.byte	-127
	.byte	23
	.byte	-97
	.byte	12
	.byte	6
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.type	string_langid, @object
	.size	string_langid, 4
string_langid:
	.byte	4
	.byte	3
	.byte	9
	.byte	4
.global	string_device
	.type	string_device, @object
	.size	string_device, 22
string_device:
	.byte	22
	.byte	3
	.string	"U"
	.string	"S"
	.string	"B"
	.string	"t"
	.string	"i"
	.string	"n"
	.string	"y"
	.string	"I"
	.string	"S"
	.string	"P"
	.local	usb_tx_data
	.comm	usb_tx_data,2,1
	.local	usb_tx_total
	.comm	usb_tx_total,1,1
	.local	usb_tx_state
	.comm	usb_tx_state,1,1
	.comm	usb_new_address,1,1
	.comm	usb_address,1,1
	.comm	usb_tx_len,1,1
	.comm	usb_tx_buf,11,1
	.comm	usb_rx_token,1,1
	.comm	usb_rx_len,1,1
	.comm	usb_rx_off,1,1
	.comm	usb_rx_buf,22,1
	.stabs	"usb_tx_state:S(8,1)",40,0,76,usb_tx_state
	.stabs	"usb_tx_total:S(8,1)",40,0,77,usb_tx_total
	.stabs	"usb_tx_data:S(0,50)",40,0,78,usb_tx_data
	.stabs	"string_langid:S(0,51)=ar(0,52)=r(0,52);0;0177777;;0;3;(0,53)=k(8,1)",38,0,132,string_langid
	.stabs	"descr_device:S(0,54)=ar(0,52);0;17;(0,53)",38,0,141,descr_device
	.stabs	"descr_config:S(0,54)",38,0,160,descr_config
	.stabs	"usb_rx_buf:G(0,55)=ar(0,52);0;21;(8,1)",32,0,53,0
	.stabs	"usb_rx_off:G(8,1)",32,0,54,0
	.stabs	"usb_rx_len:G(8,1)",32,0,55,0
	.stabs	"usb_rx_token:G(8,1)",32,0,56,0
	.stabs	"usb_tx_buf:G(0,56)=ar(0,52);0;10;(8,1)",32,0,58,0
	.stabs	"usb_tx_len:G(8,1)",32,0,59,0
	.stabs	"usb_address:G(8,1)",32,0,61,0
	.stabs	"usb_new_address:G(8,1)",32,0,62,0
	.stabs	"string_device:G(0,57)=k(0,58)=s22length:(8,1),0,8;type:(8,1),8,8;string:(0,59)=ar(0,52);0;9;(0,1),16,160;;",32,0,103,0
	.text
	.stabs	"",100,0,0,.Letext0
.Letext0:
	.ident	"GCC: (GNU) 4.8.0"
.global __do_clear_bss
