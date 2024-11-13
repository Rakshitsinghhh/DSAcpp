#include<iostream>
#include<vector>
using namespace std;


class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};

node* setval(vector<int> v)
{
    node* head=new node(v[0]);
    node* mover=head;

    for(int i=1;i<v.size();i++)
    {
        node* temp=new node(v[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;

}

void printer(node* head)
{

    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

node* swap(node* head)
{

    if(!head || !head->next)
    {
        return head;
    }

    node* current=head;

    while(current && current->next)
    {
        int temp=current->data;
        current->data=current->next->data;
        current->next->data=temp;


        current=current->next->next;

    }

    return head;
}

int main()
{
    vector<int> a={1,2,3,4,5};
    node* head=setval(a);
    
    printer(head);
    node* heads=swap(head);
    cout<<endl;
    printer(heads);



}
