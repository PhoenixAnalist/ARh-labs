.text
	.globl	fib
	.type	fib, @function
fib:
	movl	$1, (%rsi)
	movl	$1, 4(%rsi)
	leal	1(%rdi), %eax
	cmpl	$2, %eax
	jle	end
	movq	%rsi, %rax
	leal	-2(%rdi), %edx
	leaq	4(%rsi,%rdx,4), %rcx
for:
	movl	(%rax), %edx
	addl	4(%rax), %edx
	movl	%edx, 8(%rax)
	addq	$4, %rax
	cmpq	%rcx, %rax
	jne	for
end:
	rep ret
