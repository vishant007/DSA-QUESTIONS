#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    Node* next;

};
Node* reverse(Node* head, int k){
    if(!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node*prev = NULL;
    int count = 0;

    while (current!= NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current - next;
        count++;
    }
    if(next != NULL)
        head->next = reverse(next,k);
    
    return prev;
    


}
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Function to print linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    /* Created Linked list
       is 1->2->3->4->5->6->7->8->9 */
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    cout << "Given linked list \n";
    printList(head);
    head = reverse(head, 3);
 
    cout << "\nReversed Linked list \n";
    printList(head);
 
    return (0);
}