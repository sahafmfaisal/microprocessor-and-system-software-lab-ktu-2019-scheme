# Algorithm: Displaying Two Strings Using a Macro

## Steps

1. **Start** the program.

2. **Define** two strings `MSG` and `MSG1` in the data segment,  
   each ending with the `$` symbol (required by the DOS string display function).

3. **Initialize** the data segment by loading its address into the `DS` register.

4. **Define** a macro named `PRINT` that takes one parameter `STR`  
(the name of the string to be printed).

5. Inside the `PRINT` macro:
- **Load** the offset address of the string into the `DX` register:  
  ```
  LEA DX, STR
  ```
- **Set** `AH = 09H` — the DOS interrupt function for displaying a string.  
  ```
  MOV AH, 09H
  ```
- **Call** the interrupt to display the string:  
  ```
  INT 21H
  ```

6. In the code segment:
- **Call** the macro `PRINT MSG` to print the first string (`HELLO`).
- The macro expands and executes the string display interrupt for `MSG`.

7. **Call** the macro `PRINT MSG1` to print the second string (` WORLD`).  
- The macro expands again and displays `MSG1` immediately after `MSG`.

8. **After displaying both strings**, prepare to terminate the program.

9. **Return** control to DOS.

10. **Stop**
