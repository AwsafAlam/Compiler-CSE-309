.MODEL SMALL
.STACK 100H
.DATA
a DW ?
b DW ?
t0 DW ?
t1 DW ?
t2 DW ?
t3 DW ?
t4 DW ?
t5 DW ?
t6 DW ?
t7 DW ?
t8 DW ?
c DW 3 DUP (?)
.CODE
main PROC
MOV AX,@DATA
MOV DS,AX

MOV AX,3
MOV BX,2
ADD BX,,AX
MOV t0,BX

MOV AX,1
MOV BX,t0
MUL BX
MOV t1,AX

MOV AX,t1
MOV BX,3
DIV BX
MOV t2,DX

MOV AX,t2
MOV a,AX

MOV AX,1
CMP AX,5
JL L0
MOV t3,0
JMP L1
L0:
MOV t3,1
L1:
MOV AX,t3
MOV b,AX

MOV BX,0
ADD BX,BX
MOV AX,c[BX]
MOV t4,AX

MOV AX,2
MOV c[BX],AX

MOV AX,b
AND a,AX
MOV BX,a
MOV t5,BX

MOV AX,t5
CMP AX,0
JE L2
MOV BX,0
ADD BX,BX
MOV AX,c[BX]
MOV t6,AX

MOV AX,t6
INC AX
MOV c[0],AX
c[0]

JMP L3
L2:
MOV BX,0
ADD BX,BX
MOV AX,c[BX]
MOV t8,AX

MOV BX,1
ADD BX,BX
MOV AX,c[BX]
MOV t7,AX

MOV AX,t8
MOV c[BX],AX


L3:
MOV AX,a
CALL PRINT
MOV AX,b
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
