; Callee Assembly
section .text
bits 64
default rel

global find_sdot_x86

; Store the parameters to another register
find_sdot_x86:
	MOV R10, RCX
	MOV R11, RDX
	MOV RCX, R8
	XORPD XMM0, XMM0

; Looping through all the elements to compute
compute_sdot_x86:
	MOVSD XMM1, [R10]
	MOVSD XMM2, [R11]

	MULSD XMM1, XMM2
	ADDSD XMM0, XMM1

	ADD R10, 8
	ADD R11, 8
	LOOP compute_sdot_x86

	ret