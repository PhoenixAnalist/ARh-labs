	.text
	.globl	sum
	.type	sum, @function
sum:
	movq	$0x000000000, (%rcx)
	testl	%esi, %esi
	jle	returnifzero
	movq	%rdx, %r8
	leal	-1(%rsi), %eax
	salq	$4, %rax
	leaq	16(%rdx,%rax), %rdx
	movl	$0, %eax
	movl	$1, %esi
	jmp	forbody
forhead:
	addq	$16, %r8
	cmpq	%rdx, %r8
	je	forend
forbody:
	cmpl	%edi, (%r8)
	jne	forhead
	movsd	(%rcx), %xmm0
	addsd	8(%r8), %xmm0
	movsd	%xmm0, (%rcx)
	movl	%esi, %eax
	jmp	forhead
forend:
	rep ret
returnifzero:
	movl	$0, %eax
	ret
