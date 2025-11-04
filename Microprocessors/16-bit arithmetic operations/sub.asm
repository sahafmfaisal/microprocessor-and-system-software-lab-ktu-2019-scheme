data segment
        a dw 6121h
        b dw 3111h
        res dw (?)
data ends

code segment
assume cs:code, ds:data

start:
        mov ax, data
        mov ds, ax
        mov ax,00h
        mov ax, a
        mov bx, b
        sub ax, bx
        mov res, ax
        int 21h

code ends
end start