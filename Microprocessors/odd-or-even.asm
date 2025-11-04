DATA SEGMENT
    A DB 06H        
    E DB 'Even$'
    O DB 'Odd$'
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA 
    MOV DS, AX 
    MOV AX, 0000H
    MOV AL, A
    MOV BL, 02H 
    DIV BL        
    CMP AH, 00H     
    JZ L1
    MOV DX, OFFSET O
    JMP EXIT

L1:
    MOV DX, OFFSET E 

EXIT:
    MOV AH, 09H      
    INT 21H         
    MOV AH, 4CH 
    INT 21H 

CODE ENDS
END START
