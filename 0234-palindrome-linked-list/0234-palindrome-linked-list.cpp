/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode*reverse(ListNode*head)
{
     ListNode* cur=head,*nxt=nullptr,*prev=nullptr;
        while(cur)
        {
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
}
    bool isPalindrome(ListNode* head) {
       ListNode*p1=head,*p2=head;
        while(p2)
        {
            p2=p2->next;
            if(p2)
            {
                p1=p1->next;
                p2=p2->next;
            }
        }
        if(p1->next)
        cout<<p1->next->val<<endl;
        ListNode*prev=NULL,*nxt=NULL;
        while(p1!=NULL)
        {
            nxt=p1->next;
            p1->next=prev;
            prev=p1;
            p1=nxt;
        }
        ListNode*p=head;
     cout<<prev->val<<endl;
        while(p!=prev&&prev&&p)
        {
          
           if(p->val!=prev->val)
           return false;
           p=p->next;
            prev=prev->next;
        }
        return true;
    }
};