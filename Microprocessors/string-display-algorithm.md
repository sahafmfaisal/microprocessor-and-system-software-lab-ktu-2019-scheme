# Algorithm: Displaying Two Strings

## Steps

1. **Start** the program.

2. **Define** two strings `A` and `B` in the data segment,  
   each ending with the `$` symbol (used as the string terminator by DOS).

3. **Initialize** the data segment by loading its address into the `DS` register

4. **Load** the offset address of the first string `A` into the `DX` register.

5. **Load** the value `09H` into `AH`.  
- This is the DOS interrupt function for displaying a string.

6. **Call** the interrupt:  
`INT 21H`  
- Displays the string stored at address `A`.

7. **Load** the offset address of the second string `B` into the `DX` register.

8. **Move** `09H` again into `AH` to select the string display function.

9. **Call** the interrupt again:  
`INT 21H`  
- Displays the string stored at address `B`.

10. **Load** `4CH` into `AH` to select the DOS program termination function.

11. **Execute**:  
 `INT 21H`  
 - Returns control to the operating system.

12. **Stop**

