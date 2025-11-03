## Algorithm: Round Robin Scheduling

1. **Start.**  
2. **Take** the number of processes as input.  
3. **For each process**, input:  
   - Arrival Time (AT)  
   - Burst Time (BT)  
4. **Input** the **Time Quantum (TQ)**.  
5. **Initialize** the remaining burst time (**RBT**) for each process equal to its burst time.  
6. **Set** the current time (**CTime**) to **0** and the count of completed processes to **0**.  
7. **Create** a ready queue to manage processes.  
8. **Add** all processes that have arrived at or before the current time to the ready queue.  
9. **While** not all processes are completed:  
   - If the queue is **empty**, increase the current time by **1** and check again for new arrivals.  
   - **Take** the first process from the queue.  
   - **Execute** it for the time quantum or until it finishes, whichever comes first.  
   - If the process **finishes**:  
     - Record its **Completion Time (CT)**.  
     - Calculate **Turnaround Time (TAT) = CT - AT**.  
     - Calculate **Waiting Time (WT) = TAT - BT**.  
     - Mark it as **completed**.  
   - If the process is **not finished**, add it **back to the end** of the queue with its updated remaining burst time.  
   - **Add** any newly arrived processes to the ready queue before the next execution cycle.  
10. **After** all processes are completed, calculate:  
    - **Average Turnaround Time = ΣTAT / n**  
    - **Average Waiting Time = ΣWT / n**  
11. **Display** the process table including:  
    - Process ID, Arrival Time, Burst Time, Completion Time, Turnaround Time, and Waiting Time.  
12. **End.**
