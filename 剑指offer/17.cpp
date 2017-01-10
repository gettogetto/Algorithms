//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
struct compare{
    bool operator()(ListNode* l1,ListNode* l2){
        return l1->val>l2->val;//min heap
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(auto it:lists){
            if(it) pq.push(it);
        }
        if(pq.empty()) return NULL;
        ListNode* result = pq.top();
        pq.pop();
        if(result->next) pq.push(result->next);
        ListNode* tail = result;  
        while(!pq.empty()){
            tail->next=pq.top();
            pq.pop();
            tail=tail->next;
            if(tail->next) pq.push(tail->next);
        }
        return result;
        
    }
};
