# Algorithm: Pass Two Assembler

## Steps

1. **Start**

2. **Open** the required files:  
   - **Intermediate file**  
   - **Symbol Table (SYMTAB)**  
   - **Output file**  
   - **Object Code file**

3. **Read** the first line from the intermediate file.

4. **If** the opcode is `START`:  
   - Record the **program name** and **starting address**.  
   - Write the **header record** to the object code file.  
   - Move to the next line.

---

## Processing the Intermediate File

5. **For each line** until the `END` opcode:

   - **If** the opcode is found in **OPTAB**:  
     - Search for the **operand** in **SYMTAB** to find its address.  
     - Combine the **machine code** of the opcode with the **address** of the operand to form the **object code**.  
     - Write this object code to both the **output file** and **object code file**.

   - **If** the opcode is `WORD`:  
     - Convert the constant value into its object code (3 bytes).

   - **If** the opcode is `BYTE`:  
     - Convert the given constant (character or hexadecimal) into its equivalent object code.

   - **If** the opcode is `RESW` or `RESB`:  
     - Do not generate object code (they simply reserve memory).

   - Move to the next line.

---

## Finalizing the Assembling Process

6. When `END` is encountered:  
   - Write the **end record** in the object code file using the **starting address**.

7. **Display** the contents of:  
   - Intermediate file  
   - Symbol Table  
   - Output file  
   - Object code file

8. **End**
