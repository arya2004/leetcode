# 455. Assign Cookies - Solution in Java

## Problem Statement

You are given two arrays:
- `g[]`: The greed factor of children, where `g[i]` represents the minimum size of a cookie that the `i-th` child will be content with.
- `s[]`: The sizes of available cookies, where `s[j]` represents the size of the `j-th` cookie.

The task is to find the **maximum number of children** who can be content with the cookies you have. Each child can be given at most one cookie, and a child will only be content if the size of the cookie assigned to them is greater than or equal to their greed factor.

### Example 1:
**Input**:
```
g = [1, 2, 3]
s = [1, 1]
```
**Output**:
```
1
```
**Explanation**: 
You have 3 children with greed factors `[1, 2, 3]` and 2 cookies of size `[1, 1]`. 
- Only one child (the one with greed factor 1) can be content with the available cookies.

### Example 2:
**Input**:
```
g = [1, 2]
s = [1, 2, 3]
```
**Output**:
```
2
```
**Explanation**: 
You have 2 children with greed factors `[1, 2]` and 3 cookies of size `[1, 2, 3]`. 
- Both children can be content since the cookie sizes are sufficient.

### Constraints:
- \(1 \leq g.length \leq 3 \times 10^4\)
- \(0 \leq s.length \leq 3 \times 10^4\)
- \(1 \leq g[i], s[j] \leq 2^{31} - 1\)

## Approach

### Key Idea
We can use a **greedy approach** to solve this problem optimally:
1. **Sort the greed factors of the children** (`g[]`) and **sort the cookie sizes** (`s[]`).
2. Try to satisfy each child starting from the smallest greed factor and the smallest cookie size.
   - If the current cookie size can satisfy the child (i.e., cookie size ≥ greed factor), assign the cookie to the child.
   - Move to the next child and the next cookie.
   - If the cookie size is smaller than the greed factor, move to the next cookie and try again.
3. Count the number of content children.

### Steps:
1. **Sort** the greed array `g[]` and the cookie array `s[]`.
2. Use two pointers: one for the children (`gpointer`) and one for the cookies (`spointer`).
3. Loop through the children and cookies:
   - If the current cookie can satisfy the current child, increment the `gpointer` and `spointer`.
   - Otherwise, just increment the `spointer` to try the next larger cookie.
4. Return the number of satisfied children, which will be the value of `gpointer` at the end of the loop.

### Java Code Implementation

```java
import java.util.Arrays;

class Solution {
    public int findContentChildren(int[] g, int[] s) {
        // Sort the greed array and the cookie array
        Arrays.sort(g);
        Arrays.sort(s);
        
        int happy = 0;
        int glen = g.length;
        int slen = s.length;
        int gpointer = 0;  // Pointer for children
        int spointer = 0;   // Pointer for cookies

        // Greedy approach to assign cookies
        while (gpointer < glen && spointer < slen) {
            if (g[gpointer] <= s[spointer]) {
                // If the cookie can satisfy the child's greed, move to next child
                gpointer++;
            }
            // Move to the next cookie in any case
            spointer++;
        }

        // The number of happy children is the number of children pointer moved
        return gpointer;
    }
}
```

### Explanation of Code
1. **Sorting**: 
   We sort the greed factors (`g[]`) and cookie sizes (`s[]`) to make the problem easier. This allows us to assign the smallest available cookie that satisfies each child's greed.

2. **Greedy Approach**:
   - We use two pointers, `gpointer` and `spointer`, to iterate through the children and cookies respectively.
   - If the current cookie size (`s[spointer]`) can satisfy the current child's greed (`g[gpointer]`), we increment both pointers.
   - Otherwise, we move to the next cookie by incrementing only `spointer`.
   
3. **Final Result**:
   After the loop terminates, the value of `gpointer` represents the number of children who have been contented, which is the required answer.

### Time and Space Complexity

- **Time Complexity**: `O(n log n)`
  - Sorting both `g[]` and `s[]` takes `O(n log n)` where `n` is the maximum length of the arrays.
  - The subsequent iteration through the two arrays is `O(n)`.

- **Space Complexity**: `O(1)`
  - Apart from the input arrays and a few variables, no additional data structures are used. Hence, the space complexity is constant.

## Conclusion

This problem can be solved efficiently using a greedy approach by sorting the arrays and then matching the smallest available cookie to each child starting from the least greedy. The algorithm works in `O(n log n)` time and `O(1)` space, making it optimal for large inputs.