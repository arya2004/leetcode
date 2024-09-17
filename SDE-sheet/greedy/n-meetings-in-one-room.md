# N Meetings in One Room - Solution in Java

## Problem Statement

You are given the timings of `n` meetings in the form of two arrays: `start[]` and `end[]`. `start[i]` represents the start time of the `i-th` meeting, and `end[i]` represents the end time of the `i-th` meeting. The task is to find the **maximum number of meetings** that can be accommodated in a single meeting room, where only one meeting can be held at a time. Importantly, the start time of one meeting cannot coincide with the end time of another.

### Examples

#### Example 1:
**Input**:
``` 
n = 6
start[] = [1, 3, 0, 5, 8, 5]
end[] = [2, 4, 6, 7, 9, 9]
```
**Output**: 
```
4
```
**Explanation**: The maximum four meetings that can be held are `(1, 2)`, `(3, 4)`, `(5, 7)`, and `(8, 9)`.

#### Example 2:
**Input**:
```
n = 3
start[] = [10, 12, 20]
end[] = [20, 25, 30]
```
**Output**:
```
1
```
**Explanation**: Only one meeting can be held as none of the meetings overlap.

## Approach

### Step-by-Step Solution

1. **Pairing Start and End Times**: 
   First, we need to associate each meeting's start and end times together. We can create a custom class (`Data`) that stores each meeting's start time, end time, and position.

2. **Sorting by End Time**: 
   The idea is to sort the meetings based on their end times. This allows us to maximize the number of meetings by always choosing the one that finishes the earliest (greedy approach). If two meetings end at the same time, their order doesn't matter as long as their start times do not overlap with the previously selected meeting.

3. **Greedy Selection**: 
   After sorting, iterate through the sorted meetings and select a meeting only if its start time is greater than the end time of the last selected meeting.

4. **Return Result**: 
   Count and return the maximum number of meetings that can be accommodated.

### Java Code Implementation

```java
import java.util.Arrays;

class Data {
    int start;
    int end;
    int pos;
}

class Solution {
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    public int maxMeetings(int n, int start[], int end[]) {
        // Create an array of Data objects to store start, end, and position
        Data[] arr = new Data[n];
        
        // Initialize Data objects for each meeting
        for(int i = 0; i < n; i++){
            arr[i] = new Data(); 
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i + 1;
        }
        
        // Sort the meetings by their end times using a custom comparator
        Arrays.sort(arr, (a, b) -> a.end - b.end);
        
        // Variable to store the number of maximum meetings
        int maxMeetings = 1;
        
        // Track the end time of the last meeting that was selected
        int endLimit = arr[0].end;
        
        // Iterate over the remaining meetings
        for (int i = 1; i < n; i++) {
            // Select the meeting if it starts after the last selected meeting
            if (arr[i].start > endLimit) {
                maxMeetings++;
                endLimit = arr[i].end;
            }
        }
        
        return maxMeetings; // Return the result
    }
}
```

### Explanation of Code

1. **Data Class**: This is a custom class that stores the `start`, `end`, and `pos` (position) of each meeting.
2. **Sorting**: We use `Arrays.sort` to sort meetings by their end times. This allows us to use a greedy approach to maximize the number of meetings.
3. **Greedy Selection**: After sorting, we select meetings that start after the last selected meeting ends.
4. **Time Complexity**: The overall time complexity is dominated by the sorting step, which is `O(n log n)`.
5. **Space Complexity**: We use an additional array of size `n`, making the space complexity `O(n)`.

## Time and Space Complexity

- **Time Complexity**: `O(n log n)`
   - Sorting the meetings by their end times takes `O(n log n)` time.
   - The iteration to select meetings takes `O(n)` time.
   - Therefore, the overall time complexity is `O(n log n)`.

- **Space Complexity**: `O(n)`
   - We are using an additional array of size `n` to store the `Data` objects representing each meeting. Hence, the space complexity is `O(n)`.

## Conclusion

This problem can be effectively solved using a greedy approach by sorting the meetings based on their end times. This ensures that we always choose the meeting that leaves the room available for the maximum number of subsequent meetings. The time complexity of the solution is optimal at `O(n log n)`, and it uses `O(n)` additional space for storing the meeting data.