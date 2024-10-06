#include<iostream>
#include<vector>
using namespace std;


class node
{

    public:
    int data;
    node* next;
    node* prev;
    node(int data,node* next,node* prev)
    {
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
    node(int data)
    {

        this->data=data;
        next=nullptr;
        prev=nullptr;
    }
};
int main()
{
    vector<int> a={1,2,3,4,5};
    node* head= new node(a[0]);
    node* prev=head;

    for(int i=1;i<a.size();i++)
    {
        node* temp=new node(a[i],nullptr,prev);
        prev->next=temp;
        prev=temp;

    }

    node* temp = prev;
    while(temp!=nullptr)
    {
        cout<<temp->data;
        temp=temp->prev;
    }
    cout<<endl;


    temp=head;
    while(temp!=nullptr)
    {
        node* del=temp;
        temp=temp->next;
        delete del;


    }
    return 0;
}