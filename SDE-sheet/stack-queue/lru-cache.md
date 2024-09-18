# LRU Cache - Explanation and Java Code

## Problem Statement

The task is to implement an **LRU (Least Recently Used) Cache**. An LRU cache evicts the least recently used item when its capacity is exceeded. The LRU cache must support two operations:
1. `get(int key)` - Returns the value of the key if the key exists, otherwise returns `-1`.
2. `put(int key, int value)` - Updates the value of the key if the key exists. Otherwise, adds the key-value pair to the cache. If the cache reaches its capacity, it must evict the least recently used item before inserting a new key-value pair.

### Constraints
- The `get` and `put` operations should be performed in **O(1)** average time.
- At most \(2 \times 10^5\) operations will be called.
- Cache capacity: \(1 \leq capacity \leq 3000\).

### Example

**Input:**
```
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
```

**Output:**
```
[null, null, null, 1, null, -1, null, -1, 3, 4]
```

**Explanation:**
```
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // Cache is {1=1}
lRUCache.put(2, 2); // Cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // return -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```

## Approach

To implement an LRU Cache with **O(1)** time complexity for both `get` and `put` operations, we need two main data structures:

1. **Doubly Linked List**: This is used to maintain the order of the elements based on their usage. The most recently used element will be at the head, and the least recently used element will be at the tail. This allows us to quickly add and remove nodes from both ends in constant time.

2. **HashMap**: This is used for fast access to any element in constant time. The keys are mapped to the corresponding nodes in the linked list, allowing us to efficiently update or retrieve the cache.

### Steps:
1. **Initialization**:
   - Initialize a doubly linked list with two dummy nodes: `head` and `tail`.
   - Initialize a `HashMap` to store the key-to-node mapping.
   - Define the cache's capacity.

2. **Get Operation**:
   - If the key is present in the cache, return the value and move the accessed node to the head (marking it as most recently used).
   - If the key is not present, return `-1`.

3. **Put Operation**:
   - If the key is already present, update the value and move the node to the head.
   - If the key is not present, create a new node. If the cache has reached its capacity, remove the least recently used node (node at the tail) and then insert the new node at the head.
   - Add the new node to the map.

4. **Helper Functions**:
   - `delete(Node node)`: Removes a node from the doubly linked list.
   - `insertAfterHead(Node node)`: Inserts a node after the head.

### Java Code Implementation

```java
import java.util.HashMap;

class Node {
    int key;
    int val;
    Node prev;
    Node next;
}

class LRUCache {
    private HashMap<Integer, Node> cache = new HashMap<>();
    private int capacity;
    private Node head, tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        // Create dummy head and tail nodes
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        if (!cache.containsKey(key)) {
            return -1; // Key not found
        }
        Node node = cache.get(key);
        // Move the accessed node to the head (most recently used)
        delete(node);
        insertAfterHead(node);
        return node.val;
    }

    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            node.val = value;
            delete(node);
            insertAfterHead(node);
        } else {
            if (cache.size() == capacity) {
                // Evict the least recently used node (just before the tail)
                Node lru = tail.prev;
                cache.remove(lru.key);
                delete(lru);
            }
            // Create a new node and insert it after the head
            Node newNode = new Node();
            newNode.key = key;
            newNode.val = value;
            cache.put(key, newNode);
            insertAfterHead(newNode);
        }
    }

    // Helper function to remove a node from the doubly linked list
    private void delete(Node node) {
        Node prevNode = node.prev;
        Node nextNode = node.next;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }

    // Helper function to insert a node after the head (most recently used)
    private void insertAfterHead(Node node) {
        Node nextNode = head.next;
        head.next = node;
        node.prev = head;
        node.next = nextNode;
        nextNode.prev = node;
    }
}
```

## Explanation of Code

- **Node Class**: 
  This defines a node in the doubly linked list. Each node stores a key-value pair (`key`, `val`) and pointers to its previous (`prev`) and next (`next`) nodes.

- **LRUCache Class**:
  - **Constructor (`LRUCache`)**: Initializes the cache with the specified capacity. It sets up the doubly linked list with dummy head and tail nodes and initializes an empty HashMap (`cache`).
  
  - **`get(int key)`**:
    - If the key is found in the cache, move the node to the head (most recently used) and return its value.
    - If the key is not found, return `-1`.
  
  - **`put(int key, int value)`**:
    - If the key already exists, update its value and move it to the head.
    - If the key does not exist, check if the cache is full. If full, remove the least recently used node (before the tail). Then insert the new key-value pair as the most recently used.

  - **`delete(Node node)`**: Removes a node from the doubly linked list by adjusting the `next` and `prev` pointers of the adjacent nodes.
  
  - **`insertAfterHead(Node node)`**: Inserts a node after the head of the list, marking it as the most recently used.

## Time and Space Complexity

- **Time Complexity**: `O(1)` for both `get` and `put` operations. 
  - The `get` operation involves checking the map and updating the doubly linked list.
  - The `put` operation involves inserting or updating nodes in the doubly linked list and map.
  
- **Space Complexity**: `O(capacity)`. The space used is proportional to the cache's capacity for storing key-value pairs in the map and the doubly linked list.

## Conclusion

This solution efficiently implements the LRU cache using a combination of a **doubly linked list** and a **hash map**. Both `get` and `put` operations run in **constant time**, making it well-suited for large-scale applications where maintaining fast access to the most recently used data is essential.