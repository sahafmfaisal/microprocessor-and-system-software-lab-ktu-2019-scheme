## Algorithm: Shortest Job First (Non-Preemptive)

1. **Start** the process scheduling.  
2. **List** all processes with their Arrival Time (AT) and Burst Time (BT).  
3. **Sort or select** processes based on Arrival Time — the one that arrives first gets first priority.  
4. **At any given time**, from the processes that have already arrived, choose the one with the **shortest burst time**.  
5. **Run** that process until it finishes execution.  
6. **When a process completes:**  
   - Record its **Completion Time (CT)**.  
   - Calculate **Turnaround Time (TAT) = CT - AT**.  
   - Calculate **Waiting Time (WT) = TAT - BT**.  
7. **Move** the current time forward to the completion time of that process.  
8. **Repeat** the same step: from all remaining processes that have arrived, pick the one with the smallest burst time next.  
9. **If** no process has arrived yet, move the current time forward by **1 unit**.  
10. **Continue** until all processes are completed.  
11. **Finally**, calculate:  
    - **Average Turnaround Time = ΣTAT / n**  
    - **Average Waiting Time = ΣWT / n**  
12. **End.**
