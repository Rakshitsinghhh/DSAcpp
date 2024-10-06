//insert at position
//delete at postition

#include<iostream>
#include<vector>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data,node* next=nullptr)
    {
        this->data=data;
        this->next=next;

    }
};

int main()
{
    vector<int> a={1,2,3,4,5};
    node* head=new node(a[0]);
    node* mover=head;


    for(int i=1;i<a.size();i++)
    {
        node* temp =new node (a[i]);
        mover->next=temp;
        mover=temp;
    }

    mover=head;

    while(mover!=nullptr)
    {
        cout<<mover->data<<" ";
        mover=mover->next;
    }
    
    cout<<"enter new element ";
    int e;
    int p;

    cin>>e;

    cout<<"enter position";
    cin>>p;

    int c=0;

    mover=head;

    node* temp=head;
    node* newe=new node(e);
    while(mover!=nullptr)
    {

        if(c==p)
        {
            temp=mover->next;
            mover->next=newe;
            newe->next=temp;
            break;
        }
        else
        {
            mover=mover->next;
        }
        c++;
    }

    mover=head;

    while(mover!=nullptr)
    {
        cout<<mover->data<<" ";
        mover=mover->next;
    }


    mover=head;
    while(mover!=nullptr)
    {
        node* temp=mover;
        mover=mover->next;
        delete temp;
    }




}