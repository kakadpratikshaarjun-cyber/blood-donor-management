## Output

```text
Enter number of nodes: 7
Enter elements: 50 30 70 20 40 60 80

Ordinary BST Inorder Traversal: 20 30 40 50 60 70 80
Threaded BST Inorder Traversal: 20 30 40 50 60 70 80

--- Traversal Comparison ---

Ordinary BST Time Complexity: O(n)
Threaded BST Time Complexity: O(n)

Ordinary BST Auxiliary Space: O(h)
Threaded BST Auxiliary Space: O(1)

Maximum Recursive Depth: 3
Ordinary BST uses recursion.
Threaded BST uses threads without recursion.
```

### Result

Both BST and Threaded BST produce the same sorted inorder traversal. Threaded BST achieves O(1) auxiliary space during traversal, while ordinary BST requires O(h) recursive stack space.
