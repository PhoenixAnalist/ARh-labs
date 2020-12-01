	.text
	.globl	calc
	.type	calc, @function
calc:
	subq	$24, %rsp
	movsd	%xmm0, 8(%rsp)
	addsd	%xmm0, %xmm0
	call	sin
	movsd	%xmm0, (%rsp)
	movsd	8(%rsp), %xmm1
	addsd   %xmm1, %xmm1
	addsd   8(%rsp), %xmm1
	movapd	%xmm1, %xmm0
	call	cos
	addsd	(%rsp), %xmm0
	addq	$24, %rsp
	ret
