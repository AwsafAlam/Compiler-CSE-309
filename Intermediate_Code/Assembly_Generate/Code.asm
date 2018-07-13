.MODEL SMALL
.STACK 100H
.DATA
t0 DW ?
x DW ?
t1 DW ?
t2 DW ?
a DW ?
b DW ?
.CODE
MOV AX,2
MOV BX,a
MUL BX
MOV t0,AX


MOV AX,a
MOV BX,f(a)
ADD BX,,AX
MOV t1,BX

MOV AX,b
MOV BX,t1
ADD BX,,AX
MOV t2,BX

MOV AX,t2
MOV x,AX


main PROC
MOV AX,@DATA
MOV DS,AX

MOV AX,1
MOV a,AX

MOV AX,2
MOV b,AX

MOV AX,f
MOV a,AX

MOV AX,a
CALL PRINT

MOV AH,4CH
INT 21H
main ENDP

PRINT PROC

	push ax
	push bx
	push cx
	push dx
	or ax,ax
 	jge enddif
	push ax
	mov dl,'-'
	mov ah,2
	int 21h
	pop ax
	neg ax
enddif:
	xor cx,cx
	mov bx,10d
repeat:
	xor dx,dx
	div bx
	 push dx
	inc cx
	or ax,ax
	jne repeat
	mov ah,2
print_loop:
	pop dx
	or dl,30h
	int 21h
	loop print_loop
	pop dx
	pop cx
	pop bx
	pop ax
	ret
PRINT ENDP


END MAIN
