#include <iostream>
#include <fstream>
using namespace std;
const int MaxStackSize=50;
template <class T>
class Stack
{
private:
T stacklist[MaxStackSize];
int top;
public:
Stack(void); // constructor to initialize top
//modification operations
void Push(const T& item);
T Pop(void);
int StackEmpty(void) const;

};
template <class T>
Stack<T>::Stack(void):top(-1)
{}
template <class T>
//Push
void Stack<T>::Push(const T& item)//
{
//can not push if stack has exceeded its limits
if (top==MaxStackSize-1)
{
cerr<<"Stack overflow"<<endl;
exit(1);
}
// increment top and copy item into list
top++;
stacklist[top] = item;
}
template <class T>
//pop
T Stack<T>::Pop(void)
{
T temp;
// is stack empty nothing to pop
if (top==-1)
{
cerr<<"Stack empty"<<endl;
exit(1);
}
//record the top element
temp=stacklist[top] ;
//decrement top and return the earlier top element
top--;
return temp;
}
template <class T>
int Stack<T>::StackEmpty(void) const
{
return top==-1;
}
template <class T>
class Node
{
 public :
 T data;
 // Xor of next node and previous node
 Node<T>* xnode;
};
template <class T>
Node<T>* Xor(Node<T>* x, Node<T>* y)
{
 return reinterpret_cast<Node<T>*>(
 reinterpret_cast<uintptr_t>(x)
 ^ reinterpret_cast<uintptr_t>(y));
}
template <class T>
void insert(Node<T>* &head_ref, T data)
{
 // Allocate memory for the new node
 Node<T>* new_node = new Node<T>();
 new_node -> data = data;

 // Since the new node is inserted at the
 // start, xnode of new node will always be
 // Xor of current head and NULL
 new_node -> xnode = head_ref;
 // If the linkedlist is not empty, then xnode of
 // present head node will be XOR of the new node
 // and node next to current head */
 if (head_ref != NULL)
 {
 // *(head_ref)->xnode is Xor of (NULL and next).
 // If we XOR Null with next, we get next
 head_ref->xnode = Xor(new_node, head_ref->xnode);
 }
 // Change head
 head_ref = new_node;
}


template <class T>
void printList(Node<T>* head){
 Node<T>* currPtr = head;
 Node<T>* prevPtr = NULL;
 Node<T>* nextPtr;

 cout << "The nodes of Linked List are: \n";
 // Till condition holds true
 while (currPtr != NULL) {
 // print current node
 cout << currPtr -> data<<" ";

 // get the address of next node: currPtr->xnode is
 // {nextPtr (XOR) prevPtr}, so {currPtr->xnode (XOR) prevPtr} will
 // be {nextPtr (XOR) prevPtr (XOR) prevPtr}, which is nextPtr
 nextPtr = Xor(prevPtr, currPtr -> xnode);

 // update prevPtr and currPtr for next iteration
 prevPtr = currPtr;
 currPtr = nextPtr;
 }
 cout<<endl;
}


template <class T>
Node<T>* push_front(Node<T>* &head_ref, T data)
{
    insert(head_ref,data);
}
template <class T>
Node<T>* push_rear(Node<T>* &head_ref, T data)
{
    // Allocate memory for the new node
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;
    if (head_ref == NULL)
        push_front(head_ref,data);
    // If the XOR linked list is not empty
    else {

        // Stores the address
        // of current node
        Node<T>* curr = head_ref;

        // Stores the address
        // of previous node
        Node<T>* prev = NULL;

        // Stores the XOR of next
        // node and previous node
        Node<T>* next = Xor(prev, curr->xnode);

        // Traverse the XOR linked list
        while (next != NULL ) {

            // Update prev
            prev = curr;

            // Update curr
            curr = next;

            // Update next
            next = Xor(prev, curr->xnode);
        }


        // Stores pointer to previous Node
        // as (prev ^ next ^ next) = prev
        Node<T>* temp = Xor(curr->xnode, next);

        // Stores XOR of prev and new node
        curr->xnode = Xor(temp, new_node);


        // Connect node with curr and

        new_node->xnode = Xor(curr, next);
    }

}
template <class T>
Node<T>* peek_front (Node<T>* &head_ref){
    cout  << head_ref-> data;


}
template <class T>
Node<T>* pop_front(Node<T>* &head_ref)
{

    // If list is empty
    if (head_ref == NULL)
        printf("List Is Empty");
    else {

        // Store the node to be deleted
        Node<T>* temp = head_ref;
        Node<T>* a = NULL;

        // Update the head pointer
        head_ref = Xor( a , temp->xnode);

        // When the linked list
        // contains only one node
        if (head_ref != NULL) {
            // Update head node address
            (head_ref)->xnode = Xor(a, Xor(temp,(head_ref)->xnode));
        }

    }
    return head_ref;
}
template <class T>
Node<T>* pop_rear(Node<T>* &head_ref)
{
    // Base condition
    if (head_ref == NULL)
        cout << "List is empty";
    else
    {
        Node<T>* a = NULL;

        // Stores XOR pointer in current node
        Node<T>* curr = head_ref;

        // Stores XOR pointer of in previous Node
        Node<T>* prev = NULL;

        // Stores XOR pointer of in next node
        Node<T>* next;

        // Traverse XOR linked list
        while (Xor(curr->xnode, prev) != NULL)
        {
            // Forward traversal
            next = Xor(prev, curr->xnode);

            // Update prev
            prev = curr;

            // Update curr
            curr = next;
        }
        // If the Linked List contains more than 1 node
        if (prev != NULL) {
            prev->xnode = Xor(Xor(prev->xnode, curr), a);
        }
        // Otherwise
        else {
            head_ref = NULL;
        }

        // Delete the last node from memory
        delete(curr);
    }

    // Returns head of new linked list
    return head_ref;
}

template <class T>
Node<T>* print_elements(Node<T>* &head_ref)
{
    Node<T>* next;
    Stack<T> S;
    T c;
    Node<T>* prev = NULL;
    Node<T>* curr = head_ref;
    T temp;
    if (curr == NULL)
        return NULL;
    else
    {
        S.Push(curr->data);
        while (Xor(prev, curr->xnode) != NULL)
        {
            // Forward traversal
            next = Xor(prev, curr->xnode);
            // Update prev
            prev = curr;
            // Update curr

            curr = next;
            S.Push(curr->data);
        }
        while (!S.StackEmpty()){
            c=S.Pop();
            cout  << c  << " ";
        }

}
}
int main()
{

}

