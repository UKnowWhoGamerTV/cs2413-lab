// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) 
{
    if(head == NULL)
        return 0;
    if(head->next == NULL)
        return head->val;
    struct ListNode *Fast = head, *Slow = head;
    int count = 1;
    while (Fast != NULL)
    {
        count++;
        if(count%2)
            Slow = Slow->next;
        Fast = Fast->next;
    }
    return Slow->val;
}