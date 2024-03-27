; Callee Assembly
section .text
bits 64
default rel

global find_sdot_x86

; Store the parameters to another register
find_sdot_x86:
	MOV RSI, RCX
	MOV RDI, RDX
	MOV RCX, R8
	XORPD XMM0, XMM0

; Looping through all the elements to compute
compute_sdot_x86:
	MOVSD XMM1, [RSI]
	MOVSD XMM2, [RDI]

	MULSD XMM1, XMM2
	ADDSD XMM0, XMM1

	ADD RSI, 8
	ADD RDI, 8
	LOOP compute_sdot_x86

	ret