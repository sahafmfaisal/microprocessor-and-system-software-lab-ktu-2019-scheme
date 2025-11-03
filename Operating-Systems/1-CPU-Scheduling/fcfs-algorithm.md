## Algorithm: First Come First Serve (FCFS) Scheduling

1. **Start** the process scheduling.  
2. **List** all processes with their Arrival Time (AT) and Burst Time (BT).  
3. **Sort** the processes in ascending order of Arrival Time. The one that arrives first is executed first.  
4. **Set** Completion Time (CT) for the first process:  
   - CT₁ = AT₁ + BT₁  
5. **For** each remaining process *i* (from 2 to n):  
   - If **ATᵢ > CTᵢ₋₁**, then **CTᵢ = ATᵢ + BTᵢ**  
   - Else **CTᵢ = CTᵢ₋₁ + BTᵢ**  
6. **Calculate** for each process:  
   - Turnaround Time (TAT) = CT - AT  
   - Waiting Time (WT) = TAT - BT  
7. **Compute averages:**  
   - Average Turnaround Time = ΣTAT / n  
   - Average Waiting Time = ΣWT / n  
8. **Display** the table with columns:  
   - Process ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time  
9. **End.**
