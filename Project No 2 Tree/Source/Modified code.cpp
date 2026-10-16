#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Ordinary BST
struct BSTNode {
    int data;
    BSTNode *left, *right;

    BSTNode(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert into ordinary BST
BSTNode* insertBST(BSTNode* root, int value) {
    if (root == NULL)
        return new BSTNode(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else if (value > root->data)
        root->right = insertBST(root->right, value);

    return root;
}

// Inorder traversal using stack
void inorderBST(BSTNode* root) {
    stack<BSTNode*> s;
    BSTNode* current = root;
    int maxStack = 0;

    cout << "\nOrdinary BST Inorder: ";

    while (current != NULL || !s.empty()) {

        while (current != NULL) {
            s.push(current);

            maxStack = max(maxStack, (int)s.size());

            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";

        current = current->right;
    }

    cout << "\nMaximum Auxiliary Stack Usage: "
         << maxStack << " nodes\n";
}

// Threaded BST
struct ThreadNode {
    int data;
    ThreadNode *left, *right;
    bool lthread, rthread;

    ThreadNode(int value) {
        data = value;
        left = right = NULL;
        lthread = rthread = true;
    }
};

// Insert into Threaded BST
ThreadNode* insertThreaded(ThreadNode* root, int value) {

    ThreadNode* parent = NULL;
    ThreadNode* current = root;

    while (current != NULL) {
        parent = current;

        if (value == current->data)
            return root;

        if (value < current->data) {
            if (!current->lthread)
                current = current->left;
            else
                break;
        }
        else {
            if (!current->rthread)
                current = current->right;
            else
                break;
        }
    }

    ThreadNode* node = new ThreadNode(value);

    if (parent == NULL)
        return node;

    if (value < parent->data) {
        node->left = parent->left;
        node->right = parent;

        parent->lthread = false;
        parent->left = node;
    }
    else {
        node->left = parent;
        node->right = parent->right;

        parent->rthread = false;
        parent->right = node;
    }

    return root;
}

// Find leftmost node
ThreadNode* leftMost(ThreadNode* node) {
    if (node == NULL)
        return NULL;

    while (!node->lthread)
        node = node->left;

    return node;
}

// Find inorder successor
ThreadNode* successor(ThreadNode* node) {

    if (node->rthread)
        return node->right;

    return leftMost(node->right);
}

// Threaded BST inorder traversal
void inorderThreaded(ThreadNode* root) {

    ThreadNode* current = leftMost(root);

    cout << "\nThreaded BST Inorder: ";

    while (current != NULL) {
        cout << current->data << " ";
        current = successor(current);
    }

    cout << "\nAuxiliary Stack Usage: 0 nodes\n";
}

// Display predecessor and successor threads
void displayThreads(ThreadNode* root) {

    ThreadNode* current = leftMost(root);

    cout << "\nNode\tPredecessor Thread\tSuccessor Thread\n";

    while (current != NULL) {

        cout << current->data << "\t";

        if (current->lthread && current->left != NULL)
            cout << current->left->data;
        else
            cout << "-";

        cout << "\t\t\t";

        if (current->rthread && current->right != NULL)
            cout << current->right->data;
        else
            cout << "-";

        cout << endl;

        current = successor(current);
    }
}

// Main function
int main() {

    BSTNode* bst = NULL;
    ThreadNode* tbst = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;

        bst = insertBST(bst, value);
        tbst = insertThreaded(tbst, value);
    }

    cout << "\n===== TRAVERSAL COMPARISON =====\n";

    inorderBST(bst);

    inorderThreaded(tbst);

    cout << "\n===== THREAD INFORMATION =====\n";

    displayThreads(tbst);

    cout << "\n===== COMPARISON =====\n";

    cout << "Ordinary BST: Uses auxiliary stack (O(h))\n";
    cout << "Threaded BST: No auxiliary stack (O(1))\n";
    cout << "Both traversals have O(n) time complexity.\n";

    return 0;
}
