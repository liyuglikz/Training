#.global DATA
	.data
	DATA:
		.ascii "hello world\n\0"
	LEN = .-DATA

	.text

	.global _start
_start:
	pushq %rbp
	movq %rsp, %rbp

	movl $0, -4(%rbp)	# for( int i = 0; ...
Loop0_top:				# {

		movl $0, -8(%rbp)	# for( int j = 0; ...
	Loop1_top:				# {

		movl -8(%rbp), %eax
		inc %eax
		movl -8(%rbp), %ebx

		mov DATA(%eax), %cl
		mov DATA(%ebx), %ch

		cmp %cl, %ch
		jle EX
		jmp EX_Break

		EX:
			mov DATA(%eax), %cl
			mov DATA(%ebx), %ch
			mov %ch, DATA(%eax)
			mov %cl, DATA(%ebx)
		EX_Break:

	Loop1_bottom:
		movl -8(%rbp), %eax
		inc %eax
		movl %eax, -8(%rbp)

		movl $LEN, %eax
		movl -4(%rbp), %ebx
		sub %eax, %ebx
		cmp %eax, -8(%rbp)
		jle Loop1_top

Loop0_bottom:
	movl -4(%rbp), %eax
	inc %eax
	movl %eax, -4(%rbp)

	cmp $LEN, -4(%rbp)
	jle Loop0_top

	call Output

ENDHere:
	popq %rbp
#return here
	movl $0, %ebx
	movl $1, %eax
	int $0x80

Output:
	movl $LEN, %edx	
    movl $DATA, %ecx
	movl $1, %ebx
	movl $4, %eax
	int $0x80
	ret
	.end

