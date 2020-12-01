	.text
	.globl	summ
	.type	summ, @function
summ:
	testl	%edi, %edi
	jle	returnifzero
	movq	%rsi, %rdx
	leal	-1(%rdi), %eax
	leaq	4(%rsi,%rax,4), %rcx
	movl	$0, %eax
for:
	addl	(%rdx), %eax
	addq	$4, %rdx
	cmpq	%rcx, %rdx
	jne	for
	rep ret
returnifzero:
	movl	$0, %eax
	ret
