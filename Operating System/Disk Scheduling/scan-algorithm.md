## Algorithm: SCAN Disk Scheduling

1. **Start.**  
2. **Input** the total number of cylinders in the disk.  
3. **Ensure** the total number is greater than zero.  
4. **Input** the number of disk requests.  
5. **Ensure** it’s a positive number.  
6. **Input** the disk request sequence (each request is a cylinder number).  
7. **Validate** that each request lies within the range **0 to (total cylinders − 1)**.  
8. **Input** the initial head position.  
9. **Ensure** it’s within the valid range **(0 to total cylinders − 1)**.  
10. **Sort** all the disk requests in **ascending order** to determine servicing order in both directions.  
11. **Initialize** the **Total Seek Time = 0**.  
12. **Set** the current head position to the **initial head**.  
13. **Find** the first request that is **greater than or equal to the current head position**.  
    - This marks the **split point** — requests to the **right** and **left** of the current head.  
14. **Move** the head in one fixed direction (usually **towards higher-numbered cylinders**):  
    - For each request **to the right** of the current head:  
      - Move the head from its current position to that request.  
      - Add the **seek distance** to the **Total Seek Time**.  
      - Display the **head movement**.  
15. **After reaching** the last request in that direction:  
    - If the head has **not reached** the end of the disk, move it to the **last cylinder (maximum cylinder number)**.  
    - Add this movement to the **Total Seek Time**.  
16. **Reverse** the head direction (start moving **towards lower-numbered cylinders**):  
    - For each remaining request **on the left side**, in **reverse order**:  
      - Move the head to that request.  
      - Add the **seek distance** to the **Total Seek Time**.  
      - Display the **head movement**.  
17. **After all requests** are completed:  
    - **Display** the **Total Seek Time**.  
18. **End.**
