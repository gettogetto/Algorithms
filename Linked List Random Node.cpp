
/*
 Linked List Random Node  QuestionEditorial Solution  My Submissions
Total Accepted: 460
Total Submissions: 959
Difficulty: Medium
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
Subscribe to see which companies asked this question
*/
class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    vector<int>nums;
    Solution(ListNode* head) {
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
 
 class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */

    ListNode* mhead;
    int mlen;
    Solution(ListNode* head) {
        mhead=head;
        mlen=1;
        ListNode* tmp=head;
        while(tmp->next){
            mlen++;
            tmp=tmp->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n=rand()%mlen;
        ListNode* tmp=mhead;
        while(n){
            tmp=tmp->next;
            n--;
        }
        return tmp->val;
    }
};

