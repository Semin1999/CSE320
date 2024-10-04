	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 5
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	mov	w8, #236
	stur	w8, [x29, #-8]
	ldur	w9, [x29, #-8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	w8, #1
	stur	w8, [x29, #-12]
	ldur	w8, [x29, #-8]
	ldur	w9, [x29, #-12]
	orr	w8, w8, w9, lsl #3
	stur	w8, [x29, #-8]
	ldur	w9, [x29, #-8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	ldur	w8, [x29, #-8]
	ldur	w9, [x29, #-12]
	bic	w8, w8, w9, lsl #5
	stur	w8, [x29, #-8]
	ldur	w9, [x29, #-8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	ldur	w8, [x29, #-8]
	ldur	w9, [x29, #-12]
	ands	w8, w8, w9, lsl #7
	cset	w8, eq
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	ldur	w8, [x29, #-8]
	ldur	w9, [x29, #-12]
	bic	w8, w8, w9, lsl #7
	stur	w8, [x29, #-8]
	b	LBB0_3
LBB0_2:
	ldur	w8, [x29, #-8]
	ldur	w9, [x29, #-12]
	orr	w8, w8, w9, lsl #7
	stur	w8, [x29, #-8]
	b	LBB0_3
LBB0_3:
	ldur	w9, [x29, #-8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldur	w8, [x29, #-8]
	ldur	w9, [x29, #-12]
	ands	w8, w8, w9, lsl #7
	cset	w8, eq
	tbnz	w8, #0, LBB0_5
	b	LBB0_4
LBB0_4:
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	b	LBB0_5
LBB0_5:
	mov	w0, #0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Initial data: 0x%02X\n"

l_.str.1:                               ; @.str.1
	.asciz	"After setting 3rd bit: 0x%02X\n"

l_.str.2:                               ; @.str.2
	.asciz	"After clearing 5th bit: 0x%02X\n"

l_.str.3:                               ; @.str.3
	.asciz	"After toggling 7th bit: 0x%02X\n"

l_.str.4:                               ; @.str.4
	.asciz	"7th bit is set"

.subsections_via_symbols
