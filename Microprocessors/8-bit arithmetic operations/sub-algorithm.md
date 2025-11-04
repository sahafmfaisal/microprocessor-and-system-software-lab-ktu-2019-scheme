# Algorithm: Subtraction of Two 8-bit Numbers

## Steps

1. **Start** the program.

2. **Define** the data segment with:
   - Two 8-bit numbers `A` and `B`
   - A variable `RES` to store the result

3. **Initialize** the data segment by loading its address into register `DS`.

4. **Clear** the high byte of `AX` by moving `00H` into `AH`.  
   - (Only `AL` will be used for 8-bit operations.)

5. **Load** the first number `A` into register `AL`.

6. **Load** the second number `B` into register `BL`.

7. **Perform subtraction** using the instruction:  
   `SUB AL, BL`

8. **Store** the result of addition from `AL` into the memory location `RES`.

9. **Terminate** the program using the software interrupt:  
    `INT 21H`

10. **Stop**
