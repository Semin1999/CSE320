	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 5
	.globl	_modifyName                     ; -- Begin function modifyName
	.p2align	2
_modifyName:                            ; @modifyName
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	str	x1, [sp]
	ldr	x8, [sp]
	ldr	x9, [sp, #8]
	str	x8, [x9]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_modifyNumber                   ; -- Begin function modifyNumber
	.p2align	2
_modifyNumber:                          ; @modifyNumber
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	str	w1, [sp, #4]
	ldr	w8, [sp, #4]
	ldr	x9, [sp, #8]
	str	w8, [x9, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_modifyData                     ; -- Begin function modifyData
	.p2align	2
_modifyData:                            ; @modifyData
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	str	x1, [sp]
	ldr	x8, [sp]
	ldr	w8, [x8]
	ldr	x9, [sp, #8]
	str	w8, [x9, #16]
	ldr	x8, [sp]
	ldr	d0, [x8]
	ldr	x8, [sp, #8]
	str	d0, [x8, #16]
	ldr	x8, [sp]
	ldr	x8, [x8]
	ldr	x9, [sp, #8]
	str	x8, [x9, #16]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3, 0x0                          ; -- Begin function main
lCPI3_0:
	.quad	0x4029666666666666              ; double 12.699999999999999
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #112
	.cfi_def_cfa_offset 112
	stp	x29, x30, [sp, #96]             ; 16-byte Folded Spill
	add	x29, sp, #96
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0
	stur	w8, [x29, #-44]                 ; 4-byte Folded Spill
	stur	wzr, [x29, #-4]
	mov	x0, #50
	bl	_malloc
	sub	x8, x29, #32
	str	x8, [sp, #40]                   ; 8-byte Folded Spill
	stur	x0, [x29, #-32]
	ldur	x0, [x29, #-32]
	adrp	x1, l_.str@PAGE
	add	x1, x1, l_.str@PAGEOFF
	mov	x2, #-1
	str	x2, [sp, #8]                    ; 8-byte Folded Spill
	bl	___strcpy_chk
	mov	w8, #100
	stur	w8, [x29, #-24]
	ldur	x8, [x29, #-32]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	bl	_printf
	ldur	w9, [x29, #-24]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	str	x0, [sp, #24]                   ; 8-byte Folded Spill
	bl	_printf
	sub	x8, x29, #40
	str	x8, [sp, #32]                   ; 8-byte Folded Spill
	mov	w8, #150
	stur	w8, [x29, #-40]
	ldur	w9, [x29, #-40]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	adrp	x8, lCPI3_0@PAGE
	ldr	d0, [x8, lCPI3_0@PAGEOFF]
	stur	d0, [x29, #-40]
	ldur	x8, [x29, #-40]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	mov	x0, #100
	bl	_malloc
	ldr	x2, [sp, #8]                    ; 8-byte Folded Reload
	stur	x0, [x29, #-40]
	ldur	x0, [x29, #-40]
	adrp	x1, l_.str.5@PAGE
	add	x1, x1, l_.str.5@PAGEOFF
	bl	___strcpy_chk
	ldur	x8, [x29, #-40]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.6@PAGE
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	ldr	x0, [sp, #40]                   ; 8-byte Folded Reload
	adrp	x1, l_.str.7@PAGE
	add	x1, x1, l_.str.7@PAGEOFF
	bl	_modifyName
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldur	x8, [x29, #-32]
	mov	x9, sp
	str	x8, [x9]
	bl	_printf
	ldr	x0, [sp, #40]                   ; 8-byte Folded Reload
	mov	w1, #20
	bl	_modifyNumber
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	ldur	w9, [x29, #-24]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	bl	_printf
	ldr	x1, [sp, #32]                   ; 8-byte Folded Reload
	ldr	x0, [sp, #40]                   ; 8-byte Folded Reload
	bl	_modifyData
	ldur	w9, [x29, #-16]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.8@PAGE
	add	x0, x0, l_.str.8@PAGEOFF
	bl	_printf
	ldur	d0, [x29, #-16]
	mov	x8, sp
	str	d0, [x8]
	adrp	x0, l_.str.9@PAGE
	add	x0, x0, l_.str.9@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-16]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.10@PAGE
	add	x0, x0, l_.str.10@PAGEOFF
	bl	_printf
	ldur	w0, [x29, #-44]                 ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #96]             ; 16-byte Folded Reload
	add	sp, sp, #112
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"LIF Neuron"

l_.str.1:                               ; @.str.1
	.asciz	"snnA.neuronName : %s\n"

l_.str.2:                               ; @.str.2
	.asciz	"snnA.neuronNumber : %d\n"

l_.str.3:                               ; @.str.3
	.asciz	"dataA.intData : %d\n"

l_.str.4:                               ; @.str.4
	.asciz	"dataA.doubleData : %.2f\n"

l_.str.5:                               ; @.str.5
	.asciz	"Number of synapses and average weight"

l_.str.6:                               ; @.str.6
	.asciz	"dataA.stringData : %s\n"

l_.str.7:                               ; @.str.7
	.asciz	"Hodgkin-Huxley"

l_.str.8:                               ; @.str.8
	.asciz	"snnA.commonData.intData : %d <- 'garbage value' since union save only one(the last) value of data type\n"

l_.str.9:                               ; @.str.9
	.asciz	"snnA.commonData.doubleData : %.2f <- 'garbage value' since union save only one(the last) value of data type\n"

l_.str.10:                              ; @.str.10
	.asciz	"snnA.commonData.stringData : %s <- stringData was a last assigned data\n"

.subsections_via_symbols
