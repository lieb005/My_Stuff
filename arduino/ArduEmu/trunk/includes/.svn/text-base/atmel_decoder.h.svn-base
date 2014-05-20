/*
 * atmel_decoder.h
 *
 *  Created on: 22-Feb-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#ifndef ATMEL_DECODER_H_
#define ATMEL_DECODER_H_

#include "global_types.h"

#define REGISTER_SIZE 5
#define IO_ADDRESS_SIZE 6
#define INDIRECT_DATA_ADDRESS_SIZE 6
#define DIRECT_PROG_ADDRESS_SIZE 24
#define REL_PROG_ADDRESS_SIZE 12

/*
 * this type lists all the program, data
 * and addressing modes
 */
typedef enum
{
	NO_PARAM	= 0,
	RD_5		= 1,	/* Rd */
	RR_5_RD_5	= 2,	/* Rr, Rd */
	RD_K		= 3, 	/* Rd, K */
	K_RD_K		= 4,	/* K, Rd, K */
	SSS			= 5,	/* sss */
	KKKK_SSS	= 6,	/* kkkkkkk, sss */
	RD_BBB		= 7,	/* Rb, bbb */
	CALL_PARAM	= 8,
	KKKK		= 9, 	/* KKKK */
	RR_3_RD_3	= 10,	/* Rrrr, Rddd */
	RD_AAAAA	= 11,	/* Rd, AAAAA */
	RD_BIG_K	= 12,	/* Rd, K16 */
	RR_4_RD_4	= 13,	/* Rrrrr, Rdddd */
	BIG_K		= 14,	/* K * 12 */
	AAAAA_BBB	= 15,	/* AAAAA, bbb */
	K2_RD_K4	= 16,	/* KK, Rd, KKKK */
	RD_4		= 17,	/* Rdddd */
	RD_5_Q		= 18	/* Rd, Q */
} amtel_param_type;

/*
 * this type is for a register access
 * see REGISTER_SIZE
 */
typedef UINT8	register_type;

/*
 * this type is for an IO access
 * see IO_ADDRESS_SIZE
 */
typedef UINT8	io_address_type;

/*
 * this type is for a data address access
 * see INDIRECT_DATA_ADDRESS_SIZE
 */
typedef UINT16	data_address_type;

/*
 * this type is for a direct program address access
 * see DIRECT_PROG_ADDRESS_SIZE
 */
typedef UINT32	direct_prog_address_type;

/*
 * this type is for a relative (indirect) program address access
 * see REL_PROG_ADDRESS_SIZE
 */
typedef UINT16	relative_prog_address_type;

typedef enum
{
	INST_DECODED_UNKNOWN = 0,
	INST_DECODED_OK = 1,
	INST_DECODED_UNKNOWN_OPCODE = 2,
} inst_decode_result_type;

/*
 * this type lists all the possible op-codes
 */
typedef enum
{
	/* Arithmetic & Logic Instructions */
	ADD = 0,
	ADC,
	ADIW,
	SUB,
	SUBI,
	SBC,
	SBCI,
	SBIW,
	AND,
	ANDI,	
	OR,		//10
	ORI,
	EOR,
	COM,
	NEG,
	INC,
	DEC,
	SER,
	MUL,
	MULS,	//20
	MULSU,
	FMUL,
	FMULS,
	FMULSU,
	DES,
	RJMP,
	IJMP,
	EIJMP,
	JMP,
	RCALL,	//30
	ICALL,
	EICALL,
	CALL,
	RET,
	RETI,
	CPSE,
	CP,
	CPC,
	CPI,
	SBRC,	//40
	SBRS,
	SBIC,
	SBIS,
	BRBS,
	BRBC,
	BREQ,
	BRNE,
	BRCS,
	BRCC,
	BRSH,	//50
	BRLO,
	BRMI,
	BRPL,
	BRGE,
	BRLT,
	BRHS,
	BRHC,
	BRTS,
	BRTC,
	BRVS,	//60
	BRVC,
	BRIE,
	BRID,
	/* Data Transfer Instructions */
	MOV,
	MOVW,
	LDI,	
	LDS,
	LD_1,
	LD_2,
	LD_3,	//70
	LDD_1,
	LDD_2,
	LDD_3,
	LDD_5,
	LDD_6,
	LDD_7,
	STS,
	ST_1,
	ST_2,
	ST_3,	//80
	STD_1,
	STD_2,
	STD_3,
	STD_4,
	STD_5,
	STD_6,	
	LPM_1,
	LPM_2,
	LPM_3,
	ELPM_1,	//90
	ELPM_2,
	ELPM_3,
	SPM,
	SPM_2_1,
	SPM_2_2,
	IN_,
	OUT_,
	PUSH,
	POP,
	LSL,	//100
	LSR,
	ROL,
	ROR,
	ASR,
	SWAP,
	BSET,
	BCLR,
	SBI,
	CBI,
	BST,	//110
	BLD,
	SEC,
	CLC,
	SEN,
	CLN,
	SEZ,
	CLZ,
	SEI,
	CLI,
	SES,	//120
	CLS,
	SEV,
	CLV,
	SET,
	CLT,
	SEH,
	CLH,
	/* MCU Control Instructions */
	BREAK,
	NOP,
	SLEEP,	//130
	WDR
} op_code_type;
#define MAX_OPCODES WDR + 1

/*
 * this type is used to mask out all bits
 * except the op-code
 */
typedef UINT16 op_code_mask_type;

/*
 * this structure contains all the data
 * inside an instruction
 */
typedef struct
{
	op_code_mask_type	op_code_value;
	op_code_type		op_code;
	amtel_param_type	param_type;

	union
	{
		struct
		{
			register_type		rr : REGISTER_SIZE;
			register_type		rd : REGISTER_SIZE;
		} rd_rr;

		struct
		{
			register_type		rd : REGISTER_SIZE;
			data_address_type	k;
		} rd_k;

		register_type		sss;

		struct
		{
			register_type	sss;
			data_address_type k;
		} kkkkkkk_sss;

		struct
		{
			register_type		rd : REGISTER_SIZE;
			register_type		bbb;
		} rd_bbb;

		struct
		{
			register_type		rd : REGISTER_SIZE;
			io_address_type		aaaaa;
		} rd_aaaaa;

		struct
		{
			io_address_type		io;
			register_type		bit : 3;
		} aaaaa_bbb;

		struct
		{
			register_type		rd : REGISTER_SIZE;
			data_address_type	q : INDIRECT_DATA_ADDRESS_SIZE;
		} reg_with_displ;

		UINT32 call;
		data_address_type kkkk;

	} parameters;

} instruction_type;

void init_decoder(void);

/*
 * this procedure takes a 16bit short and decodes the opcode
 */
inst_decode_result_type decode_opcode(
		const UINT16 *raw_opcode,
		instruction_type* instruction);

#endif /* ATMEL_DECODER_H_ */
