## Algorithm: Non-Preemptive Priority Scheduling

1. **Start.**  
2. **Take** the number of processes as input.  
3. **For each process**, input:  
   - Arrival Time (AT)  
   - Burst Time (BT)  
   - Priority (smaller number = higher priority)  
4. **Mark** all processes as not completed.  
5. **Set** the current time to **0**.  
6. **Repeat** until all processes are completed:  
   - From all processes that have already arrived and are not completed, **find the one with the highest priority** (smallest priority number).  
   - If two or more have the same priority, **choose the one that arrived earlier**.  
   - If no process has arrived yet, **increment the current time by 1 unit**.  
   - Once a process is selected, **execute it completely (non-preemptive)**.  
   - Record its **Completion Time (CT)**.  
   - Calculate **Turnaround Time (TAT) = CT - AT**.  
   - Calculate **Waiting Time (WT) = TAT - BT**.  
   - **Mark** the process as completed.  
   - **Update** the current time to the completion time of that process.  
7. **After all processes finish**, calculate:  
   - **Average Turnaround Time = ΣTAT / n**  
   - **Average Waiting Time = ΣWT / n**  
8. **Display** the results in a table showing:  
   - Process ID, Arrival Time, Burst Time, Priority, Completion Time, Turnaround Time, and Waiting Time.  
9. **End.**
