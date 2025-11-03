# Algorithm: Optimal Page Replacement

## Steps

1. **Start**

2. **Input** the total number of frames available in memory.  
   - These are the fixed slots used to store pages.

3. **Input** the total number of pages in the reference string.

4. **Input** the complete page reference string.  
   - This is the sequence of page numbers requested by the CPU.

5. **Initialize** all frames as empty (no page loaded).

6. **Initialize** the page fault counter to `0`.

---

## Processing Each Page Request

7. **For each page** in the reference string, repeat the following steps:

8. **Check** if the current page is already present in any of the frames.  
   - If **yes**, it’s a *page hit* → no replacement is needed.  
   - Continue to the next page.

9. If **no**, it’s a *page fault* → we must load or replace a page.

---

## Handling a Page Fault

10. **If there is at least one empty frame:**  
    - Place the new page into the first empty frame.  
    - Increase the page fault counter by `1`.

11. **If all frames are full:**  
    - Find the page that will be used farthest in the future or not used at all.  
    - For each page currently in memory, look ahead in the reference string to see when it will be used next.  
    - If a page is **not used again**, that page is chosen for replacement immediately.  
    - If all pages will be used again, select the one that will be used **farthest in the future**.  
    - Replace that page with the new one.  
    - Increase the page fault counter by `1`.

12. **Continue** to the next page in the reference string.

---

## After Processing All Pages

13. **Display** the total number of page faults.

14. *(Optionally)* **Display** the final contents of all frames.

15. **End**
