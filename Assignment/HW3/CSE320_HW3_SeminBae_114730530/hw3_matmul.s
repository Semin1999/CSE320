	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 5
	.globl	_matrix_multiply                ; -- Begin function matrix_multiply
	.p2align	2
_matrix_multiply:                       ; @matrix_multiply
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	str	x0, [sp, #40]
	str	x1, [sp, #32]
	str	x2, [sp, #24]
	str	wzr, [sp, #20]
	b	LBB0_1
LBB0_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB0_3 Depth 2
                                        ;       Child Loop BB0_5 Depth 3
	ldr	w8, [sp, #20]
	subs	w8, w8, #9
	cset	w8, ge
	tbnz	w8, #0, LBB0_12
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	str	wzr, [sp, #16]
	str	wzr, [sp, #12]
	b	LBB0_3
LBB0_3:                                 ;   Parent Loop BB0_1 Depth=1
                                        ; =>  This Loop Header: Depth=2
                                        ;       Child Loop BB0_5 Depth 3
	ldr	w8, [sp, #12]
	subs	w8, w8, #9
	cset	w8, ge
	tbnz	w8, #0, LBB0_10
	b	LBB0_4
LBB0_4:                                 ;   in Loop: Header=BB0_3 Depth=2
	str	wzr, [sp, #16]
	str	wzr, [sp, #8]
	b	LBB0_5
LBB0_5:                                 ;   Parent Loop BB0_1 Depth=1
                                        ;     Parent Loop BB0_3 Depth=2
                                        ; =>    This Inner Loop Header: Depth=3
	ldr	w8, [sp, #8]
	subs	w8, w8, #8
	cset	w8, ge
	tbnz	w8, #0, LBB0_8
	b	LBB0_6
LBB0_6:                                 ;   in Loop: Header=BB0_5 Depth=3
	ldr	x8, [sp, #40]
	ldrsw	x9, [sp, #20]
	add	x8, x8, x9, lsl #5
	ldrsw	x9, [sp, #8]
	ldr	w8, [x8, x9, lsl #2]
	ldr	x9, [sp, #32]
	ldrsw	x10, [sp, #8]
	mov	x11, #36
	mul	x10, x10, x11
	add	x9, x9, x10
	ldrsw	x10, [sp, #12]
	ldr	w9, [x9, x10, lsl #2]
	mul	w9, w8, w9
	ldr	w8, [sp, #16]
	add	w8, w8, w9
	str	w8, [sp, #16]
	b	LBB0_7
LBB0_7:                                 ;   in Loop: Header=BB0_5 Depth=3
	ldr	w8, [sp, #8]
	add	w8, w8, #1
	str	w8, [sp, #8]
	b	LBB0_5
LBB0_8:                                 ;   in Loop: Header=BB0_3 Depth=2
	ldr	w8, [sp, #16]
	ldr	x9, [sp, #24]
	ldrsw	x10, [sp, #20]
	mov	x11, #36
	mul	x10, x10, x11
	add	x9, x9, x10
	ldrsw	x10, [sp, #12]
	str	w8, [x9, x10, lsl #2]
	b	LBB0_9
LBB0_9:                                 ;   in Loop: Header=BB0_3 Depth=2
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB0_3
LBB0_10:                                ;   in Loop: Header=BB0_1 Depth=1
	b	LBB0_11
LBB0_11:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #20]
	add	w8, w8, #1
	str	w8, [sp, #20]
	b	LBB0_1
LBB0_12:
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x28, x27, [sp, #-32]!           ; 16-byte Folded Spill
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w27, -24
	.cfi_offset w28, -32
	sub	sp, sp, #960
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-24]
	str	wzr, [sp, #48]
	add	x0, sp, #664
	str	x0, [sp, #24]                   ; 8-byte Folded Spill
	adrp	x1, l___const.main.matA@PAGE
	add	x1, x1, l___const.main.matA@PAGEOFF
	mov	x2, #288
	str	x2, [sp, #16]                   ; 8-byte Folded Spill
	bl	_memcpy
	ldr	x2, [sp, #16]                   ; 8-byte Folded Reload
	add	x0, sp, #376
	str	x0, [sp, #32]                   ; 8-byte Folded Spill
	adrp	x1, l___const.main.matB@PAGE
	add	x1, x1, l___const.main.matB@PAGEOFF
	bl	_memcpy
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	ldr	x1, [sp, #32]                   ; 8-byte Folded Reload
	add	x2, sp, #52
	bl	_matrix_multiply
	str	wzr, [sp, #44]
	b	LBB1_1
LBB1_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB1_3 Depth 2
	ldr	w8, [sp, #44]
	subs	w8, w8, #9
	cset	w8, ge
	tbnz	w8, #0, LBB1_11
	b	LBB1_2
LBB1_2:                                 ;   in Loop: Header=BB1_1 Depth=1
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	str	wzr, [sp, #40]
	b	LBB1_3
LBB1_3:                                 ;   Parent Loop BB1_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	w8, [sp, #40]
	subs	w8, w8, #9
	cset	w8, ge
	tbnz	w8, #0, LBB1_9
	b	LBB1_4
LBB1_4:                                 ;   in Loop: Header=BB1_3 Depth=2
	ldr	w8, [sp, #40]
	subs	w8, w8, #8
	cset	w8, ne
	tbnz	w8, #0, LBB1_6
	b	LBB1_5
LBB1_5:                                 ;   in Loop: Header=BB1_3 Depth=2
	ldrsw	x8, [sp, #44]
	mov	x9, #36
	mul	x9, x8, x9
	add	x8, sp, #52
	add	x8, x8, x9
	ldrsw	x9, [sp, #40]
	ldr	w9, [x8, x9, lsl #2]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	b	LBB1_7
LBB1_6:                                 ;   in Loop: Header=BB1_3 Depth=2
	ldrsw	x8, [sp, #44]
	mov	x9, #36
	mul	x9, x8, x9
	add	x8, sp, #52
	add	x8, x8, x9
	ldrsw	x9, [sp, #40]
	ldr	w9, [x8, x9, lsl #2]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	b	LBB1_7
LBB1_7:                                 ;   in Loop: Header=BB1_3 Depth=2
	b	LBB1_8
LBB1_8:                                 ;   in Loop: Header=BB1_3 Depth=2
	ldr	w8, [sp, #40]
	add	w8, w8, #1
	str	w8, [sp, #40]
	b	LBB1_3
LBB1_9:                                 ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_10
LBB1_10:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #44]
	add	w8, w8, #1
	str	w8, [sp, #44]
	b	LBB1_1
LBB1_11:
	ldur	x9, [x29, #-24]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB1_13
	b	LBB1_12
LBB1_12:
	bl	___stack_chk_fail
LBB1_13:
	mov	w0, #0
	add	sp, sp, #960
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x28, x27, [sp], #32             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__const
	.p2align	2, 0x0                          ; @__const.main.matA
l___const.main.matA:
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7

	.p2align	2, 0x0                          ; @__const.main.matB
l___const.main.matB:
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7

	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"[ "

l_.str.1:                               ; @.str.1
	.asciz	"%d ]\n"

l_.str.2:                               ; @.str.2
	.asciz	"%d, "

.subsections_via_symbols
