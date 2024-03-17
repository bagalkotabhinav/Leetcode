/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode NODE;
typedef struct ListNode* NODEPTR;

NODEPTR reverse(NODEPTR first){
    if(first==NULL || first->next==NULL){
        return first;
    }
    NODEPTR rest=reverse(first->next);
    first->next->next=first;
    first->next=NULL;
    return rest;
}

int pairSum(NODEPTR head){
    int count=-1;
    NODEPTR temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    NODEPTR prev=NULL,cur=head;
    int set=-1;
    while(set!=((count-1)/2)){
        set++;
        prev=cur;
        cur=cur->next;
    }
    int max=0;
    NODEPTR revcur=reverse(cur);
    while(revcur!=NULL){
        if((head->val+revcur->val)>max){
            max=head->val+revcur->val;
        }
        head=head->next;
        revcur=revcur->next;
    }
    return max;
}
//next half start: count+1/2
//prev half end: count-1/2 
