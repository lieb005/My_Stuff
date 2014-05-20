/*
 * atmel_operations.h
 *
 *  Created on: 01-Mar-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */
#ifndef ATMEL_OPERATIONS_H_
#define ATMEL_OPERATIONS_H_

/* register addresses */
#define STATUS_REGISTER_ADDRESS	0x5F //TODO: check this is accurate

#define REGISTER_0 0
#define REGISTER_Z 30
#define REGISTER_EIND 0x29
#define REGISTER_SP 0x5D

UINT8* get_status_register();

#define STATUS_REG_I	0x80
#define STATUS_REG_T	0x40
#define STATUS_REG_H	0x20
#define STATUS_REG_S	0x10
#define STATUS_REG_V	0x08
#define STATUS_REG_N	0x04
#define STATUS_REG_Z	0x02
#define STATUS_REG_C	0x01

void set_status_reg_flag(UINT8 register_mask, boolean value);

//FIXME: temporary place holder for not implemented opcodes
void op_not_implemented(const instruction_type *instr);

void op_add(const instruction_type *instr);
void op_adc(const instruction_type *instr);
void op_adiw(const instruction_type *instr);
void op_sub(const instruction_type *instr);
void op_subi(const instruction_type *instr);
void op_sbc(const instruction_type *instr);
void op_sbci(const instruction_type *instr);
void op_sbcw(const instruction_type *instr);
void op_and(const instruction_type *instr);
void op_andi(const instruction_type *instr);
void op_or(const instruction_type *instr);
void op_ori(const instruction_type *instr);
void op_eor(const instruction_type *instr);
void op_com(const instruction_type *instr);
void op_neg(const instruction_type *instr);
void op_inc(const instruction_type *instr);
void op_dec(const instruction_type *instr);
void op_ser(const instruction_type *instr);
void op_mul(const instruction_type *instr);
void op_muls(const instruction_type *instr);
void op_mulsu(const instruction_type *instr);
void op_fmul(const instruction_type *instr);
void op_fmuls(const instruction_type *instr);
void op_fmulsu(const instruction_type *instr);
void op_des(const instruction_type *instr);
void op_rjmp(const instruction_type *instr);
void op_ijmp(const instruction_type *instr);
void op_eijmp(const instruction_type *instr);
void op_jmp(const instruction_type *instr);
void op_rcall(const instruction_type *instr);
void op_icall(const instruction_type *instr);
void op_eicall(const instruction_type *instr);
void op_call(const instruction_type *instr);
void op_ret(const instruction_type *instr);
void op_reti(const instruction_type *instr);
void op_cpse(const instruction_type *instr);
void op_cp(const instruction_type *instr);
void op_cpc(const instruction_type *instr);
void op_cpi(const instruction_type *instr);
void op_sbrc(const instruction_type *instr);
void op_sbrs(const instruction_type *instr);
void op_sbic(const instruction_type *instr);
void op_sbis(const instruction_type *instr);
void op_brbs(const instruction_type *instr);
void op_brbc(const instruction_type *instr);
void op_breq(const instruction_type *instr);
void op_brne(const instruction_type *instr);
void op_brcs(const instruction_type *instr);
void op_brcc(const instruction_type *instr);
void op_brsh(const instruction_type *instr);
void op_brlo(const instruction_type *instr);
void op_brmi(const instruction_type *instr);
void op_brpl(const instruction_type *instr);
void op_brge(const instruction_type *instr);
void op_brlt(const instruction_type *instr);
void op_brhs(const instruction_type *instr);
void op_brhc(const instruction_type *instr);
void op_brts(const instruction_type *instr);
void op_brtc(const instruction_type *instr);
void op_brvs(const instruction_type *instr);
void op_brvc(const instruction_type *instr);
void op_brie(const instruction_type *instr);
void op_brid(const instruction_type *instr);
void op_mov(const instruction_type *instr);
void op_movw(const instruction_type *instr);
void op_ldi(const instruction_type *instr);
void op_lds(const instruction_type *instr);
void op_ld_1(const instruction_type *instr);
void op_ld_2(const instruction_type *instr);
void op_ld_3(const instruction_type *instr);
void op_ldd_1(const instruction_type *instr);
void op_ldd_2(const instruction_type *instr);
void op_ldd_3(const instruction_type *instr);
void op_ldd_5(const instruction_type *instr);
void op_ldd_6(const instruction_type *instr);
void op_ldd_7(const instruction_type *instr);
void op_sts(const instruction_type *instr);
void op_st_1(const instruction_type *instr);
void op_st_2(const instruction_type *instr);
void op_st_3(const instruction_type *instr);
void op_std_1(const instruction_type *instr);
void op_std_2(const instruction_type *instr);
void op_std_3(const instruction_type *instr);
void op_std_4(const instruction_type *instr);
void op_std_5(const instruction_type *instr);
void op_std_6(const instruction_type *instr);
void op_lpm_1(const instruction_type *instr);
void op_lpm_2(const instruction_type *instr);
void op_lpm_3(const instruction_type *instr);
void op_elpm_1(const instruction_type *instr);
void op_elpm_2(const instruction_type *instr);
void op_elpm_3(const instruction_type *instr);
void op_spm(const instruction_type *instr);
void op_spm_2_1(const instruction_type *instr);
void op_spm_2_2(const instruction_type *instr);
void op_in(const instruction_type *instr);
void op_out(const instruction_type *instr);
void op_push(const instruction_type *instr);
void op_pop(const instruction_type *instr);
void op_lsl(const instruction_type *instr);
void op_lsr(const instruction_type *instr);
void op_rol(const instruction_type *instr);
void op_ror(const instruction_type *instr);
void op_asr(const instruction_type *instr);
void op_swap(const instruction_type *instr);
void op_bset(const instruction_type *instr);
void op_bclr(const instruction_type *instr);
void op_sbi(const instruction_type *instr);
void op_cbi(const instruction_type *instr);
void op_bst(const instruction_type *instr);
void op_bld(const instruction_type *instr);
void op_sec(const instruction_type *instr);
void op_clc(const instruction_type *instr);
void op_sen(const instruction_type *instr);
void op_cln(const instruction_type *instr);
void op_sez(const instruction_type *instr);
void op_clz(const instruction_type *instr);
void op_sei(const instruction_type *instr);
void op_cli(const instruction_type *instr);
void op_ses(const instruction_type *instr);
void op_cls(const instruction_type *instr);
void op_sev(const instruction_type *instr);
void op_clv(const instruction_type *instr);
void op_set(const instruction_type *instr);
void op_clt(const instruction_type *instr);
void op_seh(const instruction_type *instr);
void op_clh(const instruction_type *instr);
void op_break(const instruction_type *instr);
void op_nop(const instruction_type *instr);
void op_sleep(const instruction_type *instr);
void op_wdr(const instruction_type *instr);
#endif
