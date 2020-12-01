.text
	.globl	func
	.type	func, @function
func:
	movl	%esi, %eax
	cltd
	idivl	%edi
	testl	%edx, %edx
	je	.if
	movl	%esi, %eax
	imull	%edi, %eax
	ret
.if:
	movl	%esi, %eax
	cltd
	idivl	%edi
	ret
