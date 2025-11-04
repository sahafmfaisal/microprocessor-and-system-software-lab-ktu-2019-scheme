# Algorithm: Checking Whether a Number is Even or Odd

## Steps

1. **Start** the program.

2. **Define** an 8-bit number `A` in the data segment.

3. **Define** two strings `E` and `O` to display messages:  
   - `E = "Even$"`  
   - `O = "Odd$"`

4. **Initialize** the data segment by loading its address into the `DS` register.

5. **Clear** register `AX` to ensure there are no garbage values.

6. **Move** the number `A` into the `AL` register.

7. **Load** the divisor value `02H` into `BL`.

8. **Perform division** using the instruction:  
`DIV BL`  
- After division:  
  - `AL` → Quotient  
  - `AH` → Remainder

9. **Compare** `AH` (remainder) with `00H`.

10. **If** `AH = 00H`, jump to label `L1` → *(The number is even).*

11. **If** `AH ≠ 00H`, move the offset address of string `O` (Odd) into `DX`  
 and jump to label `EXIT`.

12. **At label L1:**  
 - Move the offset address of string `E` (Even) into `DX`.

13. **Move** `09H` into `AH` to select the DOS string display function.

14. **Call** the interrupt:  
 `INT 21H`  
 - Displays the message (“Even” or “Odd”).

15. **Move** `4CH` into `AH` to terminate the program.

16. **Call**:  
 `INT 21H`  
 - Returns control to DOS.

17. **Stop**
