#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* right;
    node* left;
    node(int data)
    {
        this->data=data;
        right=nullptr;
        left=nullptr;

    }

};

node* setval(node* root,int data)
{
    if(root==nullptr)
    {
        return new node(data);
    }

    if(data<root->data)
    {
        root->left=setval(root->left,data);
    }
    else
    {
        root->right=setval(root->right,data);
    }
    
    return root;
}
void preorder(node* root)
{
    if(root==nullptr)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

int main()
{
    node *root=nullptr;
    int data;


    cout<<"enter value of BST";
    while(true)
    {
        cin>>data;
        if(data==-1)
        {
            break;
        }

        root=setval(root,data);
    }
    cout<<"preorder traversal";
    preorder(root);

}