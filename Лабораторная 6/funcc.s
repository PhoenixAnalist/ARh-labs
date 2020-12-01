	.text
	.globl	funcc
	.type	funcc, @function
funcc:
	movsd	.consts(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jnb	.if
	subsd	%xmm1, %xmm0
	ret
.if:
	pxor	%xmm0, %xmm0
	ret
.consts:
	.long	2576980378
	.long	1072273817
