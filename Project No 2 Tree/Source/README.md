# BST and Threaded BST Traversal Comparison

## Source Code Information

### 1. Description
This C++ program implements an Ordinary Binary Search Tree (BST) and an Inorder Threaded Binary Search Tree (TBST). It performs inorder traversal on both trees and compares their traversal techniques, time complexity, and auxiliary space requirements.

### 2. Concepts Used
- Binary Search Tree (BST)
- Threaded Binary Search Tree (TBST)
- Dynamic Memory Allocation
- Pointers and Structures
- Recursion
- Inorder Traversal

### 3. Main Functions

| Function | Description |
|----------|-------------|
| insertBST() | Inserts a new node into the ordinary BST. |
| inorderBST() | Performs recursive inorder traversal and records maximum recursion depth. |
| insertTBST() | Inserts nodes while maintaining predecessor and successor threads. |
| leftmost() | Finds the leftmost node in the Threaded BST. |
| inorderTBST() | Performs inorder traversal without recursion or an auxiliary stack. |
| main() | Accepts input, calls functions, and displays comparison results. |

### 4. Working of the Program

1. The user enters the number of nodes and their values.
2. The same elements are inserted into both trees.
3. The ordinary BST performs inorder traversal using recursion.
4. The Threaded BST performs inorder traversal using threads.
5. Both traversal outputs are displayed.
6. The program displays the maximum recursion depth of the ordinary BST.
7. Finally, both techniques are compared based on time and auxiliary space complexity.

### 5. Software-Based Comparison

| Parameter | Ordinary BST | Threaded BST |
|-----------|--------------|--------------|
| Traversal | Recursive | Thread-based |
| Time Complexity | O(n) | O(n) |
| Auxiliary Space | O(h) | O(1) |
| Recursion | Required in this implementation | Not Required |
| Extra Stack | Recursion Stack | Not Required |
| Traversal Output | Sorted Order | Sorted Order |

Where:
- n = Number of nodes
- h = Height of the tree

### 6. Advantages of Threaded BST
- Eliminates the need for recursion during inorder traversal.
- Does not require an auxiliary traversal stack.
- Utilizes otherwise NULL pointers as threads.
- Provides direct access to inorder successors through right threads.

### 7. Conclusion
The program demonstrates that both Ordinary BST and Threaded BST produce identical inorder traversal results. However, Threaded BST performs traversal without recursion or an additional stack, making it more space-efficient during traversal.
