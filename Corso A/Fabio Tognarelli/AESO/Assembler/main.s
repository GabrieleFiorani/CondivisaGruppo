	.text
	.global main
	.type main, %function

main:	mov r3, #123
	
	ldr r0, =fmt
	mov r1, r3
	push {lr}
	bl printf

	pop {pc}
	

	.data
fmt:	.string "Risultato %d\n"

