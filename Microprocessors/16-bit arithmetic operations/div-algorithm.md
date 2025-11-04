# Algorithm: Division of Two 16-bit Numbers

## Steps

1. **Start** the program.

2. **Define** the data segment with:
   - Two 16-bit numbers `A` and `B`
   - A variable `RES` to store the result

3. **Initialize** the data segment by loading its address into the `DS` register.

4. **Clear** the `AX` register to remove any previous data.  
   - Move `00H` into `AX`.

5. **Load** the first 16-bit number `A` into register `AX`.

6. **Load** the second 16-bit number `B` into register `BX`.

7. **Perform division** using the instruction:  
   `DIV BX`

8. The **32-bit result** will be stored in `DX:AX`, where:  
   - `AX` = lower word of the result  
   - `DX` = higher word of the result

9. **Move** the lower word of the result from `AX` into the memory location `RES`.

10. **Terminate** the program using the software interrupt:  
    `INT 21H`

11. **Stop**
