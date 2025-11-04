data segment
        a dw 6181h
        b dw 3121h
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
        div bx
        mov res, ax
        int 21h

code ends
end start