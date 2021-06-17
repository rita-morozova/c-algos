#include <stdio.h>
#include <stdlib.h>

// create a node
struct Node 
{
    int data;
    struct Node* next;
}

// list traversal
void printList(struct Node* n)
{
    while(n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}

// insert a node on the front of the list
void push(struct Node** head_ref, int new_data)
{
    // allocate Node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    //put in the data
    new_node->data = new_data;

    // make next of new node as head
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// insert a node after a given node
void insertAfter(struct Node* prev_node, int new_data)
{
    // check if the given prev_node is NULL
    if(prev_node == NULL)
    {
        printf("the given previous node cannot be NULL\n");
        return;
    }

    // allocate new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // put in the data
    new_node->data = new_data;

    // make next of new node as next of prev_node
    new_node->next = prev_node->next;

    // move the next of prev_node as new_node
    prev_node->next = new_node;
}

void deleteNode(struct Node** head_ref, int key)
{
    // store head node
    struct Node*temp = *head_ref, *prev;

    // if head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; //changed head
        free(temp); //free old head
        return;
    }

    // serach for the key to be deleted, keep track of the previous node as we need to change prev->next
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // if key was not present in linked list
    if (temp == NULL)
        return;

    // unlink the node from linked list
    prev->next = temp->next;

    free(temp); //free memory
}

// driver
int main(void)
{
    struct Node* head = NULL;

    //linked list becomes 6->NULL
    append(&head, 6);

    //insert 7 at the beginning, so it becomes 7->6->NULL
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    
    printf("\n Created Linked List is: ");
    printList(head);
    deleteNode(&head, 1);

    return 0;
}