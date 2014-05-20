/*
 * atmel_cpu.c
 *
 *  Created on: 01-Mar-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */
#include "atmel_decoder.h"
#include "atmel_operations.h"
#include "atmel_cpu.h"
#include "atmel_flash.h" 	/* used to access memory for loading program into */
#include "atmel_sram.h" 	/* used to access memory for loading data into */
#include <stdio.h>
#include <string.h>

#include "global_types.h"

/* NOT STATIC */ UINT16 atmel_PC = 0;

typedef void(*execute_op)(const instruction_type*);

static const execute_op EXECUTE_LOOKUP[MAX_OPCODES] = {
	op_add,
	op_adc,
	op_adiw,
	op_sub,
	op_subi,
	op_sbc,
	op_sbci,
	op_sbcw,
	op_and,
	op_andi,				//10
	op_or,
	op_ori,
	op_eor,
	op_com,
	op_neg,
	op_inc,
	op_dec,					//20
	op_ser,
	op_mul,
	op_muls,
	op_mulsu,
	op_fmul,
	op_fmuls,
	op_fmulsu,
	op_des,
	op_rjmp,		//30
	op_ijmp,
	op_eijmp,
	op_jmp,
	op_rcall,
	op_icall,
	op_eicall,
	op_call,
	op_ret,
	op_reti,
	op_cpse,		//40
	op_cp,
	op_cpc,
	op_cpi,
	op_sbrc,
	op_sbrs,
	op_sbic,
	op_sbis,
	op_brbs,
	op_brbc,
	op_breq,		//50
	op_brne,
	op_brcs,
	op_brcc,
	op_brsh,
	op_brlo,
	op_brmi,
	op_brpl,
	op_brge,
	op_brlt,
	op_brhs,		//60
	op_brhc,
	op_brts,
	op_brtc,
	op_brvs,
	op_brvc,
	op_brie,
	op_brid,
	op_mov,
	op_movw,
	op_ldi,		//70
	op_lds,
	op_ld_1,
	op_ld_2,
	op_ld_3,
	op_ldd_1,
	op_ldd_2,
	op_ldd_3,
	op_ldd_5,
	op_ldd_6,		//80
	op_ldd_7,
	op_sts,
	op_st_1,
	op_st_2,
	op_st_3,
	op_std_1,
	op_std_2,
	op_std_3,
	op_std_4,
	op_std_5,		//90
	op_std_6,
	op_lpm_1,
	op_lpm_2,
	op_lpm_3,
	op_elpm_1,
	op_elpm_2,
	op_elpm_3,
	op_spm,
	op_spm_2_1,
	op_spm_2_2,		//100
	op_in,
	op_out,
	op_push,
	op_pop,
	op_lsl,
	op_lsr,
	op_rol,
	op_ror,
	op_asr,
	op_swap,
	op_bset,				//110
	op_bclr,
	op_sbi,
	op_cbi,
	op_bst,
	op_bld,
	op_sec,
	op_clc,
	op_sen,
	op_cln,
	op_sez,		//120
	op_clz,
	op_sei,
	op_cli,
	op_ses,
	op_cls,
	op_sev,
	op_clv,
	op_set,
	op_clt,
	op_seh,		//130
	op_clh,
	op_break,
	op_nop,
	op_sleep,
	op_wdr
};

void init_atmel(void)
{
	const UINT16 sp_memsize = DATA_MEMORY_SIZE - 2;

	init_decoder();
	init_program_memory();
	init_data_memory();

	/* initialise the stack pointer */
	write_data_memory(
		REGISTER_SP,
		(UINT8*)&sp_memsize,
		sizeof(UINT16));

	atmel_PC = 0;
}

void atmel_fetch_execute(const UINT32 start_address)
{
	UINT8* data = get_program_memory(0);
	instruction_type instruction = { 0 };

	atmel_PC = start_address;

	while(TRUE)
	{
		inst_decode_result_type decode_res;

		memset( &instruction, 0, sizeof(instruction) );

		//decode
		decode_res = decode_opcode(
			(UINT16*)(data + atmel_PC),
			&instruction);

#ifdef _DEBUG
		printf("PC 0x%04X\tOpcode 0x%04X\t\t", atmel_PC, *((UINT16*)(data + atmel_PC)));
#endif

		if(decode_res != INST_DECODED_OK)
		{
			if(decode_res == INST_DECODED_UNKNOWN_OPCODE)
				printf("Unknown OpCode encountered during decoding\n");
			else
				printf("Unknown error encountered during decoding\n");
			break;
		}

		//execute
		EXECUTE_LOOKUP[instruction.op_code](&instruction);
	}
}
