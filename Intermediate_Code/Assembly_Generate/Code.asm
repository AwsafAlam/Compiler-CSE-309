.MODEL SMALL
.STACK 100H
.DATA
a DW ?
b DW ?
i DW ?
t0 DW ?
.CODE
main PROC
MOV AX,@DATA
MOV DS,AX

MOV AX,0
MOV b,AX

MOV AX,0
MOV i,AX

L4:
MOV AX,i
CMP AX,4
JL L0
MOV t0,0
JMP L1
L0:
MOV t0,1
L1:

MOV AX,t0
CMP AX,0
JE L5
MOV AX,3
MOV a,AX

L2:
MOV AX,a
DEC AX
MOV a,AX
MOV AX,a;;
CMP AX,0
JE L3
MOV AX,b
INC AX
MOV b,AX
b

JMP L2
L3:
MOV AX,i
INC AX
MOV i,AX
i
JMP L4
L5:
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
