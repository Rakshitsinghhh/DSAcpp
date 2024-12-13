#include <iostream>
#include <queue> // Include for level-order traversal
using namespace std;

// Node class for the AVL tree
class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        height = 1; // New node is initially added at leaf
        left = right = nullptr;
    }
};

// Function to get the height of a node
int height(Node* node) {
    return node ? node->height : 0;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Function to perform a right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;

    // Update heights
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x; // New root after rotation
}

// Function to perform a left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to insert a value into the AVL tree
Node* insert(Node* node, int data) {
    // Perform normal BST insertion
    if (!node) return new Node(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Equal values are not allowed in AVL tree
        return node;

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor to check if the node is unbalanced
    int balance = getBalance(node);

    // Perform rotations if necessary
    if (balance > 1 && data < node->left->data) // Left Left Case
        return rightRotate(node);

    if (balance < -1 && data > node->right->data) // Right Right Case
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) { // Left Right Case
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) { // Right Left Case
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function for in-order traversal of the AVL tree
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Function for level-order traversal with edges in the AVL tree
void levelorder(Node* root) { // Corrected parameter type
    if (!root) return;

    queue<Node*> q; // Corrected type
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {   
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {  // Level separator
            cout << endl;
            if (!q.empty()) {
                q.push(NULL); // Push NULL for next level
            }
        } else {
            // Print node and its children edges
            cout << temp->data;
            if (temp->left) {
                cout << " -> " << temp->left->data; // Edge to left child
                q.push(temp->left);
            } else {
                cout << " -> NULL"; // No left child
            }
            if (temp->right) {
                cout << " -> " << temp->right->data; // Edge to right child
                q.push(temp->right);
            } else {
                cout << " -> NULL"; // No right child
            }
            cout << "  | ";  // Separator for multiple nodes on the same level
        }
    }
}

int main() {
    Node* root = nullptr;

    // Insert elements into the AVL tree
    root = insert(root, 21);
    root = insert(root, 26);
    root = insert(root, 9);
    root = insert(root, 4);
    root = insert(root, 14);
    root = insert(root, 28);
    root = insert(root, 18);
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);

    // Print in-order traversal of the AVL tree
    cout << "In-order traversal of the AVL tree:\n";
    inOrder(root);
    cout << endl;

    // Print level-order traversal with edges of the AVL tree
    cout << "Level-order traversal with edges of the AVL tree:\n";
    levelorder(root); // Corrected function name
    cout << endl;

    return 0;
}
