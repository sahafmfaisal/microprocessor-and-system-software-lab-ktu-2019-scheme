DATA SEGMENT
    A   DW 1234H, 5678H      
    B   DW 8765H, 4321H   
    N1  DW 4 DUP(?)
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX
    MOV DX, 00H              
    MOV AX, A
    MOV BX, B
    CLC 
    SUB AX, BX      
    MOV N1, AX  
    MOV AX, A+2
    MOV BX, B+2
    SBB AX, BX              
    MOV N1+2, AX                  
    SBB DX, 00H      
    MOV N1+4, DX  
    MOV AH, 4CH
    INT 3H

CODE ENDS
END START