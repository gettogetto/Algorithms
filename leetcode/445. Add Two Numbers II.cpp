/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/
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
	//法一 反转链表法 
    /*ListNode* reverseList(ListNode* l){
        if(l==nullptr) return nullptr;
        ListNode dummy(-1);
        dummy.next=l;
        ListNode* oldhead=l;
        while(oldhead->next){
            ListNode* next=oldhead->next;
            oldhead->next=next->next;
            next->next=dummy.next;
            dummy.next=next;
        }
        return dummy.next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=reverseList(l1);
        ListNode *l4=reverseList(l2);
        ListNode* tmp1=l3,*tmp2=l4;
        vector<int> res;
        int carry=0;
        while(tmp1&&tmp2){
            int sum=tmp1->val+tmp2->val+carry;
            res.push_back(sum%10);
            carry=sum/10;
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        while(tmp1){
            int sum=tmp1->val+carry;
            res.push_back(sum%10);
            carry=sum/10;
            tmp1=tmp1->next;
     
        }
        while(tmp2){
            int sum=tmp2->val+carry;
            res.push_back(sum%10);
            carry=sum/10;
            tmp2=tmp2->next;
     
        }
        if(carry) res.push_back(carry);
        reverse(res.begin(),res.end());
        
        ListNode dummy(0);
        ListNode* node=new ListNode(res.front());
        dummy.next=node;
        for(int i=1;i<res.size();i++){
            node->next=new ListNode(res[i]);
            node=node->next;
        }
        return dummy.next;
    }*/
    //法二，数组法 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	    vector<int> nums1, nums2;
	    while(l1) {
	        nums1.push_back(l1->val);
	        l1 = l1->next;
	    }
	    while(l2) {
	        nums2.push_back(l2->val);
	        l2 = l2->next;
	    }
	
	    int m = nums1.size(), n = nums2.size();
	    int sum = 0, carry = 0;
	
	    ListNode *head = nullptr, *p = nullptr;
	
	    for(int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
	        sum = carry;
	        if(i >= 0) 
	            sum += nums1[i];
	
	        if(j >= 0)
	            sum += nums2[j];
	
	        carry = sum / 10;
	
	        p = new ListNode(sum%10);
	        p->next = head;
	        head = p;
	    }
	
	    return head;
	}

};
