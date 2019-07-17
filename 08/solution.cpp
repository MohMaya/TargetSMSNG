/*
Find a cycle in LinkedList.
*/

#include<bits/stdc++.h>
using namespace std;


struct Node
{
	int val;
	Node* next;
};


bool has_cycle(Node* head)
{
    Node *ptr1=head, *ptr2=head;

    while(ptr1 && ptr2  && ptr2->next)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
        if(ptr1==ptr2)
            return true;
        
     }
   
     return false;
}

int main()
{
	/*
		I/O and other codes.
		These types of questions only ask the programmer to implement the function has_cycle() 
	*/


	return 0;
}

