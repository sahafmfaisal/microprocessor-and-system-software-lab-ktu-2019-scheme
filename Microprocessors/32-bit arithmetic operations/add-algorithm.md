# Algorithm: Addition of Two 32-bit Numbers

## Steps

1. **Start** the program.

2. **Define** two 32-bit numbers `A` and `B` as two consecutive 16-bit words each:  
   - Lower word and higher word.  
   - Example:  
     - `A` → `A_LOW`, `A_HIGH`  
     - `B` → `B_LOW`, `B_HIGH`

3. **Reserve** memory location `N1` to store the 32-bit result  
   (four bytes or two words).

4. **Initialize** the data segment by loading its address into the `DS` register.

5. **Clear** the `DX` register to hold any possible carry after addition.

6. **Load** the lower word of the first 32-bit number (`A_LOW`) into `AX`.

7. **Load** the lower word of the second 32-bit number (`B_LOW`) into `BX`.

8. **Clear** the carry flag using the instruction:  
   `CLC`

9. **Add** the contents of `AX` and `BX` using:  
   `ADD AX, BX`

10. The sum of the lower words is stored in `AX`.

11. If a carry is generated, it will be automatically stored in the **Carry Flag (CF)**.

12. **Move** the result from `AX` into the lower word of the result location (`N1`).

13. **Load** the higher word of `A` into `AX` and the higher word of `B` into `BX`.

14. **Add** the higher words along with any carry using:  
    `ADC AX, BX`  
    - `ADC` adds both numbers plus the carry flag.

15. **Store** the higher-word result in the next word of `N1` (`N1 + 2`).

16. **Add** the carry (if any) from the higher-word addition to `DX` using:  
    `ADC DX, 00H`  
    - This handles overflow beyond 32 bits.

17. **Store** the carry word (if generated) into `N1 + 4`.

18. **Terminate** the program using software interrupt:  
    `INT 3H` *or* `INT 21H` with `AH = 4CH`.

19. **Stop**
