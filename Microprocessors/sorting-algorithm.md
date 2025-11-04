# Algorithm: Sorting an Array (Ascending Order)

## Steps

1. **Start** the program.

2. **Define** an array `STRING1` containing 5 unsigned 8-bit numbers in the data segment.

3. **Initialize** the data segment by loading its address into the `DS` register.

4. **Load** the total number of passes (4) into the `CH` register.  
- In bubble sort, for `n` elements, `(n - 1)` passes are needed.

5. **Label `UP2:`** — marks the start of the **outer loop** (for each pass).

6. Inside the outer loop:
- **Load** `CL` with `4` — the number of comparisons per pass.  
- **Load** the offset address of the array (`STRING1`) into the `SI` register.

7. **Label `UP1:`** — marks the start of the **inner loop** for comparing and swapping adjacent elements.

8. **Move** the current array element into `AL`.

9. **Move** the next array element into `BL`.

10. **Compare** the two elements:  
 ```
 CMP AL, BL
 ```

11. **If** `AL < BL`, jump to label `DOWN` (no swap needed):  
 ```
 JB DOWN
 ```

12. **If** `AL ≥ BL`, perform the swap:
 ```
 MOV DL, [SI+1]
 XCHG [SI], DL
 MOV [SI+1], DL
 ```

13. **Label `DOWN:`**  
 - **Increment** `SI` to move to the next pair:  
   ```
   INC SI
   ```  
 - **Decrement** `CL` (comparison counter):  
   ```
   DEC CL
   ```  
 - **If** `CL ≠ 0`, jump back to `UP1` to continue inner loop:  
   ```
   JNZ UP1
   ```

14. **After inner loop ends**, decrement the outer loop counter `CH`:  
 ```
 DEC CH
 ```

15. **If** `CH ≠ 0`, jump back to `UP2` to start the next pass:  
 ```
 JNZ UP2
 ```

16. When all passes are completed, the array is sorted in **ascending order**.

17. **Terminate** the program using:  
 ```
 INT 3
 ```

18. **Stop**
