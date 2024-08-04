#pragma once

#include "types.h"

typedef struct {
    intn rax;
    intn rbx;
    intn rcx;
    intn rsp;
} state_t;

typedef void (*ihc_handler_t)(state_t);

extern ihc_handler_t ihc_handlers[256];

void ihc_init(void);

extern void ihc0_handler(void);
extern void ihc1_handler(void);
extern void ihc2_handler(void);
extern void ihc3_handler(void);
extern void ihc4_handler(void);
extern void ihc5_handler(void);
extern void ihc6_handler(void);
extern void ihc7_handler(void);
extern void ihc8_handler(void);
extern void ihc9_handler(void);
extern void ihc10_handler(void);
extern void ihc11_handler(void);
extern void ihc12_handler(void);
extern void ihc13_handler(void);
extern void ihc14_handler(void);
extern void ihc15_handler(void);
extern void ihc16_handler(void);
extern void ihc17_handler(void);
extern void ihc18_handler(void);
extern void ihc19_handler(void);
extern void ihc20_handler(void);
extern void ihc21_handler(void);
extern void ihc22_handler(void);
extern void ihc23_handler(void);
extern void ihc24_handler(void);
extern void ihc25_handler(void);
extern void ihc26_handler(void);
extern void ihc27_handler(void);
extern void ihc28_handler(void);
extern void ihc29_handler(void);
extern void ihc30_handler(void);
extern void ihc31_handler(void);
extern void ihc32_handler(void);
extern void ihc33_handler(void);
extern void ihc34_handler(void);
extern void ihc35_handler(void);
extern void ihc36_handler(void);
extern void ihc37_handler(void);
extern void ihc38_handler(void);
extern void ihc39_handler(void);
extern void ihc40_handler(void);
extern void ihc41_handler(void);
extern void ihc42_handler(void);
extern void ihc43_handler(void);
extern void ihc44_handler(void);
extern void ihc45_handler(void);
extern void ihc46_handler(void);
extern void ihc47_handler(void);
extern void ihc48_handler(void);
extern void ihc49_handler(void);
extern void ihc50_handler(void);
extern void ihc51_handler(void);
extern void ihc52_handler(void);
extern void ihc53_handler(void);
extern void ihc54_handler(void);
extern void ihc55_handler(void);
extern void ihc56_handler(void);
extern void ihc57_handler(void);
extern void ihc58_handler(void);
extern void ihc59_handler(void);
extern void ihc60_handler(void);
extern void ihc61_handler(void);
extern void ihc62_handler(void);
extern void ihc63_handler(void);
extern void ihc64_handler(void);
extern void ihc65_handler(void);
extern void ihc66_handler(void);
extern void ihc67_handler(void);
extern void ihc68_handler(void);
extern void ihc69_handler(void);
extern void ihc70_handler(void);
extern void ihc71_handler(void);
extern void ihc72_handler(void);
extern void ihc73_handler(void);
extern void ihc74_handler(void);
extern void ihc75_handler(void);
extern void ihc76_handler(void);
extern void ihc77_handler(void);
extern void ihc78_handler(void);
extern void ihc79_handler(void);
extern void ihc80_handler(void);
extern void ihc81_handler(void);
extern void ihc82_handler(void);
extern void ihc83_handler(void);
extern void ihc84_handler(void);
extern void ihc85_handler(void);
extern void ihc86_handler(void);
extern void ihc87_handler(void);
extern void ihc88_handler(void);
extern void ihc89_handler(void);
extern void ihc90_handler(void);
extern void ihc91_handler(void);
extern void ihc92_handler(void);
extern void ihc93_handler(void);
extern void ihc94_handler(void);
extern void ihc95_handler(void);
extern void ihc96_handler(void);
extern void ihc97_handler(void);
extern void ihc98_handler(void);
extern void ihc99_handler(void);
extern void ihc100_handler(void);
extern void ihc101_handler(void);
extern void ihc102_handler(void);
extern void ihc103_handler(void);
extern void ihc104_handler(void);
extern void ihc105_handler(void);
extern void ihc106_handler(void);
extern void ihc107_handler(void);
extern void ihc108_handler(void);
extern void ihc109_handler(void);
extern void ihc110_handler(void);
extern void ihc111_handler(void);
extern void ihc112_handler(void);
extern void ihc113_handler(void);
extern void ihc114_handler(void);
extern void ihc115_handler(void);
extern void ihc116_handler(void);
extern void ihc117_handler(void);
extern void ihc118_handler(void);
extern void ihc119_handler(void);
extern void ihc120_handler(void);
extern void ihc121_handler(void);
extern void ihc122_handler(void);
extern void ihc123_handler(void);
extern void ihc124_handler(void);
extern void ihc125_handler(void);
extern void ihc126_handler(void);
extern void ihc127_handler(void);
extern void ihc128_handler(void);
extern void ihc129_handler(void);
extern void ihc130_handler(void);
extern void ihc131_handler(void);
extern void ihc132_handler(void);
extern void ihc133_handler(void);
extern void ihc134_handler(void);
extern void ihc135_handler(void);
extern void ihc136_handler(void);
extern void ihc137_handler(void);
extern void ihc138_handler(void);
extern void ihc139_handler(void);
extern void ihc140_handler(void);
extern void ihc141_handler(void);
extern void ihc142_handler(void);
extern void ihc143_handler(void);
extern void ihc144_handler(void);
extern void ihc145_handler(void);
extern void ihc146_handler(void);
extern void ihc147_handler(void);
extern void ihc148_handler(void);
extern void ihc149_handler(void);
extern void ihc150_handler(void);
extern void ihc151_handler(void);
extern void ihc152_handler(void);
extern void ihc153_handler(void);
extern void ihc154_handler(void);
extern void ihc155_handler(void);
extern void ihc156_handler(void);
extern void ihc157_handler(void);
extern void ihc158_handler(void);
extern void ihc159_handler(void);
extern void ihc160_handler(void);
extern void ihc161_handler(void);
extern void ihc162_handler(void);
extern void ihc163_handler(void);
extern void ihc164_handler(void);
extern void ihc165_handler(void);
extern void ihc166_handler(void);
extern void ihc167_handler(void);
extern void ihc168_handler(void);
extern void ihc169_handler(void);
extern void ihc170_handler(void);
extern void ihc171_handler(void);
extern void ihc172_handler(void);
extern void ihc173_handler(void);
extern void ihc174_handler(void);
extern void ihc175_handler(void);
extern void ihc176_handler(void);
extern void ihc177_handler(void);
extern void ihc178_handler(void);
extern void ihc179_handler(void);
extern void ihc180_handler(void);
extern void ihc181_handler(void);
extern void ihc182_handler(void);
extern void ihc183_handler(void);
extern void ihc184_handler(void);
extern void ihc185_handler(void);
extern void ihc186_handler(void);
extern void ihc187_handler(void);
extern void ihc188_handler(void);
extern void ihc189_handler(void);
extern void ihc190_handler(void);
extern void ihc191_handler(void);
extern void ihc192_handler(void);
extern void ihc193_handler(void);
extern void ihc194_handler(void);
extern void ihc195_handler(void);
extern void ihc196_handler(void);
extern void ihc197_handler(void);
extern void ihc198_handler(void);
extern void ihc199_handler(void);
extern void ihc200_handler(void);
extern void ihc201_handler(void);
extern void ihc202_handler(void);
extern void ihc203_handler(void);
extern void ihc204_handler(void);
extern void ihc205_handler(void);
extern void ihc206_handler(void);
extern void ihc207_handler(void);
extern void ihc208_handler(void);
extern void ihc209_handler(void);
extern void ihc210_handler(void);
extern void ihc211_handler(void);
extern void ihc212_handler(void);
extern void ihc213_handler(void);
extern void ihc214_handler(void);
extern void ihc215_handler(void);
extern void ihc216_handler(void);
extern void ihc217_handler(void);
extern void ihc218_handler(void);
extern void ihc219_handler(void);
extern void ihc220_handler(void);
extern void ihc221_handler(void);
extern void ihc222_handler(void);
extern void ihc223_handler(void);
extern void ihc224_handler(void);
extern void ihc225_handler(void);
extern void ihc226_handler(void);
extern void ihc227_handler(void);
extern void ihc228_handler(void);
extern void ihc229_handler(void);
extern void ihc230_handler(void);
extern void ihc231_handler(void);
extern void ihc232_handler(void);
extern void ihc233_handler(void);
extern void ihc234_handler(void);
extern void ihc235_handler(void);
extern void ihc236_handler(void);
extern void ihc237_handler(void);
extern void ihc238_handler(void);
extern void ihc239_handler(void);
extern void ihc240_handler(void);
extern void ihc241_handler(void);
extern void ihc242_handler(void);
extern void ihc243_handler(void);
extern void ihc244_handler(void);
extern void ihc245_handler(void);
extern void ihc246_handler(void);
extern void ihc247_handler(void);
extern void ihc248_handler(void);
extern void ihc249_handler(void);
extern void ihc250_handler(void);
extern void ihc251_handler(void);
extern void ihc252_handler(void);
extern void ihc253_handler(void);
extern void ihc254_handler(void);
extern void ihc255_handler(void);
