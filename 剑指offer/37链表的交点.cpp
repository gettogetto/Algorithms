/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL||pHead2==NULL) return NULL;
        int len1=1,len2=1;
        ListNode* cur1=pHead1,*cur2=pHead2;
        while(cur1->next){
            len1++;
            cur1=cur1->next;
        }
        while(cur2->next){
            len2++;
            cur2=cur2->next;
        }
        cur1=pHead1;cur2=pHead2;
        if(len1>len2){
			int l=len1-len2;
            while(l--){
                cur1=cur1->next;
            }
        }else if(len1<len2){
         	int l=len2-len1;
            while(l--){
                cur2=cur2->next;
            }   
        }
        
        while(cur1&&cur2&&cur1!=cur2){
			cur1=cur1->next;
            cur2=cur2->next;
        }
        if(cur1&&cur2&&cur1==cur2) return cur1;
        return NULL;
    }
};
