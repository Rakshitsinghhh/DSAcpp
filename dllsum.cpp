#include <iostream>
#include <vector>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

node* setval(vector<int> q)
{
    node* head = new node(q[0]);
    node* prev = head;

    for(int i = 1; i < q.size(); i++)
    {
        node* temp = new node(q[i]);
        prev->next = temp;
        temp->prev = prev;
        prev = temp;
    }
    return head;
}

node* tailgetter(node* head)
{
    node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    return temp; // Return the last node (tail)
}

int sum(node* tail)
{
    int result = 0;
    node* temp = tail;
    while(temp != nullptr)
    {
        result = result * 10 + temp->data;
        temp = temp->prev;
    }
    return result;
}

void deleteList(node* &head)
{
    node* temp = head;
    while(temp != nullptr)
    {
        node* del = temp;
        temp = temp->next;
        delete del;
    }
    head = nullptr;
}

node* createResultList(int tsum)
{
    // Create a linked list from the digits of tsum in reverse order
    int digit = tsum % 10;
    node* resultHead = new node(digit);
    node* current = resultHead;
    tsum /= 10;

    while(tsum > 0)
    {
        digit = tsum % 10;
        node* temp = new node(digit);
        current->next = temp;
        temp->prev = current;
        current = temp;
        tsum /= 10;
    }
    return resultHead;
}

void printer(node* head)
{
    node* temp = head;
    cout << "[";
    while(temp != nullptr)
    {
        cout << temp->data;
        temp = temp->next;
        if(temp != nullptr) cout << ",";
    }
    cout << "]" << endl;
}



int main()
{
    vector<int> v = {2, 4, 3};
    vector<int> q = {5, 6, 4};

    node* head1 = setval(v);
    node* head2 = setval(q);

    node* tail1 = tailgetter(head1);
    node* tail2 = tailgetter(head2);

    int sum1 = sum(tail1);
    int sum2 = sum(tail2);

    int tsum=sum1+sum2;

    node* resultHead = createResultList(tsum);
    printer(resultHead);
    

    deleteList(head1);
    deleteList(head2);
    deleteList(resultHead);

    return 0;
}
