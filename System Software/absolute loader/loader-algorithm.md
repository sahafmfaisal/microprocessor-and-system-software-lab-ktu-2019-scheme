# Algorithm: Absolute Loader

## Steps

1. **Start**

2. **Input** the program name.

3. **Open** the object file (`input1.txt`) for reading.

4. **Read** the first record (Header record).

5. **Extract** the program name from the header.

6. **Compare** the extracted program name with the input program name.  
   - If it matches, **continue**.  
   - Otherwise, **stop**.

---

## Processing the Object File

7. **Repeat** reading each record until the **End record** is reached:

   - **If** the record starts with `'T'` (Text record):  
     - Extract the **starting address** from the record.  
     - Convert the address from **string to integer**.  
     - Skip the control characters (`^`) and read each pair of object codes.  
     - **Print** each byte along with its corresponding **memory address**.  
     - **Increment** the address for each printed byte.

   - **If** the record starts with `'E'` (End record):  
     - **Stop** processing.

---

## Final Step

8. **Close** the file.

9. **Stop**
