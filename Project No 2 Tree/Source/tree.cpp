#include <iostream>
using namespace std;

// Ordinary BST
struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert into Ordinary BST
Node* insertBST(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else if (value > root->data)
        root->right = insertBST(root->right, value);

    return root;
}

// Inorder Traversal of Ordinary BST
void inorderBST(Node* root, int depth, int &maxDepth) {
    if (root == NULL)
        return;

    if (depth > maxDepth)
        maxDepth = depth;

    inorderBST(root->left, depth + 1, maxDepth);
    cout << root->data << " ";
    inorderBST(root->right, depth + 1, maxDepth);
}

// Threaded BST Node
struct TNode {
    int data;
    TNode *left, *right;
    bool lthread, rthread;

    TNode(int value) {
        data = value;
        left = right = NULL;
        lthread = rthread = true;
    }
};

// Insert into Threaded BST
TNode* insertTBST(TNode* root, int value) {
    TNode *ptr = root;
    TNode *parent = NULL;

    while (ptr != NULL) {
        if (value == ptr->data)
            return root;

        parent = ptr;

        if (value < ptr->data) {
            if (!ptr->lthread)
                ptr = ptr->left;
            else
                break;
        }
        else {
            if (!ptr->rthread)
                ptr = ptr->right;
            else
                break;
        }
    }

    TNode* temp = new TNode(value);

    if (parent == NULL)
        return temp;

    if (value < parent->data) {
        temp->left = parent->left;
        temp->right = parent;
        parent->lthread = false;
        parent->left = temp;
    }
    else {
        temp->left = parent;
        temp->right = parent->right;
        parent->rthread = false;
        parent->right = temp;
    }

    return root;
}

// Find Leftmost Node
TNode* leftmost(TNode* root) {
    if (root == NULL)
        return NULL;

    while (!root->lthread)
        root = root->left;

    return root;
}

// Inorder Traversal of Threaded BST
void inorderTBST(TNode* root) {
    TNode* current = leftmost(root);

    while (current != NULL) {
        cout << current->data << " ";

        if (current->rthread)
            current = current->right;
        else
            current = leftmost(current->right);
    }
}

// Main Function
int main() {
    Node* bst = NULL;
    TNode* tbst = NULL;

    int n, value;
    int maxDepth = 0;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> value;

        bst = insertBST(bst, value);
        tbst = insertTBST(tbst, value);
    }

    cout << "\nOrdinary BST Inorder Traversal: ";
    inorderBST(bst, 1, maxDepth);

    cout << "\nThreaded BST Inorder Traversal: ";
    inorderTBST(tbst);

    cout << "\n\n--- Traversal Comparison ---\n";

    cout << "Ordinary BST Time Complexity: O(n)\n";
    cout << "Threaded BST Time Complexity: O(n)\n";

    cout << "Ordinary BST Auxiliary Space: O(h)\n";
    cout << "Threaded BST Auxiliary Space: O(1)\n";

    cout << "Maximum Recursive Depth: "
         << maxDepth << endl;

    cout << "Ordinary BST uses recursion.\n";
    cout << "Threaded BST uses threads without recursion.\n";

    return 0;
}
