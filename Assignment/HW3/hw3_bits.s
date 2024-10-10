	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 5
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	mov	w8, #236
	sturb	w8, [x29, #-5]
	ldurb	w10, [x29, #-5]
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldurb	w8, [x29, #-5]
	orr	w8, w8, #0x8
	sturb	w8, [x29, #-5]
	ldurb	w10, [x29, #-5]
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	ldurb	w8, [x29, #-5]
	and	w8, w8, #0xffffffdf
	sturb	w8, [x29, #-5]
	ldurb	w10, [x29, #-5]
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	ldurb	w8, [x29, #-5]
	eor	w8, w8, #0x80
	sturb	w8, [x29, #-5]
	ldurb	w10, [x29, #-5]
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldurb	w8, [x29, #-5]
	ands	w8, w8, #0x80
	cset	w8, eq
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	b	LBB0_3
LBB0_2:
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	b	LBB0_3
LBB0_3:
	mov	w0, #0
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
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
	.asciz	"7th bit is set\n"

l_.str.5:                               ; @.str.5
	.asciz	"7th bit is not set\n"

.subsections_via_symbols
