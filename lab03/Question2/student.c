// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) 
{
      if(head == NULL)
      return head;      

      struct ListNode *curr = head, *next = NULL, *prev = NULL, *temp = NULL;
      int count = 1;
      while(curr != NULL)
      {
            count++;
            next = curr->next;
            if(count%2)
            {
                  curr->next = prev;
                  prev->next = next;
                  if(count == 3)
                        head = curr;
                  if(count > 4)
                        temp->next = curr;
                  temp = curr;
                  curr = prev;
                  prev = temp;
            }
            if((count+1)%2)
                  temp = prev;
            prev = curr;
            curr = next;
      }
      return head;
}