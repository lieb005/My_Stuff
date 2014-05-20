	.file	"usb.c"
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.stabs	"/home/mark/workspace_c/usbtiny/template/",100,0,2,.Ltext0
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
