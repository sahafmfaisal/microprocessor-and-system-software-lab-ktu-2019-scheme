# Algorithm: FIFO Page Replacement

## Steps

1. **Start**

2. **Input** the total number of frames available in memory.  
   - These represent the slots where pages can be loaded.

3. **Input** the total number of pages in the reference string.

4. **Input** the page reference string.  
   - This is the order in which pages are requested by the CPU.

5. **Initialize** all frames as empty (mark them as `-1` or “no page loaded”).

6. **Set** a pointer `front` to `0`.  
   - This pointer shows which frame should be replaced next, following the FIFO order.

7. **Initialize** the page fault counter to `0`.

---

## Processing the Reference String

8. **For each page** in the reference string, repeat steps 9–14:

9. **Check** if the page is already present in any frame.  
   - If **yes**, it’s a *page hit* → no replacement needed, continue to the next page.  
   - If **no**, it’s a *page fault* → proceed to replacement.

10. **On a page fault:**
    - Load the page into the frame pointed by `front`.  
    - Increment the page fault counter by `1`.  
    - Move the `front` pointer to the next frame position.  
    - If the pointer reaches the end (last frame), wrap it back to the first frame (circular movement).

11. **Continue** checking the next page in the sequence.

---

## After Processing All Pages

12. **Display** the total number of page faults.

13. *(Optionally)* **Display** the final state of all frames.

14. **End**
