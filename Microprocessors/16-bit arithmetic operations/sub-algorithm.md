# Algorithm: Subtraction of Two 16-bit Numbers

## Steps

1. **Start** the program.

2. **Define** the data segment containing:
   - Two 16-bit numbers `A` and `B`
   - A variable `RES` to store the result

3. **Initialize** the data segment by loading its address into register `DS`.

4. **Clear** register `AX` to remove any previous data.  
   - Move `00H` into `AX`.

5. **Load** the first 16-bit number `A` into register `AX`.

6. **Load** the second 16-bit number `B` into register `BX`.

7. **Perform subtraction** using the instruction:  
   `SUB AX, BX`

8. The **result** will be stored in register `AX`.

9. **Move** the result from `AX` to the memory location `RES`.

10. **Terminate** the program using the software interrupt:  
    `INT 21H`

11. **Stop**
