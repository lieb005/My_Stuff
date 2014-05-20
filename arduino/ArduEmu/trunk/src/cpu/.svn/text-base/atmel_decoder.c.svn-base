/*
 * atmel_decoder.c
 *
 *  Created on: 22-Feb-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */
#include "atmel_decoder.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bin_utils.h"
#include "global_types.h"

/*
 * this structure contains data needed to
 * work out the opcode based on a 16bit value
 */
typedef struct
{

	/* this attribute stores the bitmap for the opcode */
	op_code_mask_type	op_code_mask;

	op_code_mask_type	op_code_bits_mask;

	/* this attribute stores the mask we apply to get
	 * the bits which tell us the opcode value
	 */
	op_code_type		op_code;

	amtel_param_type	param_type;

} instruction_info_type;

/*
 * this type is used as a pointer an operation
 * that will take a opcode and decode its paramters
 */
typedef void(*decode_parameter_type) (
		const UINT16*,
		instruction_type*);

const static UINT8 ATMEL_INSTRUCTION_TABLE_SIZE[16]=
{
	/* 0x0000 */ 10,
	/* 0x1000 */ 4,
	/* 0x2000 */ 4,
	/* 0x3000 */ 1,
	/* 0x4000 */ 1,
	/* 0x5000 */ 1,
	/* 0x6000 */ 2,
	/* 0x7000 */ 1,
	/* 0x8000 */ 6,
	/* 0x9000 */ 54,
	/* 0xA000 */ 1,
	/* 0xB000 */ 2,
	/* 0xC000 */ 1,
	/* 0xD000 */ 1,
	/* 0xE000 */ 2,
	/* 0xF000 */ 6,
};

/*
 * lookup table with bit masks to mask out data (so
 * we're left with just opcode data) and the bitmap
 * for the opcode itself.
 *
 * we store the parameter type for it (incase it's
 * generic and we can only write a few param decoders)
 */
const static instruction_info_type ATMEL_INSTRUCTION_LOOKUP[16][54] =
{
	{	/* 0x0000 */ 
		{	0x0C00, 0xFC00,	ADD, 	RR_5_RD_5 },
		{	0x0100,	0xFF00, MOVW, 	RR_4_RD_4 },
		{	0x0200,	0xFF00, MULS, 	RR_4_RD_4 },
		{	0x0300, 0xFF88, MULSU, 	RR_3_RD_3 },
		{	0x0000, 0xFFFF, NOP, 	NO_PARAM },
		{	0x0800, 0xFC00, SBC, 	RR_5_RD_5 },
		{	0x0400,	0xFC00, CPC, 	RR_5_RD_5 },
		{	0x0308,	0xFF88, FMUL, 	RR_3_RD_3 },
		{	0x0380, 0xFF88, FMULS, 	RR_3_RD_3 },
		{	0x0388,	0xFF88, FMULSU, RR_3_RD_3 },
	},
	{	/* 0x1000 */ 
		{	0x1C00, 0xFC00,	ADC, 	RR_5_RD_5 },
		{	0x1400, 0xFC00, CP, 	RR_5_RD_5 },
		{	0x1000, 0xFC00, CPSE, 	RR_5_RD_5 },
		{	0x1800, 0xFC00, SUB, 	RR_5_RD_5 }
	},
	{	/* 0x2000 */ 
		{	0x2000, 0xFC00,	AND, 	RR_5_RD_5 },
		{	0x2400,	0xFC00, EOR, 	RR_5_RD_5 },
		{	0x2C00, 0xFC00, MOV, 	RR_5_RD_5 },
		{	0x2800, 0xFC00, OR, 	RR_5_RD_5 }
	},
	{	/* 0x3000 */ 
		{	0x3000, 0xF000, CPI, 	K_RD_K }
	},
	{	/* 0x4000 */ 
		{	0x4000, 0xF000, SBCI, 	K_RD_K }
	},
	{	/* 0x5000 */ 
		{	0x5000, 0xF000, SUBI, 	K_RD_K }
	}, 
	{	/* 0x6000 */
		{	0x6000,	0xF000, ORI, 	K_RD_K },
	}, 
	{	/* 0x7000 */
		{	0x7000, 0xF000,	ANDI,	K_RD_K }
	}, 
	{	/* 0x8000 */
		{	0x8008, 0xFE0F, LDD_1, 	RD_5 },
		{	0x8009, 0xFE0F, LDD_2, 	RD_5 },
		{	0x800A, 0xFE0F, LDD_3, 	RD_5_Q },
		{	0x8000,	0xFE0F, LDD_5, 	RD_5 },
		{	0x8208, 0xD208, STD_3,	RD_5_Q },
		{	0x8200,	0xD208, STD_6,	RD_5_Q }
	},
	{	/* 0x9000 */

		/* -- high priority -- */
		{	0x9488, 0xFF8F,	BCLR,	SSS },
		{	0x9408, 0xFF8F, BSET, 	SSS},
		{	0x940E, 0xFE0E, CALL, 	CALL_PARAM},
		
		{	0x9403,	0xFE0F, INC, 	RD_5 },
		{	0x940A, 0xFE0F, DEC, 	RD_5 },
		{	0x940C, 0xFE0E, JMP, 	CALL_PARAM },
		{	0x9C00,	0xFC00, MUL, 	RR_5_RD_5 },
		{	0x9401, 0xFE0F, NEG, 	RD_5 },
		{	0x900F, 0xFE0F, POP, 	RD_5 },
		{	0x920F, 0xFE0F, PUSH, 	RD_5 },
		{	0x9508, 0xFFFF, RET, 	NO_PARAM },
		{	0x9518,	0xFFFF, RETI, 	NO_PARAM },

		/* -- average priority -- */
		{	0x900C,	0xFE0F, LD_1, 	RD_5 },
		{	0x900D,	0xFE0F, LD_2, 	RD_5 },
		{	0x900E,	0xFE0F, LD_3, 	RD_5 },
		{	0x9001,	0xFE0F, LDD_6, 	RD_5 },
		{	0x9002,	0xFE0F, LDD_7, 	RD_5_Q },
		{	0x9000,	0xFE0F, LDS, 	RD_BIG_K },
		{	0x95C8,	0xFFFF, LPM_1, 	NO_PARAM },
		{	0x9004, 0xFE0F, LPM_2, 	RD_5 },
		{	0x9005,	0xFE0F, LPM_3, 	RD_5 },
		{	0x920C,	0xFE0F, ST_1,	RD_5 },
		{	0x920D, 0xFE0F, ST_2,	RD_5 },
		{	0x920E,	0xFE0F, ST_3,	RD_5 },
		{	0x9209,	0xFE0F, STD_1,	RD_5 },
		{	0x920A,	0xFE0F,	STD_2,	RD_5 },
		{	0x9201,	0xFE0F, STD_4,	RD_5 },
		{	0x9202,	0xFE0F, STD_5,	RD_5 },
		{	0x9509,	0xFFFF,	ICALL, 	NO_PARAM },
		{	0x9409,	0xFFFF,	IJMP, 	NO_PARAM },

		/* -- low priority -- */
		{ 	0x9405, 0xFE0F, ASR, 	RD_5  },
		{	0x9600, 0xFF00,	ADIW,	RD_K  },
		{	0x9598, 0xFFFF, BREAK, 	NO_PARAM },
		{	0x9800,	0xFF00, CBI, 	RD_BBB },
		{	0x9400, 0xFE0F, COM, 	RD_5 },
		{	0x9519,	0xFFFF, EICALL, NO_PARAM },
		{	0x9419, 0xFFFF, EIJMP, 	NO_PARAM },
		{	0x95D8, 0xFFFF, ELPM_1, NO_PARAM },
		{	0x9006, 0xFE0F, ELPM_2, RD_5 },
		{	0x9007, 0xFE0F, ELPM_3, RD_5 },
		{	0x9406,	0xFE0F, LSR, 	RD_5 },
		{	0x9407, 0xFE0F, ROR, 	RD_5 },
		{	0x9A00, 0xFF00, SBI, 	AAAAA_BBB },
		{	0x9900, 0xFF00, SBIC, 	AAAAA_BBB },
		{	0x9B00, 0xFF00, SBIS, 	AAAAA_BBB },
		{	0x9700, 0xFF00, SBIW, 	K2_RD_K4 },
		{	0x9588, 0xFFFF, SLEEP, 	NO_PARAM },
		{	0x95E8, 0xFFFF, SPM, 	NO_PARAM },
		{	0x95E8, 0xFFFF, SPM_2_1,NO_PARAM },
		{	0x95F8, 0xFFFF, SPM_2_2,NO_PARAM },
		{	0x9200, 0xFE0F, STS, 	RD_BIG_K },
		{	0x9402, 0xFE0F, SWAP, 	RD_5 },
		{	0x95A8, 0xFFFF, WDR, 	NO_PARAM },
		{	0x940B,	0xFF0F, DES, 	KKKK },
	},
	{	/* 0xA000 */ 
		{	0x0000,	0x0000,	0,		0},
	}, 
	{	/* 0xB000 */
		{	0xB000,	0xF800, IN_, 	RD_AAAAA },
		{	0xB800, 0xF800, OUT_, 	RD_AAAAA }
	}, 
	{	/* 0xC000 */
		{	0xC000, 0xF000, RJMP, 	BIG_K }
	}, 
	{	/* 0xD000 */
		{	0xD000, 0xF000, RCALL, 	BIG_K }
	}, 
	{	/* 0xE000 */
		{	0xE000,	0xF000,	LDI, 	K_RD_K },
		{	0xEF0F, 0xFF0F, SER, 	RD_4 }
	}, 
	{	/* 0xF000 */
		{	0xF800, 0xFE08, BLD, 	RR_5_RD_5 },
		{	0xF400, 0xFC00,	BRBC,	KKKK_SSS },
		{	0xF000, 0xFC00,	BRBS, 	KKKK_SSS },
		{	0xFA00,	0xFE08, BST, 	RD_BBB},
		{	0xFC00, 0xFE08, SBRC, 	RD_4 },
		{	0xFE00, 0xFE08, SBRS, 	RD_BBB }
	}
};

/*
 * this constant takes the table above and works out
 * how many entries it contains by dividing its size
 * by the size of an entry
 */
const static UINT32 NO_IMPL_OPCODES
	= (sizeof(ATMEL_INSTRUCTION_LOOKUP) / sizeof(instruction_info_type));

/*
 * this procedure is used to decode the Rd format
 */
void static decode_param_rd(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rr Rd format
 */
void static decode_param_rd_rr(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rd, K format
 */
void static decode_param_rd_k(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rd, K format
 */
void static decode_param_k_rd_k(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rd, K format
 */
void static decode_param_sss(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the KKKKKKK, SSS format
 */
void static decode_param_kkkkkkk_sss(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rd, bbb format
 */
void static decode_param_rd_bbb(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rd, bbb format
 */
void static decode_param_call(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rd, bbb format
 */
void static decode_param_kkkk(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rr, Rd format
 */
void static decode_param_rr3_rd3(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rr, Rd format
 */
void static decode_param_rd_aaaaa(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rd, K*16 format
 */
void static decode_param_rd_big_k(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rrrrr, Rdddd format
 */
void static decode_param_rr4_rd4(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the K*12
 */
void static decode_param_big_k(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the AAAAA, bbb
 */
void static decode_param_aaaaa_bbb(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the K2, Rd, K4
 */
void static decode_param_k2_rd_k4(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rdddd
 */
void static decode_param_rd4(
		const UINT16*,
		instruction_type*);

/*
 * this procedure is used to decode the Rd with displacement (Q)
 */
void static decode_param_rd_with_q(
		const UINT16*,
		instruction_type*);

/*
 * this table is used to lookup the procedure to decode the params
 */
const static decode_parameter_type PARAMETER_DECODER_LOOKUP[] =
{
		NULL,						/* NO_PARAM */
		decode_param_rd,			/* Rddddd */
		decode_param_rd_rr,			/* Rrrrrr, Rdddddd */
		decode_param_rd_k,			/* RD_K */
		decode_param_k_rd_k,		/* K_RD_K */
		decode_param_sss,			/* SSS */
		decode_param_kkkkkkk_sss,	/* KKKK_SSS */
		decode_param_rd_bbb,		/* RD_BBB */
		decode_param_call,			/* See CALL */
		decode_param_kkkk,
		decode_param_rr3_rd3,		/* Rrrr, Rddd */
		decode_param_rd_aaaaa,		/* Rd, AAAAA */
		decode_param_rd_big_k,		/* Rd, K*16 */
		decode_param_rr4_rd4,		/* Rrrrr, Rdddd */
		decode_param_big_k,			/* K * 12 */
		decode_param_aaaaa_bbb,		/* AAAAA, bbb */
		decode_param_k2_rd_k4,		/* KK, Rd, KKKK */
		decode_param_rd4,			/* Rdddd */
		decode_param_rd_with_q,		/* Rd, Q */
};

void init_decoder(void)
{

#ifdef _DEBUG
	/* this code iterates through all the opcode values
	 * to check that the decoder can work them out */
	UINT16 code[2];
	instruction_type inst;

	for ( code[0]=0 ; code[0] < (POW_2_16-1); code[0]++ )
	{
		decode_opcode(
			code,
			&inst);
	}
#endif

}

inst_decode_result_type decode_opcode(
		const UINT16 *raw_opcode,
		instruction_type* instruction)
{
	UINT8 current_inst, short_code;
	boolean found = FALSE;
	instruction_info_type *type = NULL;

	inst_decode_result_type ret = INST_DECODED_OK;

	/* clear out anything already in the instruction */
	memset(instruction, 0, sizeof(instruction_type));

	short_code = (*raw_opcode >> 12) & 0xF;

	for ( current_inst = 0 ; current_inst < ATMEL_INSTRUCTION_TABLE_SIZE[short_code] ; current_inst++)
	{

		UINT16 masked_value = 0;
		type = (instruction_info_type*)&ATMEL_INSTRUCTION_LOOKUP[short_code][current_inst];

		/* create a mask for the opcode bits to get hold
		 * of which bits for each instruction tell us the opcode
		 */
		masked_value = (*raw_opcode
			& type->op_code_bits_mask);

		/* see if the masked value matches the bitmap in the lookup table */
		if ( masked_value == type->op_code_mask )
		{
			instruction->op_code_value =
				(masked_value & type->op_code_mask);
			instruction->op_code = type->op_code;

			found = TRUE;

			break;
		}
	}

	if ( found == TRUE )
	{
		if ( type->param_type != NO_PARAM )
		{
			instruction->param_type = type->param_type;

			PARAMETER_DECODER_LOOKUP[type->param_type]
			                         (raw_opcode,instruction);
		}
	}
	else
	{
		ret = INST_DECODED_UNKNOWN_OPCODE;
	}

	return ret;
}

void decode_param_rd(
		const UINT16	*raw_instruction,
		instruction_type*	inst)
{
	inst->parameters.rd_rr.rd = ((*raw_instruction & 0x1F0) >> 4);
}

void decode_param_rd_rr(
		const UINT16	*raw_instruction,
		instruction_type*	inst)
{
	inst->parameters.rd_rr.rd = ((*raw_instruction & 0x1F0) >> 4);

	inst->parameters.rd_rr.rr = *raw_instruction & 0xF;
	inst->parameters.rd_rr.rr |= ((*raw_instruction & 0x200) >> 5);
}

void decode_param_rd_k(
		const UINT16	*raw_instruction,
		instruction_type*	inst)
{
	inst->parameters.rd_k.rd = (*raw_instruction & 0x30) >> 4;

	inst->parameters.rd_k.k = *raw_instruction & 0xF;
	inst->parameters.rd_k.k |= (*raw_instruction & 0xC0) >> 2;
}

void decode_param_k_rd_k(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.rd_k.rd = (*raw_instruction & 0xF0) >> 4;

	inst->parameters.rd_k.k = (*raw_instruction & 0x0F);
	inst->parameters.rd_k.k |= (*raw_instruction & 0xF00) >> 4;
}


void decode_param_sss(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.sss = (*raw_instruction & 0x70) >> 4;
}

void decode_param_kkkkkkk_sss(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.kkkkkkk_sss.sss = *raw_instruction & 0x07;

	inst->parameters.kkkkkkk_sss.k = (*raw_instruction >> 3) & 0x7F;
}

void decode_param_rd_bbb(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.rd_bbb.rd = (*raw_instruction >> 4) & 0x1F;
	inst->parameters.rd_bbb.bbb = (*raw_instruction & 0x07);
}

void decode_param_call(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	/* get the full 32 bits */
	UINT16 a = *raw_instruction;
	UINT16 b = *(raw_instruction + 0x01);

	/*
	 * it's the entire second short plus some of the first short
	 */
	inst->parameters.call = b;
	inst->parameters.call |= ((a & 0x01) << 16) | (((a >> 4) & 0x1F) << 17);
}

void decode_param_kkkk(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.kkkk = (*raw_instruction >> 4) & 0xF;
}

void decode_param_rr3_rd3(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.rd_rr.rr = (*raw_instruction) & 0x07;
	inst->parameters.rd_rr.rd = ((*raw_instruction) >> 4) & 0x07;
}

void decode_param_rd_aaaaa(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.rd_aaaaa.rd = (((*raw_instruction) >> 4) & 0x1F);
	inst->parameters.rd_aaaaa.aaaaa = ((*raw_instruction) & 0x0F)
		| (((*raw_instruction) >> 5) & 0x30);
}

void decode_param_rd_big_k(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.rd_k.rd = (((*raw_instruction) >> 4)& 0x1F);
	inst->parameters.rd_k.k = *(raw_instruction + sizeof(UINT16));
}

void decode_param_rr4_rd4(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.rd_rr.rd = ((*raw_instruction) >> 4) & 0x0F;
	inst->parameters.rd_rr.rr = (*raw_instruction) & 0x0F;
}

void decode_param_big_k(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.kkkk = (*raw_instruction) & 0x0FFF;
}

void decode_param_aaaaa_bbb(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.aaaaa_bbb.bit = (*raw_instruction) & 0x07;
	inst->parameters.aaaaa_bbb.io = ((*raw_instruction) >> 3) & 0x1F;
}

void decode_param_k2_rd_k4(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.rd_k.k = ((*raw_instruction) & 0x0F)
		| (((*raw_instruction) >> 2) & 0x30);
	inst->parameters.rd_k.rd = ((*raw_instruction) >> 4) & 0x03;
}

void decode_param_rd4(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.rd_rr.rd = ((*raw_instruction) >> 4) & 0x0F;
}

void decode_param_rd_with_q(
		const UINT16 *raw_instruction,
		instruction_type* inst)
{
	inst->parameters.reg_with_displ.rd = ((*raw_instruction) >> 4) & 0x1F;
	inst->parameters.reg_with_displ.q = (*raw_instruction) & 0x07;
	inst->parameters.reg_with_displ.q |= ((*raw_instruction) >> 0x07) & 0x18;
	inst->parameters.reg_with_displ.q |= ((*raw_instruction) >> 0x08) & 0x20;
}
