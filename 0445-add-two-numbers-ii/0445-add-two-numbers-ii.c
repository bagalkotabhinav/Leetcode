/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     long long int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode NODE;
typedef struct ListNode* NODEPTR;
NODEPTR getnode(long long int n){
    NODEPTR temp=(NODEPTR)malloc(sizeof(NODE));
    temp->val=n;
    temp->next=NULL;
    return temp;
}
NODEPTR reverse(NODEPTR first) {
    if (first == NULL || first->next == NULL) {
        return first;
    }

    NODEPTR rest = reverse(first->next);
    first->next->next = first;
    first->next = NULL;

    return rest;
}

NODEPTR addl(NODEPTR first,int k){
    NODEPTR it=first;
    NODEPTR temp=getnode(k);
    if(it==NULL)
        return temp;
    while(it->next!=NULL){
        it=it->next;
    }
    it->next=temp;
    return first;
}
NODEPTR addTwoNumbers(NODEPTR l1, NODEPTR l2){
    NODEPTR t1=reverse(l1),t2=reverse(l2),t3,first=NULL,new=NULL;
    int c=0;
    while(t1!=NULL || t2!=NULL){
        if(t1!=NULL){
            c=c+t1->val;
            t1=t1->next;
        }
        if(t2!=NULL){
            c=c+t2->val;
            t2=t2->next;
        }
        first=addl(first,c%10);
        c=c/10;
    }
    if(c>0){
        first=addl(first,c);
    }
    new=reverse(first);
    return new;
}
//     NODEPTR first=NULL,temp;
//     long long int n1=0,n2=0,i=0;
//     while(l1){
//         n1=n1+((l1->val)*(pow(10,i)));
//         i++;
//         l1=l1->next;
//     }
//     i=0;
//     while(l2){
//         n2=n2+((l2->val)*(pow(10,i)));
//         i++;
//         l2=l2->next;
//     }
//     long long int n3=n1+n2;
//     if(n3==0){
//         temp=getnode(n3);
//         first=addl(first,temp);
//     }
//     while(n3){
//         long long int k=n3%10;
//         temp=getnode(k);
//         first=addl(first,temp);
//         n3=n3/10;
//     }
//     return first;
// }