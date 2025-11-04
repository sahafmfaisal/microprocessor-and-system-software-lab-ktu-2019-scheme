# Algorithm: Finding the Factorial of a Number

## Steps

1. **Start** the program.

2. **Define** a variable `NUM` in the data segment to hold the number whose factorial is to be calculated.

3. **Reserve** a word-sized memory location `RESULT` to store the final factorial value.

4. **Initialize** the data segment by loading its address into the `DS` register.

5. **Load** the number `NUM` into the `AL` register.

6. **Copy** the value of `AL` into the `BL` register.  
- `BL` will act as a decrementing counter.

7. **Initialize** the `AX` register with `1` — the starting value for multiplication.

8. **Label `L1:`** — marks the start of the loop for factorial calculation.

9. **Multiply** `AX` by `BL`.
- The product is stored in `AX` (assuming the result fits within 16 bits).

10. **Decrement** `BL` by `1` to reduce the multiplier:  
 ```
 DEC BL
 ```

11. **Check** if `BL ≠ 0` using:  
 ```
 JNZ L1
 ```
 - If `BL ≠ 0`, jump back to label `L1` and continue multiplication.  
 - If `BL = 0`, the factorial calculation is complete.

12. **Move** the final result from `AX` into the memory location `RESULT`:  
 ```
 MOV RESULT, AX
 ```

13. **Terminate** the program using:  
 ```
 INT 3
 ```

14. **Stop**
