#include <iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Function to create a tree using user input
node* setval() {
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    node* root = new node(data);
    cout << "Enter left child of " << data << endl;
    root->left = setval();

    cout << "Enter right child of " << data << endl;
    root->right = setval();

    return root;
}

// Preorder traversal function
void preorder(node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal function
void inorder(node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder traversal function
void postorder(node* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {   
        node* temp=q.front();
        q.pop();
        if(temp==nullptr)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }

        }

    }


}



int main() {
    node* root = nullptr;

    // Creating the binary tree
    root = setval();


    cout<<"\nlevelorder Traversal: \n";
    levelorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}
