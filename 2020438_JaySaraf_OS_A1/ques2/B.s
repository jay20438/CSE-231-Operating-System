	.file	"B.c"
	.text
	.section	.rodata
.LC0:
	.string	"I'm inside B. "
.LC1:
	.string	"char : %c \n"
	.text
	.globl	B
	.type	B, @function
B:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	jmp	.L2
.L3:
	movq	-24(%rbp), %rax
	shrq	$8, %rax
	movb	%al, -1(%rbp)
	shrq	$8, -24(%rbp)
	movzbl	-1(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L2:
	cmpq	$0, -24(%rbp)
	jne	.L3
	call	C@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	B, .-B
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
