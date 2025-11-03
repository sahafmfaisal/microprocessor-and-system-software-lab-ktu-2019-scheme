## Algorithm: FCFS Disk Scheduling

1. **Start.**  
2. **Input** the total number of cylinders in the disk.  
3. **Validate** that the number of cylinders is positive.  
4. **Input** the number of disk I/O requests.  
5. **Validate** that the number of requests is greater than zero.  
6. **Input** each disk request (the cylinder numbers).  
7. **Ensure** each request lies within the valid range (**0 to total cylinders − 1**).  
8. **Input** the initial position of the disk head.  
9. **Validate** that the initial head position is within the range (**0 to total cylinders − 1**).  
10. **Initialize** the **Total Seek Time = 0**.  
11. **Set** the current head position to the initial head position.  
12. **Display** the sequence of disk requests.  
13. **For each** request in the order they were entered:  
    - Calculate the **seek distance = |current head − next request|**.  
    - Add this distance to the **Total Seek Time**.  
    - Move the disk head to the **requested cylinder**.  
    - Display the **head movement**.  
14. **After all requests are processed:**  
    - **Display** the **Total Seek Time**.  
15. **End.**
