# Algorithm: Finding the Largest Number in an Array

## Steps

1. **Start** the program.

2. **Define** an array `A` of 8-bit numbers in the data segment.

3. **Reserve** one memory location `RES` to store the largest number found.

4. **Initialize** the data segment by loading its address into the `DS` register.

5. **Load** the total number of elements (e.g., 5) into the `CX` register  
— this will act as the counter.

6. **Clear** the `BL` register by setting it to `00H`.  
- `BL` will hold the current largest number during comparisons.

7. **Load** the offset address of the array `A` into the `SI` register.

8. **Start** the loop labeled `UP:`  

- **Move** the current array element (pointed by `SI`) into the `AL` register.  
  ```
  MOV AL, [SI]
  ```

- **Compare** `AL` (current element) with `BL` (current largest):  
  ```
  CMP AL, BL
  ```

- **If** `AL < BL`, jump to label `NXT` (no update needed).  
  ```
  JB NXT
  ```

- **If** `AL ≥ BL`, move `AL` into `BL` (update the current largest value).  
  ```
  MOV BL, AL
  ```

9. **Label NXT:**  
- **Increment** `SI` to point to the next element:  
  ```
  INC SI
  ```  
- **Decrement** `CX` to count down remaining elements:  
  ```
  DEC CX
  ```  
- **If** `CX ≠ 0`, jump back to label `UP` to continue comparisons:  
  ```
  JNZ UP
  ```

10. **After the loop ends**, move the final largest value from `BL` into memory location `RES`:  
 ```
 MOV RES, BL
 ```

11. **Terminate** the program using interrupt:  
 - `INT 3H` *(for debugger stop)*  
 - or `INT 21H` with `AH = 4CH` *(to return control to DOS)*.

12. **Stop**
