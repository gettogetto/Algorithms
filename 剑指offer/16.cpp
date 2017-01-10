class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy= ListNode(0);
        dummy.next=head;
        ListNode* pre=&dummy,*cur=head;
        while(cur&&cur->next){
            ListNode* tmp=cur->next;
            cur->next=cur->next->next;
            tmp->next=pre->next;
            pre->next=tmp;
        }
        return dummy.next;
    }
};
//��ת�������������ע�����ַ��������� 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        while(head){
            ListNode* tmp=head->next;
            head->next=pre;
            pre=head;
            head=tmp;
        }
        return pre;
    }
};

//��ת����ݹ鷨 
class Solution {
public:   
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) return head;
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node; 
    }
}; 

//��ת��m����n���ڵ� m,n>=1
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* pre=&dummy;
        for(int i=0;i<m-1;i++){
            pre=pre->next;
        }

        ListNode* cur=pre->next;
        for(int i=m;i<n;i++){
            ListNode* tmp=cur->next;
            cur->next=tmp->next;
            tmp->next=pre->next;
            pre->next=tmp;
        }
        return dummy.next;
    }
};
