# Algorithm: Pass One of Assembler

## Steps

1. **Start**

2. **Open all required files:**
   - **Input file:** Source program  
   - **OPTAB file:** Contains operation codes and their machine equivalents  
   - **SYMTAB file:** To store symbols and their addresses  
   - **Intermediate file:** To store intermediate output  
   - **Length file:** To store the length of the assembled program

3. **Read** the first line (label, opcode, operand).

4. **If** `opcode = START`:
   - Set **starting address = operand**
   - Initialize **LOCCTR = starting address**
   - Write the line to the intermediate file  
   **Else**, set **LOCCTR = 0**

---

## Processing the Source Program

5. **While** `opcode ≠ END`:
   - Write the current **LOCCTR**, **label**, **opcode**, and **operand** to the intermediate file.  
   - **If** the label exists, add it to **SYMTAB** with the current **LOCCTR**.  
   - **If** `opcode` is found in **OPTAB**, then  
     `LOCCTR = LOCCTR + 3`  
   - **Else if** `opcode = WORD`, then  
     `LOCCTR = LOCCTR + 3`  
   - **Else if** `opcode = RESW`, then  
     `LOCCTR = LOCCTR + (3 × operand)`  
   - **Else if** `opcode = BYTE`, then  
     Increase **LOCCTR** based on the constant length.  
   - **Else if** `opcode = RESB`, then  
     `LOCCTR = LOCCTR + operand`  
   - **Read** the next line.

---

## Completing Pass One

6. When `opcode = END`, write it to the intermediate file.

7. **Compute** the program length:  
   `Program length = LOCCTR − starting address`

8. **Store** the program length in the length file.

9. **Display**:
   - Input file  
   - Intermediate file  
   - Symbol table (SYMTAB)

10. **End**
