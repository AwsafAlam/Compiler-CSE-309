.MODEL SMALL
.STACK 100H
.DATA
a2 DW ?
b2 DW ?
t02 DW ?
t13 DW ?
c2 DW 3 DUP (?)
.CODE
main PROC
MOV AX,@DATA
MOV DS,AX

MOV AX,1
MOV a,AX

MOV AX,a
CMP AX,1
JG L0
MOV t02,0
JMP L1
L0:
MOV t02,1
L1:
MOV AX,t02
CMP AX,0
JE L2
MOV BX,2
ADD BX,BX
MOV AX,c[BX]
MOV t13,AX

MOV AX,2
MOV c[BX],AX


L2:
MOV AX,a
CALL PRINT
MOV AX,0

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
