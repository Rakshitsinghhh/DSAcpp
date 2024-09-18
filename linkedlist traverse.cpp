#include<iostream>
#include<vector>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int data,node* next)
    {

        this->data=data;
        this->next= next;
    }
    node(int data)
    {

        this->data=data;
        next=nullptr;
    }

};



node* consel(vector<int> &a)
{
    node* head=new node(a[0]);
    node* mover=head;


    for(int i=1;i<a.size();i++)
    {
        node* temp=new node(a[i]);
        mover->next=temp;
        mover=temp;


    }
    return head;
}




int main()
{
    vector<int> a={1,2,3,4,5};
    node* head=consel(a);
    node* temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;


    }
    while (head)
    {
        node* next = head->next;
        delete head;
        head = next;
    }
}