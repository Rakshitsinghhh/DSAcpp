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
        node* temp = new node(a[i]);
        mover->next=temp;
        mover=temp;
    }


    mover=head;

    while(mover!=nullptr)
    {
        cout<<mover->data<<" ";
        mover=mover->next;
    }
    cout<<endl;

    cout<<"enter new head";
    int j;
    cin>>j;

    node* newhead= new node(j);
    newhead->next=head;
    head= newhead;

    mover=head;

    while(mover!=nullptr)
    {
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    mover=head;
    while(mover!=nullptr)
    {   
        node* temp =mover;
        mover=mover->next;
        delete temp;

    }

}