# Algorithm: LRU (Least Recently Used) Page Replacement

## Steps

1. **Start**

2. **Input** the total number of frames available in memory.  
   - These are the slots available to hold pages.

3. **Input** the total number of pages in the reference string.

4. **Input** the page reference string.  
   - This is the order in which the CPU requests pages.

5. **Initialize** all frames as empty (mark them as `-1` or “no page loaded”).

6. **Initialize** a counter or tracker that records the “last used time” of each page.  
   - This helps identify which page was used least recently.

7. **Initialize** the page fault counter to `0`.

---

## Processing the Reference String

8. **For each page** in the reference string, repeat the following steps:

9. **Check** if the page is already present in any frame.  
   - If **yes**, it’s a *page hit* → no replacement is needed.  
   - Update the “last used time” for this page to the current step/time.  
   - Continue to the next page.

10. If **no**, it’s a *page fault* → proceed to load or replace.

11. **If there is still an empty frame:**  
    - Place the new page in the first available empty slot.  
    - Update the “last used time” for this newly loaded page.  
    - Increase the page fault counter by `1`.

12. **If no empty frame is available (all are filled):**  
    - Identify the page that was used least recently (the one with the oldest “last used time”).  
    - Replace that page with the new page.  
    - Update the “last used time” for the newly loaded page.  
    - Increase the page fault counter by `1`.

13. **Continue** to the next page in the reference string.

---

## After Processing All Pages

14. **Display** the total number of page faults.

15. *(Optionally)* **Display** the final state of all frames.

16. **End**
