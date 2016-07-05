/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
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
	//��һ����һ�������ͷ�ڵ� 
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode tmpNode(0);
        ListNode* dummy=&tmpNode;//��ʱ�ڵ� 
        dummy->next=head;
        
        ListNode *tmp=head->next;
        while(tmp){
            head->next=tmp->next;
            tmp->next=dummy->next;
            dummy->next=tmp;
            tmp=head->next;
        }
        return dummy->next;
    }
    //����������ʱͷ���
	ListNode* reverseList2(ListNode* head) {
    
        if(head==nullptr||head->next==nullptr) return head;
        
        ListNode* pre=head,*cur=head->next;
        while(cur){
            pre->next=cur->next;
            cur->next=head;
            head=cur;
            cur=pre->next;
        }
        return head;
    } 
    //�����ݹ�
	ListNode* reverseList3(ListNode* head) {
    
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* toBeTailNode=head->next;
        ListNode* newHeadNode=reverseList(head->next);
        toBeTailNode->next=head;
        head->next=nullptr;
        return newHeadNode;
    }  
    
    
};
