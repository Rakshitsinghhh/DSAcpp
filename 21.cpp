#include<iostream>
#include<vector>
#include <algorithm>
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

node* lmaker(vector<int> v)
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


vector<int> combi(node* head,node* head1)
{

    vector<int> final;
    node* temp=head;
    node* temp1=head1;
    while(temp!=nullptr)
    {
        final.push_back(temp->data);
        temp=temp->next;
    }

    while(temp1!=nullptr)
    {
        final.push_back(temp1->data);
        temp1=temp1->next;

    }
    return final;

}

void printer(node* head)
{
    node* temp=head;
    while(temp!=nullptr)
    {
        temp=temp->next;

    }
    cout<<endl;

}

void clear(node* head)
{
    node* temp=head;
    while(temp!=nullptr)
    {
        node* del=temp;
        temp=temp->next;
        delete del;
        
    }
}



int main()
{

    vector<int> v1={1,2,3};
    vector<int> v2={1,3,4};
    
    node* head=lmaker(v1);
    node* head1=lmaker(v2);

    vector<int> final=combi(head,head1);

    sort(final.begin(),final.end());

    node* headf=lmaker(final);


    cout << "[";
    for (size_t i = 0; i < final.size(); i++) {
        cout << final[i];
        if (i < final.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;


    clear(head);
    clear(head1);

    return 0;


}