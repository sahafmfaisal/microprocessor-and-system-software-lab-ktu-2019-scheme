# Algorithm: Decimal to Hexadecimal Conversion

## Steps

1. **Start** the program.

2. **Define** a string `MESSAGE` in the data segment to prompt the user for input:  
   `"ENTER THE DECIMAL VALUE$"`

3. **Initialize** the data segment by loading its address into the `DS` register.

4. **Display** the input message using DOS interrupt.

5. **Initialize** `CX = 10` — this acts as the multiplier for base-10 calculations.

6. **Clear** `BX` (set to 0).  
- This register will hold the numeric value entered by the user.

---

## Decimal Input Routine

7. **Label `INPUT:`** — start reading the input digits from the keyboard.

8. Use DOS interrupt to read one character.

9. **Compare** the ASCII value of the input with `13` (Enter key).

10. **Convert** the ASCII digit to its numeric equivalent:  
 ```
 SUB AL, 48
 ```

11. **Clear** `AH` to form a valid 16-bit number:
 ```
 MOV AH, 00
 ```

12. **Push** `AX` onto the stack temporarily.

13. **Multiply** the accumulated total in `BX` by 10 to shift digits left:  
 ```
 MOV AX, BX  
 MUL CX  
 MOV BX, AX
 ```

14. **Pop** the digit back from the stack into `AX` and **add** it to `BX`:  
 ```
 POP AX  
 ADD BX, AX
 ```

15. **Jump** back to `INPUT` to read the next digit:
 ```
 JMP INPUT
 ```

---

## Decimal to Hexadecimal Conversion Routine

16. **Label `INPUT_END:`** — input is complete, number is stored in `BX`.

17. **Move** the decimal number into `AX` for conversion:
 ```
 MOV AX, BX
 ```

18. **Set** `CX = 16` — the divisor for base-16 conversion.

19. **Clear** `BX` and reset it to 0 (used as digit counter).

20. **Label `CONVERSION:`** — begin conversion loop.  
 Divide the number in `AX` by 16:
 ```
 DIV CX
 ```
 - Quotient → `AX`  
 - Remainder → `DX`

21. **Push** `DX` (remainder) onto the stack.  
 Each remainder represents one hexadecimal digit.

22. **Increment** `BL` (used to count total digits).

23. **If** `AX ≠ 0`, repeat the loop:
 ```
 JNZ CONVERSION
 ```

---

## Display Routine

24. **Print a newline** before displaying the result:
 ```
 MOV DL, 13  
 MOV AH, 02H  
 INT 21H  
 MOV DL, 10  
 INT 21H
 ```

25. **Label `OUTPUT_START:`** — begin printing digits from stack (reverse order).

26. **Pop** one digit from the stack into `AX`:
 ```
 POP AX
 ```

27. **Check** if the value in `AL` > 9:
 ```
 CMP AL, 9  
 JG OUTPUT_HEX
 ```

28. **For digits 0–9**, convert to ASCII by adding 48:
 ```
 ADD AL, 48  
 JMP PRINT_CHAR
 ```

29. **Label `OUTPUT_HEX:`** — for digits 10–15 (A–F), convert to ASCII:
 ```
 ADD AL, 55
 ```

30. **Label `PRINT_CHAR:`** — display the ASCII character:
 ```
 MOV DL, AL  
 MOV AH, 02H  
 INT 21H
 ```

31. **Increment** `BH` (digit print counter) and check if more digits remain:
 ```
 INC BH  
 CMP BH, BL  
 JL OUTPUT_START
 ```

---

## End Routine

32. **Label `OUTPUT_END:`** — when all digits are printed, terminate the program:
 ```
 MOV AH, 4CH  
 INT 21H
 ```

33. **Stop**
