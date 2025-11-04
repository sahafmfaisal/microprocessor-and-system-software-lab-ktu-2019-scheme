# Algorithm: Division of Two 8-bit Numbers

## Steps

1. **Start** the program.

2. **Define** the data segment with:
   - Two 8-bit numbers `A` and `B`.
   - A variable `RES` to store the result.

3. **Initialize** the data segment by loading its address into register `DS`.

4. **Clear** register `AH` by moving `00H` into it.  
   - (Since 8-bit multiplication uses `AL` and `BL`, and the result is stored in `AX`.)

5. **Load** the first number `A` into register `AL`.

6. **Load** the second number `B` into register `BL`.

7. **Perform** division using the instruction:  
   `DIV BL`

8. The **16-bit result** will be stored in register `AX`, where:  
   - `AL` = lower byte of the result  
   - `AH` = higher byte of the result

9. **Move** the lower byte of the result (`AL`) into the memory location `RES`.

10. **End** the program using the software interrupt:  
    `INT 21H`

11. **Stop**

