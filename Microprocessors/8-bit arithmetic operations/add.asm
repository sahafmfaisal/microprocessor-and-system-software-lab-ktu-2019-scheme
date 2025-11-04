data segment
        a db 6h
        b db 3h
        res db (?)
data ends

code segment
assume cs:code, ds:data

start:
        mov ax, data
        mov ds, ax
        mov ah,00h
        mov al, a
        mov bl, b
        add al, bl
        mov res, al
        int 21h

code ends
end start