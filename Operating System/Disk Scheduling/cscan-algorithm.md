# Algorithm: C-SCAN (Circular SCAN) Disk Scheduling

## Steps

1. **Start**

2. **Input** the total number of cylinders in the disk.  
   - Ensure it’s greater than zero.

3. **Input** the number of disk requests.  
   - Make sure it’s a positive number.

4. **Input** the sequence of disk requests.  
   - Each request must be within the range `0` to `(total cylinders − 1)`.

5. **Input** the initial head position.  
   - Ensure it’s also within the valid range.

6. **Sort** the request sequence in ascending order.  
   *(This makes it easy to process requests in the correct order.)*

7. **Initialize** total seek time to zero.

8. **Set** the current head to the initial head position.

9. **Find** the first request that is greater than or equal to the current head position.  
   - This marks the point where the head will start moving forward.

10. **Move the head in the upward direction** (toward higher-numbered cylinders):
    - For each request greater than or equal to the current head:
      - Move the head to that request.  
      - Add the distance moved to the total seek time.  
      - Print the head movement.

11. **After serving all requests in the upward direction:**
    - If the head has not yet reached the last cylinder `(totalCylinders − 1)`:
      - Move it to the end of the disk.  
      - Add this movement to the total seek time.  
      - Display the head position.

12. **Jump back** to the start of the disk `(cylinder 0)`.  
    - This jump is not a servicing movement—it represents the circular motion.  
    - Add the distance from the last cylinder to the first (end-to-start jump) to the total seek time.  
    - Display the head position as it resets to 0.

13. **Continue servicing** the remaining requests that were before the initial head position (the smaller values):  
    - Move the head from 0 to each of these remaining requests (in ascending order).  
    - Add the distance moved to the total seek time.  
    - Print the head movement.

14. **After all requests are completed:**  
    - Display the total seek time.

15. **End**
