.MODEL SMALL
.STACK 100H
.DATA
t0 DW ?
a2 DW ?
x3 DW ?
t1 DW ?
t2 DW ?
t3 DW ?
a3 DW ?
b3 DW ?
a4 DW ?
b4 DW ?
t4 DW ?
t5 DW ?
t6 DW ?
c4 DW 3 DUP (?)
.CODE
f PROC
JMP L1
L0:
POP BP
RET 2
L1:
PUSH BP
MOV BP,SP
MOV AX,[BP+4]
MOV a2,AX
MOV AX,2
MOV BX,a2
MUL BX
MOV t0,AX

MOV AX,t0
JMP L0

JMP L0
f ENDP
g PROC
JMP L3
L2:
POP BP
RET 2
L3:
PUSH BP
MOV BP,SP
MOV AX,[BP+4]
MOV a3,AX
MOV AX,[BP+6]
MOV b3,AX
PUSH a3
CALL f
MOV t1,AX

MOV AX,a3
MOV BX,t1
ADD BX,AX
MOV t2,BX

MOV AX,b3
MOV BX,t2
ADD BX,AX
MOV t3,BX

MOV AX,t3
MOV x3,AX

MOV AX,x3
JMP L2

JMP L2
g ENDP
main PROC
MOV AX,@DATA
MOV DS,AX

JMP L5
L4:
MOV AH,4CH
INT 21H
L5:
MOV AX,1
MOV a4,AX

MOV BX,2
ADD BX,BX
MOV AX,c4[BX]
MOV t4,AX

MOV AX,2
MOV c4[BX],AX

MOV BX,2
ADD BX,BX
MOV AX,c4[BX]
MOV t5,AX

PUSH 1
PUSH t5
CALL g
MOV t6,AX

MOV AX,t6
MOV a4,AX

MOV AX,a4
CALL PRINT
MOV AX,0
JMP L4

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
