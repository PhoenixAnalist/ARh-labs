	.text
	.globl	form
	.type	form, @function
form:
	testl	%esi, %esi
	jle	returnifzero
	movq	%rdx, %rcx
	leal	-1(%rsi), %eax
	salq	$4, %rax
	leaq	16(%rdx,%rax), %r8
	movl	$0, %eax
counter:
	cmpl	%edi, (%rdx)
	sete	%sil
	movzbl	%sil, %esi
	addl	%esi, %eax
	addq	$16, %rdx
	cmpq	%r8, %rdx
	jne	counter
	testl	%eax, %eax
	je	returnifzero
	pxor	%xmm0, %xmm0
	cvtsi2sd	%eax, %xmm0
	movsd	one(%rip), %xmm1
	divsd	%xmm0, %xmm1
	jmp	forbody
for:
	addq	$16, %rcx
	cmpq	%rdx, %rcx
	je	returnifzero
forbody:
	cmpl	%edi, (%rcx)
	jne	for
	movsd	%xmm1, 8(%rcx)
	jmp	for
returnifzero:
	rep ret
one:
	.long	0
	.long	1072693248
