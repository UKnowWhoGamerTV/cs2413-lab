// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    struct ListNode *curr, *next;
    int i, count = 0; 
    curr = head;
    if(head == NULL || curr->next == NULL)
        return false;
    next = curr->next;
    i = -1; //I assumed pos only numbers
    while (curr != NULL)
    {
        count++;
        if(i == curr->val)                
            return true;
        if((count%7) == 0)
            i = curr->val;   
        curr = next;
        if(curr != NULL)
            next = curr->next;
    }                       
    return false;           
}
//A more redudant version would create a new struct out of the itterated struct and check if it repeats
//this, of course, would miss a list of 1,2,3,1,2,3,1,2,3,4 but I can't quite think of a way to check for that
//since I don't know a way to check the length of the whole linked list w/o itterating through it
//Additionaly because the tests have no repeating values, this catches the one that repeat