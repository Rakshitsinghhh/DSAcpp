#include<iostream>
#include<vector>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    // Constructor to initialize node
    node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

int main()
{
    // Input data to create the list
    vector<int> a = {1, 2, 3, 4, 5, 6};

    // Create the head node
    node* head = new node(a[0]);
    node* prev = head;

    // Build the doubly linked list
    for (int i = 1; i < a.size(); i++)
    {
        node* temp = new node(a[i]);
        prev->next = temp;     // Set the next of the previous node
        temp->prev = prev;     // Set the prev of the current node
        prev = temp;           // Move prev to the current node (temp)
    }

    // Now 'prev' points to the last node, so let's reverse traverse using this as tail
    node* tail = prev;

    // Reverse traversal from the last node to the first
    cout << "Reverse traversal: ";
    while (tail != nullptr)
    {
        cout << tail->data << " ";  // Print the data of the current node
        tail = tail->prev;          // Move to the previous node
    }
    cout << endl;

    // Reset tail to the last node again for deletion
    tail = prev;

    // Delete nodes from the end
    while (tail != nullptr)
    {
        node* del = tail;
        tail = tail->prev;
        delete del;
    }

    return 0;
}
