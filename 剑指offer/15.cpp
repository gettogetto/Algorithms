/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** t1=&head;
        ListNode* t2=head;
        for(int i=1;i<n;i++){
            t2=t2->next;
        }
        while(t2->next){
            t2=t2->next;
            t1=&((*t1)->next);
        }
        *t1=(*t1)->next;
        return head;
    }
};
 /**
 use faster and lower runner solution. (2 pointers)
 the faster one move 2 steps, and slower one move only one step.
 if there's a circle, the faster one will finally "catch" the slower one. 
 (the distance between these 2 pointers will decrease one every time.)
 
 if there's no circle, the faster runner will reach the end of linked list. (NULL)
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)    
            return false;
 
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
                return true;
        }
 
        return false;
    }
};

//ÅÐ¶Ï»·Èë¿Ú 
//2 * (L1+L2) = L1 + L2 + n * C => L1 + L2 = n * C => L1 = (n - 1) C + (C - L2) 
// L1 is defined as the distance between the head point and entry point

// L2 is defined as the distance between the entry point and the meeting point

// C is defined as the length of the cycle

// n is defined as the travel times of the fast pointer around the cycle When the first encounter of the slow pointer and the fast pointer
ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    
    ListNode *slow  = head;
    ListNode *fast  = head;
    ListNode *entry = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {                      // there is a cycle
            while(slow != entry) {               // found the entry location
                slow  = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;                                 // there has no cycle
}
