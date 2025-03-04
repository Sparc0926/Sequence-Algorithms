	.file	"IsExactlyIn.c"
	.text
	.p2align 4,,15
	.globl	_IsExactlyIn
	.def	_IsExactlyIn;	.scl	2;	.type	32;	.endef
_IsExactlyIn:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	movl	28(%esp), %edi
	movl	32(%esp), %ebp
	movl	4(%edi), %ecx
	movl	4(%ebp), %esi
	subl	%esi, %ecx
	movl	%ecx, 4(%esp)
	js	L22
	xorl	%eax, %eax
	.p2align 4,,10
L11:
	cmpl	$0, %esi
	jle	L7
	movl	(%edi), %ebx
	movl	0(%ebp), %ecx
	movl	$0, (%esp)
	addl	%eax, %ebx
	movzbl	(%ecx), %edx
	cmpb	%dl, (%ebx)
	jne	L5
	xorl	%edx, %edx
	movl	%eax, (%esp)
	jmp	L12
	.p2align 4,,10
L25:
	movzbl	(%ecx,%edx), %eax
	cmpb	%al, (%ebx,%edx)
	jne	L24
L12:
	addl	$1, %edx
	cmpl	%esi, %edx
	jne	L25
	movl	(%esp), %eax
L1:
	addl	$8, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
L7:
	.cfi_restore_state
	je	L1
L5:
	addl	$1, %eax
	cmpl	4(%esp), %eax
	jle	L11
L22:
	addl	$8, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	$-1, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
L24:
	.cfi_restore_state
	movl	(%esp), %eax
	addl	$1, %eax
	cmpl	4(%esp), %eax
	jle	L11
	jmp	L22
	.cfi_endproc
LFE13:
	.section .rdata,"dr"
LC0:
	.ascii "abacaba\0"
LC1:
	.ascii "%d \0"
	.text
	.p2align 4,,15
	.globl	_test
	.def	_test;	.scl	2;	.type	32;	.endef
_test:
LFB14:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$LC0+1, %ebx
	subl	$52, %esp
	.cfi_def_cfa_offset 64
	leal	24(%esp), %ecx
	movl	$0, 20(%esp)
	.p2align 4,,10
L32:
	movzbl	(%ebx), %edx
	xorl	%eax, %eax
	cmpb	$97, %dl
	sete	%al
	movl	%eax, (%ecx)
	movl	-4(%ecx), %eax
	testl	%eax, %eax
	jg	L31
	jmp	L27
	.p2align 4,,10
L30:
	movl	16(%esp,%eax,4), %eax
	testl	%eax, %eax
	jle	L27
L31:
	cmpb	LC0(%eax), %dl
	jne	L30
	addl	$1, %eax
	movl	%eax, (%ecx)
L27:
	addl	$1, %ebx
	addl	$4, %ecx
	cmpl	$LC0+7, %ebx
	jne	L32
	leal	20(%esp), %ebx
	leal	48(%esp), %esi
	.p2align 4,,10
L33:
	movl	(%ebx), %eax
	movl	$LC1, (%esp)
	addl	$4, %ebx
	movl	%eax, 4(%esp)
	call	_printf
	cmpl	%ebx, %esi
	jne	L33
	movl	$10, (%esp)
	call	_putchar
	addl	$52, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE14:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
