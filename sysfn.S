	.file	"sysfn.cc"
	.text
	.type	_ZN3IHCL11set_handlerEhPFvhE, @function
_ZN3IHCL11set_handlerEhPFvhE:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, %eax
	movq	%rsi, -16(%rbp)
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	ihc_set_handler@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ZN3IHCL11set_handlerEhPFvhE, .-_ZN3IHCL11set_handlerEhPFvhE
	.type	_ZN3IRQL2onEh, @function
_ZN3IRQL2onEh:
.LFB21:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	movl	%eax, %edi
	call	irq_on@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE21:
	.size	_ZN3IRQL2onEh, .-_ZN3IRQL2onEh
	.type	_ZN3IRQL3offEh, @function
_ZN3IRQL3offEh:
.LFB22:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	movl	%eax, %edi
	call	irq_off@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE22:
	.size	_ZN3IRQL3offEh, .-_ZN3IRQL3offEh
	.local	_ZL10__justexit
	.comm	_ZL10__justexit,1,1
	.section	.rodata
	.align 8
.LC0:
	.string	" * syscall invoked using component "
.LC1:
	.string	" * syscall: blocked\n"
	.text
	.globl	sysfn_ihc_handler
	.type	sysfn_ihc_handler, @function
sysfn_ihc_handler:
.LFB25:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	%r8, -40(%rbp)
	movq	%r9, -48(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZN4uart4coutE(%rip), %rax
	movq	%rax, %rdi
	call	_ZN4uart7ostreamlsEPKc@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZN4uart7ostreamlsEy@PLT
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZN4uart7ostreamlsEc@PLT
	movzbl	_ZL10__justexit(%rip), %eax
	testb	%al, %al
	je	.L8
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZN4uart4coutE(%rip), %rax
	movq	%rax, %rdi
	call	_ZN4uart7ostreamlsEPKc@PLT
	jmp	.L7
.L8:
	cmpq	$0, -8(%rbp)
	je	.L15
	movabsq	$281474976710656, %rax
	cmpq	%rax, -8(%rbp)
	jne	.L11
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZN4uart4coutE(%rip), %rax
	movq	%rax, %rdi
	call	_ZN4uart7ostreamlsEPc@PLT
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZN4uart7ostreamlsEc@PLT
	jmp	.L7
.L11:
	movabsq	$562949953421312, %rax
	cmpq	%rax, -8(%rbp)
	jne	.L12
	movq	-16(%rbp), %rax
	movzbl	%al, %eax
	movl	%eax, %edi
	call	_ZN3IRQL2onEh
	jmp	.L7
.L12:
	movabsq	$562949953486848, %rax
	cmpq	%rax, -8(%rbp)
	jne	.L13
	movq	-16(%rbp), %rax
	movzbl	%al, %eax
	movl	%eax, %edi
	call	_ZN3IRQL3offEh
	jmp	.L7
.L13:
	movabsq	$562954248388608, %rax
	cmpq	%rax, -8(%rbp)
	jne	.L14
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movzbl	%al, %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	_ZN3IHCL11set_handlerEhPFvhE
	jmp	.L7
.L14:
	movabsq	$844424930131968, %rax
	cmpq	%rax, -8(%rbp)
	jne	.L7
	movb	$1, _ZL10__justexit(%rip)
	jmp	.L7
.L15:
	nop
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE25:
	.size	sysfn_ihc_handler, .-sysfn_ihc_handler
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
