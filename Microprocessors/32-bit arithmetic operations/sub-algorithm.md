# Algorithm: Subtraction of Two 32-bit Numbers

## Steps

1. **Start** the program.

2. **Define** two 32-bit numbers `A` and `B`, each represented as two 16-bit words:  
   - Lower word and higher word.  
   - Example:  
     - `A` → `A_LOW`, `A_HIGH`  
     - `B` → `B_LOW`, `B_HIGH`

3. **Reserve** memory location `N1` to store the 32-bit result  
   (two words plus a possible borrow word).

4. **Initialize** the data segment by loading its address into the `DS` register.

5. **Clear** the `DX` register to hold any borrow or overflow if generated.

6. **Load** the lower word of the first 32-bit number (`A_LOW`) into `AX`.

7. **Load** the lower word of the second 32-bit number (`B_LOW`) into `BX`.

8. **Clear** the carry flag using the instruction:  
   `CLC`  
   - This ensures subtraction starts cleanly without residual borrow.

9. **Subtract** the contents of `BX` from `AX` using:  
   `SUB AX, BX`

10. The **result** of the lower 16-bit subtraction is stored in `AX`.

11. If a **borrow** occurs, it is stored in the **Carry Flag (CF)**.

12. **Store** the result from `AX` into memory location `N1`  
    (the lower word of the result).

13. **Load** the higher word of `A` into `AX`.

14. **Load** the higher word of `B` into `BX`.

15. **Perform subtraction of higher words** along with any previous borrow using:  
    `SBB AX, BX`  
    - `SBB` (Subtract with Borrow) subtracts `BX` and the **Carry Flag (CF)** from `AX`.

16. **Store** the higher-word result from `AX` into memory location `N1 + 2`.

17. **Subtract** any final borrow from `DX` using:  
    `SBB DX, 00H`

18. **Store** the final borrow word (if generated) into `N1 + 4`.

19. **Terminate** the program using software interrupt:  
    `INT 3H` *or* `INT 21H` with `AH = 4CH`.

20. **Stop**
