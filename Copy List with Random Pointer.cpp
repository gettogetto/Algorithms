/*A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==nullptr) return nullptr;
        vector<RandomListNode*>v;
        unordered_map<RandomListNode*,int>um;
        RandomListNode* cur=head;
        int index=0;
        while(cur){
            v.push_back(new RandomListNode(cur->label));
            um[cur]=index++;
            cur=cur->next;
        }
        cur=head;
        for(int i=0;i<v.size()-1;i++){
            v[i]->next=v[i+1];
            v[i]->random=(cur->random==nullptr?nullptr:v[um[cur->random]]);
            cur=cur->next;
        }
        //v[v.size()-1]->next=nullptr;
        v[v.size()-1]->random=(cur->random==nullptr?nullptr:v[um[cur->random]]);
        
        return v[0];
    }
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
	    RandomListNode *newHead, *l1, *l2;
	    if (head == NULL) return NULL;
	    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
	        l2 = new RandomListNode(l1->label);
	        l2->next = l1->next;
	        l1->next = l2;
	    }
	
	    newHead = head->next;
	    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
	        if (l1->random != NULL) l1->next->random = l1->random->next;
	    }
	
	    for (l1 = head; l1 != NULL; l1 = l1->next) {
	        l2 = l1->next;
	        l1->next = l2->next;
	        if (l2->next != NULL) l2->next = l2->next->next;
	    }
	
	    return newHead;
	}
    
};

