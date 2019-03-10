
#include <bits/stdc++.h>
using namespace std;
/* Link list node */
struct Node
{
    int data;
    Node *next;
} * head;
Node *findNode(Node * head, int search_for)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}
void insert()
{
    int n, i, value;
    Node *temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (i == 0)
        {
            head = (Node *)malloc(sizeof(Node));
            head->data = value;
            head->next = NULL;
            temp = head;
            continue;
        }
        else
        {
            temp->next = (Node *)malloc(sizeof(Node));
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
    }
}
/* Function to print linked list */
void printList(Node * node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void deleteNode(Node * node_ptr);
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t, k, n, value;
    /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
    scanf("%d", &t);
    while (t--)
    {
        insert();
        scanf("%d", &k);
        Node *del = findNode(head, k);
        if (del != NULL && del->next != NULL)
        {
            deleteNode(del);
        }
        printList(head);
    }
    return (0);
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list node 
struct Node
{
int data;
Node* next;
}*/
// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
void deleteNode(Node *node)
{
    // Your code here
    if (node == NULL)
    {
        return;
    }
    else if (node->next == NULL)
    {
        node = NULL;
    }
    else
    {
        node->data = node->next->data;
        node->next = node->next->next;
    }
}